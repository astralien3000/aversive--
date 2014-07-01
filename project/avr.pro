include(generated/avr.mmcu.pro)

TEMPLATE = lib
CONFIG = staticlib
QT =

TARGET = aversive_$${MMCU}

DESTDIR = build
OBJECTS_DIR = build/$${MMCU}

QMAKE_CXX = avr-g++

QMAKE_CXXFLAGS = -std=c++11 -Wall -Wextra -mmcu=$${MMCU}
QMAKE_CXXFLAGS_DEBUG = -g
QMAKE_CXXFLAGS_RELEASE = -O3

INCLUDEPATH = include/avr

HEADERS =
SOURCES =
include(generated/avr.files.pro)
include(generated/common.files.pro)

QMAKE_AR_CMD = avr-ar cqs ${TARGET} ${OBJECTS}
