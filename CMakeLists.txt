cmake_minimum_required(VERSION 2.8)

project(aversive++)

if(NOT DEFINED TARGET)
  set(TARGET sasiae)
endif()

unset(CMAKE_TOOLCHAIN_FILE CACHE)
if(${TARGET} STREQUAL "atmega2560")
  set(CMAKE_TOOLCHAIN_FILE ${PROJECT_SOURCE_DIR}/toolchain-avr.cmake)
endif()

if(DEFINED CMAKE_TOOLCHAIN_FILE)
  include(${CMAKE_TOOLCHAIN_FILE})
endif()

add_compile_options(-std=c++11)

include(modules-${TARGET}.cmake)

include_directories (${INCLUDE_DIRS})

add_library(aversive++_atmega2560 STATIC ${SOURCES})

unset(TARGET CACHE)