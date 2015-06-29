cmake_minimum_required(VERSION 2.6)

set(AVERSIVE_MCU "atmega2560")
include("${CMAKE_CURRENT_LIST_DIR}/../toolchain/avr.cmake")

set(CMAKE_C_FLAGS      "${CMAKE_C_FLAGS_INIT} -D__AVR_ATmega2560__" CACHE STRING "")
set(CMAKE_CXX_FLAGS    "${CMAKE_CXX_FLAGS_INIT} -D__AVR_ATmega2560__" CACHE STRING "")
