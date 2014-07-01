MMCU = atmega2560

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
include(avr.files)
include(common.files)

QMAKE_AR_CMD = avr-ar cqs ${TARGET} ${OBJECTS}
