add_module(base)
add_module(container)
add_module(math)
add_module(geometry)
add_module(stream)
add_module(device)
add_module(filter)

add_module(stm32)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -fsingle-precision-constant -Wdouble-promotion -ffunction-sections -fdata-sections -DSTM32F40_41xxx -fno-rtti -fno-exceptions")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -fsingle-precision-constant -Wdouble-promotion -ffunction-sections -fdata-sections -DSTM32F40_41xxx -fno-rtti -fno-exceptions")
