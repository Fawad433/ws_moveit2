# Install script for directory: /home/robot/ws_moveit2/src/moveit_task_constructor/core/python/pybind11

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/robot/ws_moveit2/install/moveit_task_constructor_core")
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/moveit/python" TYPE DIRECTORY FILES "/home/robot/ws_moveit2/src/moveit_task_constructor/core/python/pybind11/include/pybind11")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/moveit_task_constructor_core/cmake" TYPE FILE FILES
    "/home/robot/ws_moveit2/build/moveit_task_constructor_core/python/pybind11/pybind11Config.cmake"
    "/home/robot/ws_moveit2/build/moveit_task_constructor_core/python/pybind11/pybind11ConfigVersion.cmake"
    "/home/robot/ws_moveit2/src/moveit_task_constructor/core/python/pybind11/tools/FindPythonLibsNew.cmake"
    "/home/robot/ws_moveit2/src/moveit_task_constructor/core/python/pybind11/tools/pybind11Common.cmake"
    "/home/robot/ws_moveit2/src/moveit_task_constructor/core/python/pybind11/tools/pybind11Tools.cmake"
    "/home/robot/ws_moveit2/src/moveit_task_constructor/core/python/pybind11/tools/pybind11NewTools.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/moveit_task_constructor_core/cmake/pybind11Targets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/moveit_task_constructor_core/cmake/pybind11Targets.cmake"
         "/home/robot/ws_moveit2/build/moveit_task_constructor_core/python/pybind11/CMakeFiles/Export/2579f0094c5c66d55d2dc8b46e954c9c/pybind11Targets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/moveit_task_constructor_core/cmake/pybind11Targets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/moveit_task_constructor_core/cmake/pybind11Targets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/moveit_task_constructor_core/cmake" TYPE FILE FILES "/home/robot/ws_moveit2/build/moveit_task_constructor_core/python/pybind11/CMakeFiles/Export/2579f0094c5c66d55d2dc8b46e954c9c/pybind11Targets.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pkgconfig" TYPE FILE FILES "/home/robot/ws_moveit2/build/moveit_task_constructor_core/python/pybind11/pybind11.pc")
endif()

