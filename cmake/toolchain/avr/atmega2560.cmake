cmake_minimum_required(VERSION 2.6)
cmake_policy(SET CMP0011 NEW)

set(AVERSIVE_MCU "atmega2560")
include("${CMAKE_CURRENT_LIST_DIR}/../avr.cmake")

set(ATMEGA2560_FLAGS "-D__AVR_ATmega2560__ -D_AVERSIVE_OLD_SUPPORT")

set(CMAKE_C_FLAGS      "${CMAKE_C_FLAGS_INIT} ${ATMEGA2560_FLAGS}" CACHE STRING "")
set(CMAKE_CXX_FLAGS    "${CMAKE_CXX_FLAGS_INIT} ${ATMEGA2560_FLAGS}" CACHE STRING "")
set(CMAKE_ASM_FLAGS    "${CMAKE_ASM_FLAGS_INIT} ${ATMEGA2560_FLAGS}" CACHE STRING "")

unset(ATMEGA2560_FLAGS)
