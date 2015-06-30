cmake_minimum_required(VERSION 2.6)
cmake_policy(SET CMP0011 NEW)

set(CMAKE_SYSTEM_NAME Generic)

include("${CMAKE_CURRENT_LIST_DIR}/generic.cmake")

set(AVERSIVE_PLATFORM    avr)
set(CMAKE_C_COMPILER     avr-gcc)
set(CMAKE_C_FLAGS_INIT   "${CMAKE_C_FLAGS_INIT} -Os -mcall-prologues -I${CMAKE_CURRENT_SOURCE_DIR}/include/avr -mmcu=${AVERSIVE_MCU}")
set(CMAKE_CXX_COMPILER   avr-g++)
set(CMAKE_CXX_FLAGS_INIT "${CMAKE_CXX_FLAGS_INIT} -Os -mcall-prologues -I${CMAKE_CURRENT_SOURCE_DIR}/include/avr -mmcu=${AVERSIVE_MCU}")
set(CMAKE_AR             avr-ar)
