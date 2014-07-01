TEMPLATE = lib
CONFIG = qt staticlib
QT = core

TARGET = aversive_sasiae

DESTDIR = build
OBJECTS_DIR = build/sasiae

QMAKE_CXXFLAGS = -std=c++11 -Wall -Wextra -fPIE
QMAKE_CXXFLAGS_DEBUG = -g
QMAKE_CXXFLAGS_RELEASE = -O3

INCLUDEPATH = include/sasiae

HEADERS =
SOURCES=
include(generated/sasiae.files.pro)
include(generated/common.files.pro)
