# Install script for directory: /home/robot/ws_moveit2/src/moveit_task_constructor/visualization/visualization_tools

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/robot/ws_moveit2/install/moveit_task_constructor_visualization")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/robot/ws_moveit2/src/moveit_task_constructor/visualization/visualization_tools/include/")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmoveit_task_visualization_tools.so.0.1.3" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmoveit_task_visualization_tools.so.0.1.3")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmoveit_task_visualization_tools.so.0.1.3"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/robot/ws_moveit2/build/moveit_task_constructor_visualization/visualization_tools/libmoveit_task_visualization_tools.so.0.1.3")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmoveit_task_visualization_tools.so.0.1.3" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmoveit_task_visualization_tools.so.0.1.3")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmoveit_task_visualization_tools.so.0.1.3"
         OLD_RPATH "/opt/ros/humble/opt/rviz_ogre_vendor/lib:/home/robot/ws_moveit2/install/moveit_task_constructor_msgs/lib:/home/robot/ws_moveit2/install/moveit_ros_visualization/lib:/home/robot/ws_moveit2/install/moveit_ros_robot_interaction/lib:/home/robot/ws_moveit2/install/moveit_ros_planning_interface/lib:/home/robot/ws_moveit2/install/moveit_ros_warehouse/lib:/opt/ros/humble/lib/x86_64-linux-gnu:/home/robot/ws_moveit2/install/srdfdom/lib:/opt/ros/humble/lib:/home/robot/ws_moveit2/install/moveit_ros_move_group/lib:/home/robot/ws_moveit2/install/moveit_ros_planning/lib:/home/robot/ws_moveit2/install/moveit_ros_occupancy_map_monitor/lib:/home/robot/ws_moveit2/install/moveit_core/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmoveit_task_visualization_tools.so.0.1.3")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/robot/ws_moveit2/build/moveit_task_constructor_visualization/visualization_tools/libmoveit_task_visualization_tools.so")
endif()

