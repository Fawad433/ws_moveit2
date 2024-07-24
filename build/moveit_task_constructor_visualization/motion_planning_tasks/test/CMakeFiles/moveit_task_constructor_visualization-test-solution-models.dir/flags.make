# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

# compile CXX with /usr/bin/c++
CXX_DEFINES = -DBACKWARD_HAS_DW=1 -DBOOST_ALL_NO_LIB -DBOOST_ATOMIC_DYN_LINK -DBOOST_CHRONO_DYN_LINK -DBOOST_DATE_TIME_DYN_LINK -DBOOST_FILESYSTEM_DYN_LINK -DBOOST_IOSTREAMS_DYN_LINK -DBOOST_MATH_DISABLE_FLOAT128 -DBOOST_PROGRAM_OPTIONS_DYN_LINK -DBOOST_REGEX_DYN_LINK -DBOOST_SERIALIZATION_DYN_LINK -DBOOST_SYSTEM_DYN_LINK -DBOOST_THREAD_DYN_LINK -DDEFAULT_RMW_IMPLEMENTATION=rmw_fastrtps_cpp -DFMT_LOCALE -DFMT_SHARED -DQT_CORE_LIB -DQT_GUI_LIB -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DRCUTILS_ENABLE_FAULT_INJECTION

CXX_INCLUDES = -I/home/robot/ws_moveit2/build/moveit_task_constructor_visualization/motion_planning_tasks/test -I/home/robot/ws_moveit2/src/moveit_task_constructor/visualization/motion_planning_tasks/test -I/home/robot/ws_moveit2/build/moveit_task_constructor_visualization/motion_planning_tasks/test/moveit_task_constructor_visualization-test-solution-models_autogen/include -I/home/robot/ws_moveit2/src/moveit_task_constructor/visualization/motion_planning_tasks/src/.. -I/home/robot/ws_moveit2/src/moveit_task_constructor/visualization/motion_planning_tasks/utils/.. -I/home/robot/ws_moveit2/src/moveit_task_constructor/visualization/motion_planning_tasks/properties/.. -I/home/robot/ws_moveit2/src/moveit_task_constructor/visualization/visualization_tools/include -isystem /opt/ros/humble/src/gmock_vendor/include -isystem /opt/ros/humble/src/gtest_vendor/include -isystem /usr/include/x86_64-linux-gnu/qt5 -isystem /usr/include/x86_64-linux-gnu/qt5/QtWidgets -isystem /usr/include/x86_64-linux-gnu/qt5/QtGui -isystem /usr/include/x86_64-linux-gnu/qt5/QtCore -isystem /usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -isystem /opt/ros/humble/include/libyaml_vendor -isystem /home/robot/ws_moveit2/install/moveit_task_constructor_core/include -isystem /usr/include/bullet -isystem /home/robot/ws_moveit2/install/moveit_core/include -isystem /opt/ros/humble/include/rclcpp -isystem /opt/ros/humble/include/ament_index_cpp -isystem /opt/ros/humble/include/libstatistics_collector -isystem /opt/ros/humble/include/builtin_interfaces -isystem /opt/ros/humble/include/rosidl_runtime_c -isystem /opt/ros/humble/include/rcutils -isystem /opt/ros/humble/include/rosidl_typesupport_interface -isystem /opt/ros/humble/include/fastcdr -isystem /opt/ros/humble/include/rosidl_runtime_cpp -isystem /opt/ros/humble/include/rosidl_typesupport_fastrtps_cpp -isystem /opt/ros/humble/include/rmw -isystem /opt/ros/humble/include/rosidl_typesupport_fastrtps_c -isystem /opt/ros/humble/include/rosidl_typesupport_introspection_c -isystem /opt/ros/humble/include/rosidl_typesupport_introspection_cpp -isystem /opt/ros/humble/include/rcl -isystem /opt/ros/humble/include/rcl_interfaces -isystem /opt/ros/humble/include/rcl_logging_interface -isystem /opt/ros/humble/include/rcl_yaml_param_parser -isystem /opt/ros/humble/include/tracetools -isystem /opt/ros/humble/include/rcpputils -isystem /opt/ros/humble/include/statistics_msgs -isystem /opt/ros/humble/include/rosgraph_msgs -isystem /opt/ros/humble/include/rosidl_typesupport_cpp -isystem /opt/ros/humble/include/rosidl_typesupport_c -isystem /opt/ros/humble/include/urdf -isystem /opt/ros/humble/include/urdf_parser_plugin -isystem /opt/ros/humble/include/urdfdom_headers -isystem /opt/ros/humble/include/urdfdom -isystem /opt/ros/humble/include/pluginlib -isystem /opt/ros/humble/include/class_loader -isystem /opt/ros/humble/include/visualization_msgs -isystem /opt/ros/humble/include/geometry_msgs -isystem /opt/ros/humble/include/std_msgs -isystem /opt/ros/humble/include/sensor_msgs -isystem /opt/ros/humble/include/octomap_msgs -isystem /opt/ros/humble/include -isystem /opt/ros/humble/include/tf2_eigen -isystem /opt/ros/humble/include/tf2 -isystem /opt/ros/humble/include/tf2_ros -isystem /opt/ros/humble/include/message_filters -isystem /opt/ros/humble/include/rclcpp_action -isystem /opt/ros/humble/include/action_msgs -isystem /opt/ros/humble/include/unique_identifier_msgs -isystem /opt/ros/humble/include/rcl_action -isystem /opt/ros/humble/include/tf2_msgs -isystem /usr/include/eigen3 -isystem /usr/include/libqhull_r -isystem /opt/ros/humble/include/resource_retriever -isystem /opt/ros/humble/include/shape_msgs -isystem /opt/ros/humble/include/tf2_geometry_msgs -isystem /opt/ros/humble/include/angles -isystem /opt/ros/humble/include/moveit_msgs -isystem /opt/ros/humble/include/object_recognition_msgs -isystem /opt/ros/humble/include/trajectory_msgs -isystem /home/robot/ws_moveit2/install/srdfdom/include -isystem /home/robot/ws_moveit2/install/moveit_core/include/moveit_butterworth_parameters -isystem /opt/ros/humble/include/parameter_traits -isystem /opt/ros/humble/include/rsl -isystem /opt/ros/humble/include/rclcpp_lifecycle -isystem /opt/ros/humble/include/rcl_lifecycle -isystem /opt/ros/humble/include/lifecycle_msgs -isystem /opt/ros/humble/include/kdl_parser -isystem /home/robot/ws_moveit2/install/moveit_ros_planning/include -isystem /home/robot/ws_moveit2/install/moveit_ros_occupancy_map_monitor/include -isystem /home/robot/ws_moveit2/install/moveit_ros_planning_interface/include -isystem /home/robot/ws_moveit2/install/moveit_ros_move_group/include -isystem /opt/ros/humble/include/std_srvs -isystem /home/robot/ws_moveit2/install/moveit_ros_warehouse/include -isystem /home/robot/ws_moveit2/install/moveit_task_constructor_msgs/include/moveit_task_constructor_msgs -isystem /home/robot/ws_moveit2/install/rviz_marker_tools/include -isystem /opt/ros/humble/include/rviz_common -isystem /opt/ros/humble/opt/rviz_ogre_vendor/include/OGRE -isystem /opt/ros/humble/include/rviz_rendering -isystem /home/robot/ws_moveit2/install/moveit_ros_visualization/include -isystem /opt/ros/humble/include/rviz_default_plugins -isystem /opt/ros/humble/include/image_transport -isystem /opt/ros/humble/include/interactive_markers -isystem /opt/ros/humble/include/laser_geometry -isystem /opt/ros/humble/include/map_msgs -isystem /opt/ros/humble/include/nav_msgs -isystem /home/robot/ws_moveit2/install/moveit_ros_robot_interaction/include

CXX_FLAGS = --param ggc-min-expand=20 -O3 -DNDEBUG -std=c++17 -Wall -Wextra -Wwrite-strings -Wunreachable-code -Wpointer-arith -Wredundant-decls -Wcast-qual -Wno-maybe-uninitialized -fPIC

