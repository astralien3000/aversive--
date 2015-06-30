cmake_minimum_required(VERSION 2.6)
cmake_policy(SET CMP0011 NEW)

set(CMAKE_SYSTEM_NAME Generic)

include("${CMAKE_CURRENT_LIST_DIR}/generic.cmake")

set(CMAKE_C_COMPILER     arm-none-eabi-gcc)
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_C_FLAGS_INIT   "${CMAKE_C_FLAGS_INIT} -Os -I${CMAKE_CURRENT_SOURCE_DIR}/include/${AVERSIVE_PLATFORM} -mcpu=${AVERSIVE_CPU}")
set(CMAKE_CXX_COMPILER   arm-none-eabi-g++)
set(CMAKE_CXX_COMPILER_WORKS 1)
set(CMAKE_CXX_FLAGS_INIT "${CMAKE_CXX_FLAGS_INIT} -Os -I${CMAKE_CURRENT_SOURCE_DIR}/include/${AVERSIVE_PLATFORM} -mcpu=${AVERSIVE_CPU}")
set(CMAKE_AR             arm-none-eabi-ar)
