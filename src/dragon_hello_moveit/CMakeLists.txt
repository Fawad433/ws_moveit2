cmake_minimum_required(VERSION 3.8)
project(dragon_hello_moveit)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(moveit_ros_planning_interface REQUIRED)
find_package(rclcpp REQUIRED)

add_executable(dragon_hello_moveit src/dragon_hello_moveit.cpp)
add_executable(dragon_get_pose src/dragon_get_pose.cpp)

target_include_directories(dragon_hello_moveit PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(dragon_hello_moveit PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17

ament_target_dependencies(
  dragon_get_pose
  "geometry_msgs"
  "moveit_ros_planning_interface"
  "rclcpp"
)

ament_target_dependencies(
  dragon_hello_moveit
  "moveit_ros_planning_interface"
  "rclcpp"
)

install(TARGETS dragon_hello_moveit dragon_get_pose
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
