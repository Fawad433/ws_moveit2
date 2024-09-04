cmake_minimum_required(VERSION 3.8)
project(myrobot_ompl_constrained_planning)

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(moveit_ros_planning_interface REQUIRED)
find_package(moveit_visual_tools REQUIRED)
find_package(rviz_visual_tools REQUIRED)
find_package(std_msgs REQUIRED)
find_package(moveit_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(shape_msgs REQUIRED)
find_package(tf2_ros REQUIRED)

# Include directories
include_directories(include)

# Executable
add_executable(ompl_constrained_planning src/ompl_constrained_planning_tutorial.cpp)

# Target dependencies
ament_target_dependencies(ompl_constrained_planning
  rclcpp
  moveit_ros_planning_interface
  moveit_visual_tools
  rviz_visual_tools
  std_msgs
  moveit_msgs
  geometry_msgs
  shape_msgs
  tf2_ros
)

install(TARGETS ompl_constrained_planning
  DESTINATION lib/${PROJECT_NAME})


install(DIRECTORY launch/
DESTINATION share/${PROJECT_NAME}/launch
)

ament_package()
