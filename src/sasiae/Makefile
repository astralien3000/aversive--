export CC=g++
export CFLAGS=-Wall -Wextra
export BUILD=../../build/sasiae
export INCLUDE=../../include/{sasiae,common}
export LIB=$(BUILD)/libaversive.a

SHELL=/bin/bash

SUB_DIRS= # add the sub directory's names here

all: build $(SUB_DIRS) $(LIB)

# to build local sources
build: $(BUILD)/aversive.o

$(BUILD)/aversive.o: aversive.cpp
$(BUILD)/%.o: %.cpp
	$(CC) $(CFLAGS) $(shell echo -I$(INCLUDE)) -o $@ -c $<

$(SUB_DIRS):
	$(MAKE) -C $@

$(LIB): $(BUILD)/aversive.o
	ar r $(LIB) $?