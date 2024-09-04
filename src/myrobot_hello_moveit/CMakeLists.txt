cmake_minimum_required(VERSION 3.8)
project(myrobot_hello_moveit)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(moveit_ros_planning_interface REQUIRED)
find_package(rclcpp REQUIRED)


find_package(moveit_core REQUIRED)
find_package(moveit_ros_planning REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(moveit_visual_tools REQUIRED)


add_executable(myrobot_planning_around_objects src/myrobot_planningaroundobjects.cpp)
add_executable(myrobot_hello_moveit src/myrobot_hello_moveit.cpp)
add_executable(myrobot_tryall_ompl src/myrobot_tryall_ompl.cpp)
add_executable(get_eef_pose src/myrobot_get_pose.cpp)


target_include_directories(myrobot_hello_moveit PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

target_compile_features(myrobot_hello_moveit PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17

ament_target_dependencies(
  get_eef_pose
  "geometry_msgs"
  "moveit_ros_planning_interface"
  "rclcpp"
)

ament_target_dependencies(
  myrobot_hello_moveit
  "moveit_ros_planning_interface"
  "rclcpp"
  "moveit_core"
  "moveit_ros_planning"
  "geometry_msgs"
  "moveit_visual_tools"
)

ament_target_dependencies(
  myrobot_planning_around_objects
  "moveit_ros_planning_interface"
  "rclcpp"
  "moveit_core"
  "moveit_ros_planning"
  "geometry_msgs"
  "moveit_visual_tools"
)

ament_target_dependencies(myrobot_tryall_ompl
  rclcpp
  geometry_msgs
  moveit_core
  moveit_ros_planning_interface
  moveit_visual_tools
  rviz_visual_tools
  Eigen3
)

install(TARGETS 
  myrobot_hello_moveit
  myrobot_tryall_ompl 
  get_eef_pose
  myrobot_planning_around_objects
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}/launch
)



ament_package()
