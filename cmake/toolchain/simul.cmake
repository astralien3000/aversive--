cmake_minimum_required(VERSION 2.6)
cmake_policy(SET CMP0011 NEW)

set(CMAKE_SYSTEM_NAME Linux)

include("${CMAKE_CURRENT_LIST_DIR}/generic.cmake")

set(SIMUL_FLAGS "-Os")

set(AVERSIVE_PLATFORM    sasiae)

set(CMAKE_C_COMPILER     gcc)
set(CMAKE_C_FLAGS_INIT   "${CMAKE_C_FLAGS_INIT} ${SIMUL_FLAGS}")
set(CMAKE_CXX_COMPILER   g++)
set(CMAKE_CXX_FLAGS_INIT "${CMAKE_CXX_FLAGS_INIT} ${SIMUL_FLAGS} -fno-rtti -fno-exceptions")
set(CMAKE_ASM_COMPILER   gcc)
set(CMAKE_ASM_FLAGS_INIT "${CMAKE_ASM_FLAGS_INIT} ${SIMUL_FLAGS}")

unset(SIMUL_FLAGS)
