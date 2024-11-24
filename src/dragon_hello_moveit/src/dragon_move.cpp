#include <memory>
#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.h>
#include <geometry_msgs/msg/pose.hpp>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <cmath>  // For sin, cos, and M_PI constants

// Function to validate the target pose against the range
bool isPoseValid(const geometry_msgs::msg::Pose& pose) {
  // Position limits
  const double x_min = -0.253998, x_max = 0.254790;
  const double y_min = -0.255879, y_max = 0.255532;
  const double z_min = -0.007005, z_max = 0.401627;

  // Quaternion limits
  const double qx_min = -0.864419, qx_max = 0.999978;
  const double qy_min = -0.857191, qy_max = 0.999987;
  const double qz_min = -0.865146, qz_max = 0.999999;
  const double qw_min = -0.499998, qw_max = 0.999998;

  // Validate position
  if (pose.position.x < x_min || pose.position.x > x_max ||
      pose.position.y < y_min || pose.position.y > y_max ||
      pose.position.z < z_min || pose.position.z > z_max) {
    return false;
  }

  // Validate orientation (quaternion)
  if (pose.orientation.x < qx_min || pose.orientation.x > qx_max ||
      pose.orientation.y < qy_min || pose.orientation.y > qy_max ||
      pose.orientation.z < qz_min || pose.orientation.z > qz_max ||
      pose.orientation.w < qw_min || pose.orientation.w > qw_max) {
    return false;
  }

  // If all validations pass
  return true;
}

int main(int argc, char* argv[]) {
  // Initialize ROS and create the Node
  rclcpp::init(argc, argv);
  auto const node = std::make_shared<rclcpp::Node>(
    "dragon_move",
    rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true)
  );

  // Create a ROS logger
  auto const logger = rclcpp::get_logger("Lets get rolling");

  // Create the MoveIt MoveGroup Interface
  using moveit::planning_interface::MoveGroupInterface;
  auto move_group_interface = MoveGroupInterface(node, "dragon_arm");

  // Set a target Pose with corrected quaternion
  auto target_pose = [] {
    geometry_msgs::msg::Pose msg;

    // Set the initial pose
    msg.position.x = 0.210762;
    msg.position.y = 0.001249;
    msg.position.z = 0.129761;
    msg.orientation.x = 0.867672;
    msg.orientation.y = 0.002596;
    msg.orientation.z = 0.497128;
    msg.orientation.w = -0.001491;

    return msg;
  }();

  // Apply a 45-degree rotation to the initial quaternion
  const double angle = M_PI / 2.0;  // 90 degrees in radians
  tf2::Quaternion initial_quat(
    target_pose.orientation.x,
    target_pose.orientation.y,
    target_pose.orientation.z,
    target_pose.orientation.w
  );

  // Define the axis for local rotation (z-axis)
  tf2::Quaternion rotation_quat;
  rotation_quat.setRPY(0.0, 0.0, angle);  // Rotation around z-axis
  tf2::Quaternion corrected_quat = initial_quat * rotation_quat;
  corrected_quat.normalize();  // Normalize to ensure it's a valid quaternion

  // Update the target pose orientation
  target_pose.orientation.x = corrected_quat.x();
  target_pose.orientation.y = corrected_quat.y();
  target_pose.orientation.z = corrected_quat.z();
  target_pose.orientation.w = corrected_quat.w();

  // Validate the target pose
  if (!isPoseValid(target_pose)) {
    RCLCPP_ERROR(logger, "Target pose is out of range! Aborting planning.");
    rclcpp::shutdown();
    return 1;  // Exit with failure
  }

  // If valid, proceed with planning
  move_group_interface.setPoseTarget(target_pose);

  // Create a plan to that target pose
  auto const [success, plan] = [&move_group_interface] {
    moveit::planning_interface::MoveGroupInterface::Plan msg;
    auto const ok = static_cast<bool>(move_group_interface.plan(msg));
    return std::make_pair(ok, msg);
  }();

  // Execute the plan
  if (success) {
    move_group_interface.execute(plan);
  } else {
    RCLCPP_ERROR(logger, "Planning failed!");
  }

  // Shutdown ROS
  rclcpp::shutdown();
  return 0;
}
