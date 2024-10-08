# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.6)
   message(FATAL_ERROR "CMake >= 2.6.0 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.6...3.20)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

if(CMAKE_VERSION VERSION_LESS 3.0.0)
  message(FATAL_ERROR "This file relies on consumers using CMake 3.0.0 or greater.")
endif()

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_targetsDefined)
set(_targetsNotDefined)
set(_expectedTargets)
foreach(_expectedTarget OpenXR::openxr_loader OpenXR::headers)
  list(APPEND _expectedTargets ${_expectedTarget})
  if(NOT TARGET ${_expectedTarget})
    list(APPEND _targetsNotDefined ${_expectedTarget})
  endif()
  if(TARGET ${_expectedTarget})
    list(APPEND _targetsDefined ${_expectedTarget})
  endif()
endforeach()
if("${_targetsDefined}" STREQUAL "${_expectedTargets}")
  unset(_targetsDefined)
  unset(_targetsNotDefined)
  unset(_expectedTargets)
  set(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT "${_targetsDefined}" STREQUAL "")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_targetsDefined}\nTargets not yet defined: ${_targetsNotDefined}\n")
endif()
unset(_targetsDefined)
unset(_targetsNotDefined)
unset(_expectedTargets)


# Create imported target OpenXR::openxr_loader
add_library(OpenXR::openxr_loader STATIC IMPORTED)

set_target_properties(OpenXR::openxr_loader PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "C:/Users/Chengxiang Li/Desktop/OpenXR-SDK-Source-release-1.1.37/include;D:/HelloWorldTest/include"
  INTERFACE_LINK_LIBRARIES "Threads::Threads;OpenXR::headers;advapi32"
)

# Create imported target OpenXR::headers
add_library(OpenXR::headers INTERFACE IMPORTED)

set_target_properties(OpenXR::headers PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "D:/HelloWorldTest/include"
)

# Import target "OpenXR::openxr_loader" for configuration "Debug"
set_property(TARGET OpenXR::openxr_loader APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(OpenXR::openxr_loader PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "C;CXX;RC"
  IMPORTED_LOCATION_DEBUG "D:/HelloWorldTest/src/loader/Debug/openxr_loaderd.lib"
  )

# Import target "OpenXR::openxr_loader" for configuration "Release"
set_property(TARGET OpenXR::openxr_loader APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(OpenXR::openxr_loader PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C;CXX;RC"
  IMPORTED_LOCATION_RELEASE "D:/HelloWorldTest/src/loader/Release/openxr_loader.lib"
  )

# Import target "OpenXR::openxr_loader" for configuration "MinSizeRel"
set_property(TARGET OpenXR::openxr_loader APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(OpenXR::openxr_loader PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_MINSIZEREL "C;CXX;RC"
  IMPORTED_LOCATION_MINSIZEREL "D:/HelloWorldTest/src/loader/MinSizeRel/openxr_loader.lib"
  )

# Import target "OpenXR::openxr_loader" for configuration "RelWithDebInfo"
set_property(TARGET OpenXR::openxr_loader APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(OpenXR::openxr_loader PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "C;CXX;RC"
  IMPORTED_LOCATION_RELWITHDEBINFO "D:/HelloWorldTest/src/loader/RelWithDebInfo/openxr_loader.lib"
  )

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)
