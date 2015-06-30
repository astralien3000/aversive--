cmake_minimum_required(VERSION 2.6)
cmake_policy(SET CMP0011 NEW)

set(AVERSIVE_PLATFORM "stm32")
set(AVERSIVE_CPU "cortex-m4")
include("${CMAKE_CURRENT_LIST_DIR}/../arm.cmake")

set(CMAKE_C_FLAGS      "${CMAKE_C_FLAGS_INIT} -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -fsingle-precision-constant -Wdouble-promotion -ffunction-sections -fdata-sections -DSTM32F40_41xxx" CACHE STRING "")
set(CMAKE_CXX_FLAGS    "${CMAKE_CXX_FLAGS_INIT} -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -fsingle-precision-constant -Wdouble-promotion -ffunction-sections -fdata-sections -DSTM32F40_41xxx" CACHE STRING "")
