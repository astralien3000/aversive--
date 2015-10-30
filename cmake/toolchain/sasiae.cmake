cmake_minimum_required(VERSION 2.6)
cmake_policy(SET CMP0011 NEW)

set(CMAKE_SYSTEM_NAME Linux)

include("${CMAKE_CURRENT_LIST_DIR}/generic.cmake")

set(SASIAE_FLAGS "-fPIC -Os")

set(AVERSIVE_PLATFORM    sasiae)
set(CMAKE_C_COMPILER     gcc)
set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS_INIT} ${SASIAE_FLAGS}")
set(CMAKE_CXX_COMPILER   g++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_INIT} ${SASIAE_FLAGS} -fno-rtti -fno-exceptions")
set(CMAKE_ASM_COMPILER   gcc)
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS_INIT} ${SASIAE_FLAGS}")

unset(SASIAE_FLAGS)
