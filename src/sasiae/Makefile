export CC=g++
export CFLAGS=-Wall -Wextra --std=c++11
export BUILD=../../build/sasiae
export INCLUDE=../../include/sasiae
export LIB=$(BUILD)/libaversive.a

SHELL=/bin/bash

SUB_DIRS= # add the sub directory's names here

all: build $(SUB_DIRS) $(LIB)

# to build local sources
build: $(BUILD)/aversive.o

$(BUILD)/aversive.o: aversive.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $@ -c $<

$(BUILD)/%.o: %.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $@ -c $<

$(SUB_DIRS):
	$(MAKE) -C $@

$(LIB): $(BUILD)/aversive.o
	ar cr $(LIB) $?
