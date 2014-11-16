cmake_minimum_required(VERSION 2.8)

project(aversive++)

add_compile_options(-std=c++11)
add_compile_options(-mmcu=atmega2560)
message(STATUS ${CMAKE_CXX_COMPILER})

macro(add_module name)
  message(STATUS "including module ${name} in the package")
  add_subdirectory(modules/${name})
endmacro(add_module)

include(modules-atmega2560.cmake)

include_directories (${INCLUDE_DIRS})
add_library(aversive++_atmega2560 STATIC ${SOURCES})

unset(TARGET CACHE)