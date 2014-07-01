TEMPLATE = lib
CONFIG = qt staticlib
QT = core

TARGET = aversive_sasiae

DESTDIR = build
OBJECTS_DIR = build/sasiae

QMAKE_CXXFLAGS = -std=c++11 -O3 -fPIC

INCLUDEPATH = include/sasiae

HEADERS =
SOURCES=
include(sasiae.files)
include(common.files)
