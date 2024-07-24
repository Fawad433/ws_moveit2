#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "moveit_resources_prbt_ikfast_manipulator_plugin::prbt_manipulator_moveit_ikfast_plugin" for configuration "Release"
set_property(TARGET moveit_resources_prbt_ikfast_manipulator_plugin::prbt_manipulator_moveit_ikfast_plugin APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(moveit_resources_prbt_ikfast_manipulator_plugin::prbt_manipulator_moveit_ikfast_plugin PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libprbt_manipulator_moveit_ikfast_plugin.so"
  IMPORTED_SONAME_RELEASE "libprbt_manipulator_moveit_ikfast_plugin.so"
  )

list(APPEND _cmake_import_check_targets moveit_resources_prbt_ikfast_manipulator_plugin::prbt_manipulator_moveit_ikfast_plugin )
list(APPEND _cmake_import_check_files_for_moveit_resources_prbt_ikfast_manipulator_plugin::prbt_manipulator_moveit_ikfast_plugin "${_IMPORT_PREFIX}/lib/libprbt_manipulator_moveit_ikfast_plugin.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
