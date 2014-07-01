MCPU=cortex-m4
MMCU=stm32f4

TEMPLATE = app
CONFIG =
QT =

TARGET = test.elf

DESTDIR = build
OBJECTS_DIR = build/$${MMCU}

QMAKE_CXX = arm-none-eabi-g++
QMAKE_CC = arm-none-eabi-gcc
QMAKE_LINK = arm-none-eabi-gcc

QMAKE_CXXFLAGS = -std=c++11 -Wall -Wextra -mcpu=$${MCPU} -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -fsingle-precision-constant -Wdouble-promotion -ffunction-sections -fdata-sections -DSTM32F40_41xxx
QMAKE_CXXFLAGS_DEBUG = -g
QMAKE_CXXFLAGS_RELEASE = -O3

QMAKE_CFLAGS = -mthumb -mcpu=$${MCPU} -mfloat-abi=hard -mfpu=fpv4-sp-d16 -fsingle-precision-constant -Wdouble-promotion -Wall -Wextra -ffunction-sections -fdata-sections -DSTM32F40_41xxx  -DDEBUG -DUSART_DEBUG=USART1 -DHSE_VALUE=168000000
QMAKE_CFLAGS_DEBUG = -g
QMAKE_CFLAGS_RELEASE = -O3

INCLUDEPATH = ../../include/stm32 ../../thirdparty/stm32f4xx

LIBS = -L"/home/astralien3000/aversive--/build" -laversive_stm32f4

HEADERS =
SOURCES = main.cpp

QMAKE_LFLAGS = -Tlink.ld -mthumb -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -fsingle-precision-constant -Wdouble-promotion -Wall -Wextra -ffunction-sections -fdata-sections -DSTM32F40_41xxx -Wl,--gc-sections -nostartfiles -nostdlib
QMAKE_LFLAGS_DEBUG =
QMAKE_LFLAGS_RELEASE =

QMAKE_POST_LINK = arm-none-eabi-objcopy -O binary build/test.elf build/test.bin
