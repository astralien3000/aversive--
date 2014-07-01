MCPU=cortex-m4
MMCU=stm32f4

TEMPLATE = lib
CONFIG = staticlib
QT =

TARGET = aversive_$${MMCU}

DESTDIR = build
OBJECTS_DIR = build/$${MMCU}

QMAKE_CXX = arm-none-eabi-g++
QMAKE_CC = arm-none-eabi-gcc

QMAKE_CXXFLAGS = -std=c++11 -Wall -Wextra -mcpu=$${MCPU} -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -fsingle-precision-constant -Wdouble-promotion -ffunction-sections -fdata-sections -DSTM32F40_41xxx
QMAKE_CXXFLAGS_DEBUG = -g
QMAKE_CXXFLAGS_RELEASE = -O3

QMAKE_CFLAGS = -mthumb -mcpu=$${MCPU} -mfloat-abi=hard -mfpu=fpv4-sp-d16 -fsingle-precision-constant -Wdouble-promotion -Wall -Wextra -ffunction-sections -fdata-sections -DSTM32F40_41xxx  -DDEBUG -DUSART_DEBUG=USART1 -DHSE_VALUE=168000000
QMAKE_CFLAGS_DEBUG = -g
QMAKE_CFLAGS_RELEASE = -Os

INCLUDEPATH = include/stm32 thirdparty/stm32f4xx

HEADERS =
SOURCES = thirdparty/stm32f4xx/system_stm32f4xx.c thirdparty/stm32f4xx/syscalls.c thirdparty/stm32f4xx/startup_stm32f40_41xxx.s
include(generated/stm32.files.pro)
include(generated/common.files.pro)

QMAKE_AR_CMD = arm-none-eabi-ar cqs ${TARGET} ${OBJECTS}
