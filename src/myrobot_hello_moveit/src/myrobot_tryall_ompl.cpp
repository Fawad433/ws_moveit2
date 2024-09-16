#include <memory>
#include <moveit_visual_tools/moveit_visual_tools.h>
#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.h>
#include <vector>
#include <string>

int main(int argc, char *argv[]) {
  // Initialize ROS and create the Node
  rclcpp::init(argc, argv);
  auto const node = std::make_shared<rclcpp::Node>(
      "myrobot_hello_moveit",
      rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true));

  // Create a ROS logger
  auto const logger = rclcpp::get_logger("myrobot_hello_moveit");

  // Spin up a SingleThreadedExecutor so MoveItVisualTools interact with ROS
  rclcpp::executors::SingleThreadedExecutor executor;
  executor.add_node(node);
  auto spinner = std::thread([&executor]() { executor.spin(); });

  using moveit::planning_interface::MoveGroupInterface;
  auto move_group_interface = MoveGroupInterface(node, "myrobot_arm");

  // Construct and initialize MoveItVisualTools
  auto moveit_visual_tools = moveit_visual_tools::MoveItVisualTools{
      node, "arm_base_link", rviz_visual_tools::RVIZ_MARKER_TOPIC,
      move_group_interface.getRobotModel()};
  moveit_visual_tools.deleteAllMarkers();
  moveit_visual_tools.loadRemoteControl();

  // Create closures for visualization
  auto const draw_title = [&moveit_visual_tools](auto text) {
    auto const text_pose = [] {
      auto msg = Eigen::Isometry3d::Identity();
      msg.translation().z() = 1.0;
      return msg;
    }();
    moveit_visual_tools.publishText(text_pose, text, rviz_visual_tools::WHITE,
                                    rviz_visual_tools::XLARGE);
  };
  auto const prompt = [&moveit_visual_tools](auto text) {
    moveit_visual_tools.prompt(text);
  };
  auto const draw_trajectory_tool_path =
      [&moveit_visual_tools,
       jmg = move_group_interface.getRobotModel()->getJointModelGroup("myrobot_arm")](auto const trajectory) {
        moveit_visual_tools.publishTrajectoryLine(trajectory, jmg);
      };

  // Set a target position only (no orientation)
  auto const target_position = [] {
    geometry_msgs::msg::Pose msg;
    msg.position.x = -0.097172;
    msg.position.y = -0.193269;
    msg.position.z = 0.286618;
    msg.orientation.w = 1.0; // Neutral orientation
    return msg;
  }();
  move_group_interface.setPoseTarget(target_position);

  // List of planners to try
  std::vector<std::string> planners = {
      "SBLkConfigDefault"};

      /* "ESTkConfigDefault", "LBKPIECEkConfigDefault",
      "BKPIECEkConfigDefault", "KPIECEkConfigDefault", "RRTkConfigDefault",
      "RRTConnectkConfigDefault", "RRTstarkConfigDefault", "TRRTkConfigDefault",
      "PRMkConfigDefault", "PRMstarkConfigDefault", "FMTkConfigDefault",
      "BFMTkConfigDefault", "PDSTkConfigDefault", "STRIDEkConfigDefault",
      "BiTRRTkConfigDefault", "LBTRRTkConfigDefault", "BiESTkConfigDefault",
      "ProjESTkConfigDefault", "LazyPRMkConfigDefault", "LazyPRMstarkConfigDefault",
      "SPARSkConfigDefault", "SPARStwokConfigDefault", "TrajOptDefault"
      */

     
  for (const auto &planner : planners) {
    RCLCPP_INFO(logger, "Trying planner: %s", planner.c_str());
    move_group_interface.setPlannerId(planner);

    // Plan to the target position
    prompt("Press 'Next' in the RvizVisualToolsGui window to plan with " + planner);
    draw_title("Planning with " + planner);
    moveit_visual_tools.trigger();
    auto const [success, plan] = [&move_group_interface] {
      moveit::planning_interface::MoveGroupInterface::Plan msg;
      auto const ok = static_cast<bool>(move_group_interface.plan(msg));
      return std::make_pair(ok, msg);
    }();

    if (success) {
      draw_trajectory_tool_path(plan.trajectory_);
      moveit_visual_tools.trigger();
      prompt("Press 'Next' in the RvizVisualToolsGui window to execute");
      draw_title("Executing with " + planner);
      moveit_visual_tools.trigger();
      move_group_interface.execute(plan);
      break; // Exit loop on first successful plan
    } else {
      draw_title("Planning Failed with " + planner + "!");
      moveit_visual_tools.trigger();
      RCLCPP_ERROR(logger, "Planning failed with %s!", planner.c_str());
    }
  }

  // Shutdown ROS
  rclcpp::shutdown();  // <--- This will cause the spin function in the thread to return
  spinner.join();      // <--- Join the thread before exiting
  return 0;
}
