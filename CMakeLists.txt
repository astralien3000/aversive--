cmake_minimum_required(VERSION 2.6)

project(Aversive++ CXX C ASM)

file(GLOB_RECURSE COMMON_HPP "include/common/*.hpp")
file(GLOB_RECURSE PLATFORM_HPP "include/${AVERSIVE_PLATFORM}/*.hpp")
file(GLOB_RECURSE COMMON_CPP "src/common/*.cpp")
file(GLOB_RECURSE PLATFORM_CPP "src/${AVERSIVE_PLATFORM}/*.cpp")

add_library(Aversive++ STATIC ${COMMON_HPP} ${PLATFORM_HPP} ${COMMON_CPP} ${PLATFORM_CPP} ${AVERSIVE_THIRDPARTY})
