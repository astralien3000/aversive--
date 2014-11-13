cmake_minimum_required(VERSION 2.8)

project(aversive++)

add_compile_options(-std=c++11)
add_compile_options(-mmcu=atmega2560)
message(STATUS ${CMAKE_CXX_COMPILER})

include(modules-atmega2560.cmake)

include_directories (${INCLUDE_DIRS})

add_library(aversive++_atmega2560 STATIC ${SOURCES})

unset(TARGET CACHE)