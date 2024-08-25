#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <geometry_msgs/msg/pose_stamped.hpp>

class SimplePickAndPlace : public rclcpp::Node
{
public:
  SimplePickAndPlace()
    : Node("simple_pick_and_place"),
      arm_group_(std::make_shared<rclcpp::Node>("simple_pick_and_place"), "myrobot_arm"),
      gripper_group_(std::make_shared<rclcpp::Node>("simple_pick_and_place"), "myrobot_hand"),
      planning_scene_interface_()
  {
    // Increase the planning time
    arm_group_.setPlanningTime(60.0);  // Increased planning time to 60 seconds

    // Set a target Pose
    target_pose.header.frame_id = "arm_base_link";
    target_pose.pose.position.x = -0.000644;
    target_pose.pose.position.y = 0.171450;
    target_pose.pose.position.z = 0.154200;
    target_pose.pose.orientation.w = 1.000000;

    // Set the pick and place poses
    pick_pose_.header.frame_id = "arm_base_link";
    pick_pose_.pose.position.x = -0.000644;
    pick_pose_.pose.position.y = 0.27145;
    pick_pose_.pose.position.z = 0.154200;
    pick_pose_.pose.orientation.w = 1.0;

    place_pose_.header.frame_id = "arm_base_link";
    place_pose_.pose.position.x = 0.3;
    place_pose_.pose.position.y = -0.2;
    place_pose_.pose.position.z = 0.0;
    place_pose_.pose.orientation.w = 1.0;

    // Define approach and retreat poses
    pick_approach_pose_ = pick_pose_;
    pick_approach_pose_.pose.position.z += 0.05; // Adjust the approach distance to 5cm above pick pose

    pick_retreat_pose_ = pick_pose_;
    pick_retreat_pose_.pose.position.z += 0.05; // Adjust the retreat distance to 5cm above pick pose

    place_approach_pose_ = place_pose_;
    place_approach_pose_.pose.position.z += 0.05; // Adjust the approach distance to 5cm above place pose

    place_retreat_pose_ = place_pose_;
    place_retreat_pose_.pose.position.z += 0.05; // Adjust the retreat distance to 5cm above place pose

    // Add the object to the planning scene
    addObject();

    // Execute pick and place sequence
    executePickAndPlace();
  }

private:
  void addObject()
  {
    moveit_msgs::msg::CollisionObject collision_object;
    collision_object.header.frame_id = arm_group_.getPlanningFrame();

    collision_object.id = "object";
    shape_msgs::msg::SolidPrimitive primitive;
    primitive.type = primitive.BOX;
    primitive.dimensions = {0.01, 0.01, 0.1};

    geometry_msgs::msg::Pose box_pose = pick_pose_.pose;

    collision_object.primitives.push_back(primitive);
    collision_object.primitive_poses.push_back(box_pose);
    collision_object.operation = collision_object.ADD;

    planning_scene_interface_.applyCollisionObject(collision_object);
    RCLCPP_INFO(this->get_logger(), "Object added to the scene.");
  }

  bool isPoseReachable(const geometry_msgs::msg::Pose& pose)
  {
    arm_group_.setPoseTarget(pose);
    moveit::planning_interface::MoveGroupInterface::Plan my_plan;
    bool success = (arm_group_.plan(my_plan) == moveit::core::MoveItErrorCode::SUCCESS);
    arm_group_.clearPoseTargets();  // Clear targets after checking
    return success;
  }

  void executePickAndPlace()
  {
    // Open the gripper
    RCLCPP_INFO(this->get_logger(), "Opening the gripper...");
    gripper_group_.setNamedTarget("open");
    gripper_group_.move();

    // Move to ready
    RCLCPP_INFO(this->get_logger(), "Moving to ready pose...");
    arm_group_.setNamedTarget("ready");
    arm_group_.move();

    // Move to pick approach pose
    RCLCPP_INFO(this->get_logger(), "Moving to pick approach pose...");
    arm_group_.setPlannerId("TRRTkConfigDefault");
    arm_group_.setPoseTarget(target_pose.pose);
    if (arm_group_.move() != moveit::core::MoveItErrorCode::SUCCESS)
    {
      RCLCPP_ERROR(this->get_logger(), "Failed to move to pick approach pose.");
      return;
    }

    // Move to pick pose
    RCLCPP_INFO(this->get_logger(), "Moving to pick pose...");
    arm_group_.setPoseTarget(pick_pose_.pose);
    if (arm_group_.move() != moveit::core::MoveItErrorCode::SUCCESS)
    {
      RCLCPP_ERROR(this->get_logger(), "Failed to move to pick pose.");
      return;
    }

    // Close the gripper to grasp the object
    RCLCPP_INFO(this->get_logger(), "Closing the gripper...");
    gripper_group_.setNamedTarget("close");
    gripper_group_.move();

    // Attach the object to the robot
    planning_scene_interface_.applyAttachedCollisionObject(createAttachedObject());
    RCLCPP_INFO(this->get_logger(), "Object attached to the gripper.");

    // Move to pick retreat pose
    RCLCPP_INFO(this->get_logger(), "Moving to pick retreat pose...");
    arm_group_.setPoseTarget(pick_retreat_pose_.pose);
    if (arm_group_.move() != moveit::core::MoveItErrorCode::SUCCESS)
    {
      RCLCPP_ERROR(this->get_logger(), "Failed to move to pick retreat pose.");
      return;
    }

    // Move to place approach pose
    RCLCPP_INFO(this->get_logger(), "Moving to place approach pose...");
    arm_group_.setPoseTarget(place_approach_pose_.pose);
    if (arm_group_.move() != moveit::core::MoveItErrorCode::SUCCESS)
    {
      RCLCPP_ERROR(this->get_logger(), "Failed to move to place approach pose.");
      return;
    }

    // Move to place pose
    RCLCPP_INFO(this->get_logger(), "Moving to place pose...");
    arm_group_.setPoseTarget(place_pose_.pose);
    if (arm_group_.move() != moveit::core::MoveItErrorCode::SUCCESS)
    {
      RCLCPP_ERROR(this->get_logger(), "Failed to move to place pose.");
      return;
    }

    // Open the gripper to release the object
    RCLCPP_INFO(this->get_logger(), "Opening the gripper...");
    gripper_group_.setNamedTarget("open");
    gripper_group_.move();

    // Detach the object from the robot's end effector
    RCLCPP_INFO(this->get_logger(), "Detaching the object...");
    arm_group_.detachObject("object");

    // Remove the object from the scene
    planning_scene_interface_.removeCollisionObjects({"object"});
    RCLCPP_INFO(this->get_logger(), "Object removed from the scene.");

    // Move to place retreat pose
    RCLCPP_INFO(this->get_logger(), "Moving to place retreat pose...");
    arm_group_.setPoseTarget(place_retreat_pose_.pose);
    if (arm_group_.move() != moveit::core::MoveItErrorCode::SUCCESS)
    {
      RCLCPP_ERROR(this->get_logger(), "Failed to move to place retreat pose.");
      return;
    }

    RCLCPP_INFO(this->get_logger(), "Pick and place task completed.");
  }

  moveit_msgs::msg::AttachedCollisionObject createAttachedObject()
  {
    moveit_msgs::msg::AttachedCollisionObject attached_object;
    attached_object.link_name = arm_group_.getEndEffectorLink();
    attached_object.object.header.frame_id = arm_group_.getPlanningFrame();
    attached_object.object.id = "object";

    shape_msgs::msg::SolidPrimitive primitive;
    primitive.type = primitive.BOX;
    primitive.dimensions = {0.01, 0.01, 0.1};

    geometry_msgs::msg::Pose box_pose = pick_pose_.pose;

    attached_object.object.primitives.push_back(primitive);
    attached_object.object.primitive_poses.push_back(box_pose);
    attached_object.object.operation = attached_object.object.ADD;

    return attached_object;
  }

  moveit::planning_interface::MoveGroupInterface arm_group_;
  moveit::planning_interface::MoveGroupInterface gripper_group_;
  moveit::planning_interface::PlanningSceneInterface planning_scene_interface_;
  geometry_msgs::msg::PoseStamped pick_pose_;
  geometry_msgs::msg::PoseStamped place_pose_;
  geometry_msgs::msg::PoseStamped target_pose;
  geometry_msgs::msg::PoseStamped pick_approach_pose_;
  geometry_msgs::msg::PoseStamped pick_retreat_pose_;
  geometry_msgs::msg::PoseStamped place_approach_pose_;
  geometry_msgs::msg::PoseStamped place_retreat_pose_;
};

int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<SimplePickAndPlace>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
