#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "srdfdom::srdfdom" for configuration "Release"
set_property(TARGET srdfdom::srdfdom APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(srdfdom::srdfdom PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libsrdfdom.so.2.0.4"
  IMPORTED_SONAME_RELEASE "libsrdfdom.so.2.0.4"
  )

list(APPEND _cmake_import_check_targets srdfdom::srdfdom )
list(APPEND _cmake_import_check_files_for_srdfdom::srdfdom "${_IMPORT_PREFIX}/lib/libsrdfdom.so.2.0.4" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
