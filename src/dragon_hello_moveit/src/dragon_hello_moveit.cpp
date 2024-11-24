#include <memory>
#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.h>
#include <geometry_msgs/msg/pose.hpp>

int main(int argc, char* argv[])
{
  // Initialize ROS and create the Node
  rclcpp::init(argc, argv);
  auto const node = std::make_shared<rclcpp::Node>(
    "dragon_hello_moveit_random",
    rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true)
  );

  // Create a ROS logger
  auto const logger = rclcpp::get_logger("dragon_hello_moveit");

  // Create the MoveIt MoveGroup Interface for the "dragon_arm" group
  using moveit::planning_interface::MoveGroupInterface;
  auto move_group_interface = MoveGroupInterface(node, "dragon_arm");

  // Generate a random valid target pose
  move_group_interface.setRandomTarget();

  // Log the randomly generated target pose for reference
  auto const random_target_pose = move_group_interface.getCurrentPose().pose;
  RCLCPP_INFO(logger, "Randomly generated target pose:");
  RCLCPP_INFO(logger, "Position - x: %f, y: %f, z: %f", 
              random_target_pose.position.x, 
              random_target_pose.position.y, 
              random_target_pose.position.z);
  RCLCPP_INFO(logger, "Orientation - x: %f, y: %f, z: %f, w: %f", 
              random_target_pose.orientation.x, 
              random_target_pose.orientation.y, 
              random_target_pose.orientation.z, 
              random_target_pose.orientation.w);

  // Create a plan to the random target pose
  auto const [success, plan] = [&move_group_interface] {
    moveit::planning_interface::MoveGroupInterface::Plan msg;
    auto const ok = static_cast<bool>(move_group_interface.plan(msg));
    return std::make_pair(ok, msg);
  }();

  // Execute the plan if planning was successful
  if (success) {
    move_group_interface.execute(plan);
  } else {
    RCLCPP_ERROR(logger, "Planning failed!");
  }

  // Shutdown ROS
  rclcpp::shutdown();
  return 0;
}
