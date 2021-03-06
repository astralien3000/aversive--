cmake_minimum_required(VERSION 2.6)
cmake_policy(SET CMP0011 NEW)

set(AVERSIVE_MCU "atmega1281")
include("${CMAKE_CURRENT_LIST_DIR}/../avr.cmake")

set(ATMEGA1281_FLAGS "-D__AVR_ATmega1281__")

set(CMAKE_C_FLAGS      "${CMAKE_C_FLAGS_INIT} ${ATMEGA1281_FLAGS}" CACHE STRING "")
set(CMAKE_CXX_FLAGS    "${CMAKE_CXX_FLAGS_INIT} ${ATMEGA1281_FLAGS}" CACHE STRING "")
set(CMAKE_ASM_FLAGS    "${CMAKE_ASM_FLAGS_INIT} ${ATMEGA1281_FLAGS}" CACHE STRING "")

unset(ATMEGA1281_FLAGS)
