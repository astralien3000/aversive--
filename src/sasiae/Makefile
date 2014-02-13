CC=g++
CFLAGS=-Wall -Wextra -std=c++11 -DQT_CORE_LIB -DQT_NETWORK_LIB -I/usr/include/qt5 -I/usr/include/qt5/QtCore -I/usr/include/qt5/QtNetwork -fPIE -g
BUILD=../../build/sasiae
export BUILD_EXPORT=$(BUILD)
INCLUDE=../../include/sasiae
export INCLUDE_EXPORT=$(INCLUDE)
LIB=$(BUILD)/libaversive.a
OBJ=$(BUILD)/aversive.o $(BUILD)/client_thread.o

SHELL=/bin/bash

SUB_DIRS=system # add the sub directory's names here

all: build system.d $(LIB)

# to build local sources
build: $(OBJ)

$(BUILD)/aversive.o: $(INCLUDE)/aversive.hpp
$(BUILD)/client_thread.o: $(INCLUDE)/client_thread.hpp $(INCLUDE)/base/singleton.hpp
$(BUILD)/%.o: %.cpp
	@echo "Compiling $@ ..."
	@$(CC) $(CFLAGS) -I$(INCLUDE) -o $@ -c $<

system.d:
	@echo "Making system ..."
	@$(MAKE) -C $(@:.d=)

$(LIB): $(OBJ)
	ar cr $(LIB) $(BUILD)/*.o
