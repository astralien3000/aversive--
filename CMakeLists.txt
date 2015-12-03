cmake_minimum_required(VERSION 2.6)

project(Aversive++ CXX C ASM)

file(GLOB_RECURSE COMMON_HPP "include/common/*.hpp")
file(GLOB_RECURSE PLATFORM_HPP "include/${AVERSIVE_PLATFORM}/*.hpp")
file(GLOB_RECURSE COMMON_CPP "src/common/*.cpp")
file(GLOB_RECURSE PLATFORM_CPP "src/${AVERSIVE_PLATFORM}/*.cpp")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include/${AVERSIVE_PLATFORM}")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/base/include/")

if(${AVERSIVE_PLATFORM} STREQUAL "sasiae")
  find_package(Qt5 COMPONENTS Core)
  include_directories(${Qt5Core_INCLUDE_DIRS})
endif()

add_library(Aversive++ STATIC ${COMMON_HPP} ${PLATFORM_HPP} ${COMMON_CPP} ${PLATFORM_CPP} ${AVERSIVE_THIRDPARTY})


add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/hdl")

if(DEFINED STARTUP_FILES)
  add_library(Aversive++_startup STATIC $<TARGET_OBJECTS:hdl_test_startup>)
endif()