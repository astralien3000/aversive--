cmake_minimum_required(VERSION 2.6)
cmake_policy(SET CMP0011 NEW)

set(AVERSIVE_MCU "atmega32")
include("${CMAKE_CURRENT_LIST_DIR}/../avr.cmake")

set(CMAKE_C_FLAGS      "${CMAKE_C_FLAGS_INIT} -D__AVR_ATmega32__" CACHE STRING "")
set(CMAKE_CXX_FLAGS    "${CMAKE_CXX_FLAGS_INIT} -D__AVR_ATmega32__" CACHE STRING "")
