cmake_minimum_required(VERSION 2.6)
cmake_policy(SET CMP0011 NEW)

set(AVERSIVE_PLATFORM "stm32")
set(AVERSIVE_CPU "cortex-m4")
set(AVERSIVE_THIRDPARTY core_cm4.h core_cm4_simd.h core_cmFunc.h core_cmInstr.h startup_stm32f40_41xxx.s stm32f4xx.h syscalls.c system_stm32f4xx.c system_stm32f4xx.h)

set(res)
foreach(l ${AVERSIVE_THIRDPARTY})
  list(APPEND res "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/stm32f4xx/${l}")
endforeach()
set(AVERSIVE_THIRDPARTY ${res})
unset(res)

include("${CMAKE_CURRENT_LIST_DIR}/../arm.cmake")

set(STM32F4_FLAGS "-mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -fsingle-precision-constant -Wdouble-promotion -ffunction-sections -fdata-sections -DSTM32F40_41xxx -DDEBUG -DUSART_DEBUG=USART1 -DHSE_VALUE=168000000 -I${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/stm32f4xx")

set(CMAKE_C_FLAGS      "${CMAKE_C_FLAGS_INIT} ${STM32F4_FLAGS}" CACHE STRING "")
set(CMAKE_CXX_FLAGS    "${CMAKE_CXX_FLAGS_INIT} ${STM32F4_FLAGS}" CACHE STRING "")
set(CMAKE_ASM_FLAGS    "${CMAKE_ASM_FLAGS_INIT} ${STM32F4_FLAGS}" CACHE STRING "")

unset(STM32F4_FLAGS)
