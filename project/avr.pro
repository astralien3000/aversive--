MMCU = atmega2560

TEMPLATE = lib
CONFIG = staticlib
QT =

TARGET = aversive_$${MMCU}

DESTDIR = build
OBJECTS_DIR = build/avr

QMAKE_CXX = avr-g++

QMAKE_CXXFLAGS = -std=c++11 -Wall -Wextra -mmcu=$${MMCU}
QMAKE_CXXFLAGS_DEBUG = -g
QMAKE_CXXFLAGS_RELEASE = -O3

INCLUDEPATH = include/avr

HEADERS = $$system("find ../include/{avr,common} | grep \\.hpp")
SOURCES= $$system("find ../src/{avr,common} | grep \\.cpp")

QMAKE_AR_CMD = avr-ar cqs ${TARGET} ${OBJECTS}
