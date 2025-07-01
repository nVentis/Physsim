#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Physsim::Physsim" for configuration "RelWithDebInfo"
set_property(TARGET Physsim::Physsim APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(Physsim::Physsim PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib64/libPhyssim.so.0.5.0"
  IMPORTED_SONAME_RELWITHDEBINFO "libPhyssim.so.0.5"
  )

list(APPEND _cmake_import_check_targets Physsim::Physsim )
list(APPEND _cmake_import_check_files_for_Physsim::Physsim "${_IMPORT_PREFIX}/lib64/libPhyssim.so.0.5.0" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
