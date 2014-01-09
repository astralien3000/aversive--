export CC=g++
export CFLAGS=-Wall -Wextra -std=c++11 -DQT_CORE_LIB -DQT_NETWORK_LIB -I/usr/include/qt5 -I/usr/include/qt5/QtCore -I/usr/include/qt5/QtNetwork -fPIE -g
export BUILD=../../build/sasiae
export INCLUDE=../../include/sasiae
export LIB=$(BUILD)/libaversive.a
OBJ=$(BUILD)/aversive.o $(BUILD)/client_thread.o

SHELL=/bin/bash

SUB_DIRS= # add the sub directory's names here

all: build $(SUB_DIRS) $(LIB)

# to build local sources
build: $(OBJ)

$(BUILD)/aversive.o: $(INCLUDE)/aversive.hpp
$(BUILD)/client_thread.o: $(INCLUDE)/client_thread.hpp $(INCLUDE)/base/singleton.hpp
$(BUILD)/%.o: %.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $@ -c $<

$(SUB_DIRS):
	$(MAKE) -C $@

$(LIB): $(OBJ)
	ar cr $(LIB) $?
