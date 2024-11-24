#include <memory>
#include <limits>  // For numeric_limits
#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.h>
#include <geometry_msgs/msg/pose.hpp>
#include <thread>
#include <moveit/robot_state/robot_state.h>

int main(int argc, char* argv[]) {
  // Initialize ROS and create the Node
  rclcpp::init(argc, argv);
  auto const node = std::make_shared<rclcpp::Node>(
    "dragon_get_positions",
    rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true)
  );

  // Create a ROS logger
  auto const logger = rclcpp::get_logger("dragon_positions_range");

  // Create an executor and spinner thread
  rclcpp::executors::SingleThreadedExecutor executor;
  executor.add_node(node);
  std::thread spinner = std::thread([&executor]() { executor.spin(); });

  // Create the MoveIt MoveGroup Interface for the "dragon_arm" group
  using moveit::planning_interface::MoveGroupInterface;
  auto move_group_interface = MoveGroupInterface(node, "dragon_arm");

  // Get the joint model group and robot state
  auto joint_model_group = move_group_interface.getCurrentState()->getJointModelGroup("dragon_arm");
  auto robot_state = move_group_interface.getCurrentState();

  // Initialize min/max variables
  double x_min = std::numeric_limits<double>::max(), x_max = std::numeric_limits<double>::lowest();
  double y_min = std::numeric_limits<double>::max(), y_max = std::numeric_limits<double>::lowest();
  double z_min = std::numeric_limits<double>::max(), z_max = std::numeric_limits<double>::lowest();
  double qx_min = std::numeric_limits<double>::max(), qx_max = std::numeric_limits<double>::lowest();
  double qy_min = std::numeric_limits<double>::max(), qy_max = std::numeric_limits<double>::lowest();
  double qz_min = std::numeric_limits<double>::max(), qz_max = std::numeric_limits<double>::lowest();
  double qw_min = std::numeric_limits<double>::max(), qw_max = std::numeric_limits<double>::lowest();

  // Loop to sample random poses and calculate min/max
  for (int i = 0; i < 100000; ++i) {  // Adjust the number of samples as needed
    // Set random joint positions
    robot_state->setToRandomPositions(joint_model_group);
    
    // Calculate forward kinematics to get the end-effector pose
    const Eigen::Isometry3d& end_effector_state = robot_state->getGlobalLinkTransform("servo5_servo6_link");

    // Extract pose information
    geometry_msgs::msg::Pose random_pose;
    random_pose.position.x = end_effector_state.translation().x();
    random_pose.position.y = end_effector_state.translation().y();
    random_pose.position.z = end_effector_state.translation().z();
    Eigen::Quaterniond quat(end_effector_state.rotation());
    random_pose.orientation.x = quat.x();
    random_pose.orientation.y = quat.y();
    random_pose.orientation.z = quat.z();
    random_pose.orientation.w = quat.w();

    // Log the sampled pose
    RCLCPP_INFO(logger, "Sample #%d - Position: x=%f, y=%f, z=%f | Orientation: x=%f, y=%f, z=%f, w=%f",
                i, random_pose.position.x, random_pose.position.y, random_pose.position.z,
                random_pose.orientation.x, random_pose.orientation.y, random_pose.orientation.z, random_pose.orientation.w);

    // Update position limits
    x_min = std::min(x_min, random_pose.position.x);
    x_max = std::max(x_max, random_pose.position.x);
    y_min = std::min(y_min, random_pose.position.y);
    y_max = std::max(y_max, random_pose.position.y);
    z_min = std::min(z_min, random_pose.position.z);
    z_max = std::max(z_max, random_pose.position.z);

    // Update quaternion limits
    qx_min = std::min(qx_min, random_pose.orientation.x);
    qx_max = std::max(qx_max, random_pose.orientation.x);
    qy_min = std::min(qy_min, random_pose.orientation.y);
    qy_max = std::max(qy_max, random_pose.orientation.y);
    qz_min = std::min(qz_min, random_pose.orientation.z);
    qz_max = std::max(qz_max, random_pose.orientation.z);
    qw_min = std::min(qw_min, random_pose.orientation.w);
    qw_max = std::max(qw_max, random_pose.orientation.w);
  }

  // Log the results
  RCLCPP_INFO(logger, "Position Limits:");
  RCLCPP_INFO(logger, "x: [%f, %f]", x_min, x_max);
  RCLCPP_INFO(logger, "y: [%f, %f]", y_min, y_max);
  RCLCPP_INFO(logger, "z: [%f, %f]", z_min, z_max);

  RCLCPP_INFO(logger, "Quaternion Limits:");
  RCLCPP_INFO(logger, "qx: [%f, %f]", qx_min, qx_max);
  RCLCPP_INFO(logger, "qy: [%f, %f]", qy_min, qy_max);
  RCLCPP_INFO(logger, "qz: [%f, %f]", qz_min, qz_max);
  RCLCPP_INFO(logger, "qw: [%f, %f]", qw_min, qw_max);

  // Shutdown ROS and join spinner
  rclcpp::shutdown();
  spinner.join();
  return 0;
}
