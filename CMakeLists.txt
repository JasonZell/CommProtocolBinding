cmake_minimum_required(VERSION 3.2)

# Name of the project (will be the name of the plugin)
project (CommProtocolBinder)

# Boost dependency

# Include BoostLib module
# file(GLOB_RECURSE boostlib_cmake_path "${CMAKE_CURRENT_SOURCE_DIR}/node_modules" "BoostLib.cmake")
# list(GET boostlib_cmake_path 0 boostlib_cmake_path)
# get_filename_component(boostlib_cmake_path "${boostlib_cmake_path}" DIRECTORY)
# SET(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${boostlib_cmake_path}")
# include(BoostLib)

# Locate/Download Boost (semver)
# require_boost_libs(">= 1.66.0" "coroutine")
# include_directories(${Boost_INCLUDE_DIRS})

# Essential include files to build a node addon,
# you should add this line in every CMake.js based project.
include_directories(${CMAKE_JS_INC})
include_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/include/Encryption/cryptopp564/)
include_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/include/libxbee3)

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)

# Declare the location of the source files
file(GLOB SOURCE_FILES
      main.cpp
      v8Utilities.cpp
      # src/ReceivePacket.cpp
      # src/SerialXbee.cpp
      # src/TransmitRequest.cpp
      # src/Utility.cpp
      )
# Add Commprotocol Static library
#find_library(CommProtocol libCommProtocol-Static)
#find_library(libxbee3 liblibxbee3)
#add_library(CommProtocol STATIC IMPORTED)
#add_library(libxbee3 SHARED)
	  
# This line will tell CMake that we're building a shared library
# from the above source files
# named after the project's name
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

# This line will give our library file a .node extension without any "lib" prefix
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")

# Essential library files to link to a node addon,
# you should add this line in every CMake.js based project.
# Define Boost dependencies there.

# target_link_libraries(${PROJECT_NAME} ${CMAKE_JS_LIB};${Boost_LIBRARIES})

target_link_libraries(${PROJECT_NAME} CommProtocol-Shared)
target_link_libraries(${PROJECT_NAME} libxbee3)
target_link_libraries(${PROJECT_NAME} cryptopp)
target_link_libraries(${PROJECT_NAME} ${CMAKE_JS_LIB})
