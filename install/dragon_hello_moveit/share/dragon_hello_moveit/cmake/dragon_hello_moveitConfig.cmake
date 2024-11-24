# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_dragon_hello_moveit_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED dragon_hello_moveit_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(dragon_hello_moveit_FOUND FALSE)
  elseif(NOT dragon_hello_moveit_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(dragon_hello_moveit_FOUND FALSE)
  endif()
  return()
endif()
set(_dragon_hello_moveit_CONFIG_INCLUDED TRUE)

# output package information
if(NOT dragon_hello_moveit_FIND_QUIETLY)
  message(STATUS "Found dragon_hello_moveit: 0.0.0 (${dragon_hello_moveit_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'dragon_hello_moveit' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${dragon_hello_moveit_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(dragon_hello_moveit_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${dragon_hello_moveit_DIR}/${_extra}")
endforeach()
