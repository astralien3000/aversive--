TEMPLATE = app
CONFIG = qt
QT = core

QMAKE_LIBDIR = ../../../build
QMAKE_LIBS = -laversive_sasiae

DESTDIR = .
OBJECTS_DIR = build

QMAKE_CXXFLAGS = -std=c++11 -Wall -Wextra
QMAKE_CXXFLAGS_DEBUG = -g
QMAKE_CXXFLAGS_RELEASE = -O3

QMAKE_LFLAGS = -Wall -Wextra
QMAKE_LFLAGS_DEBUG = -g
QMAKE_LFLAGS_RELEASE = -O3

INCLUDEPATH = ../../../include/sasiae
