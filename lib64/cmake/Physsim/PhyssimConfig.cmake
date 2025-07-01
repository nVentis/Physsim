###############################################################
# Physsim CMAKE CONFIG
#
# Exported Targets
#
#   Physsim::Physsim     The Physsim library
###############################################################

####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was PhyssimConfig.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

macro(set_and_check _var _file)
  set(${_var} "${_file}")
  if(NOT EXISTS "${_file}")
    message(FATAL_ERROR "File or directory ${_file} referenced by variable ${_var} does not exist !")
  endif()
endmacro()

macro(check_required_components _NAME)
  foreach(comp ${${_NAME}_FIND_COMPONENTS})
    if(NOT ${_NAME}_${comp}_FOUND)
      if(${_NAME}_FIND_REQUIRED_${comp})
        set(${_NAME}_FOUND FALSE)
      endif()
    endif()
  endforeach()
endmacro()

####################################################################################

# set_and_check(Physsim_INCLUDE_DIR "")
# set_and_check(Physsim_LIBRARY_DIR "")

include(CMakeFindDependencyMacro)
find_dependency(ROOT 6.32.04)

if (NOT TARGET Physsim::Physsim)
  include("${CMAKE_CURRENT_LIST_DIR}/PhyssimTargets.cmake")
endif()

check_required_components(Physsim)

# Print the default "Found" message and check library location
include(FindPackageHandleStandardArgs)
get_property(TEST_PHYSSIM_LIBRARY TARGET Physsim::Physsim PROPERTY LOCATION)
find_package_handle_standard_args(Physsim DEFAULT_MSG CMAKE_CURRENT_LIST_FILE TEST_PHYSSIM_LIBRARY)
