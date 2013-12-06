export CC=g++
export CFLAGS=-Wall -Wextra
export BUILD=../../build/sasiae
export INCLUDE=../../include/sasiae

SUB_DIRS= # add the sub directory's names here

all: build $(SUB_DIRS) lib

# to build local sources
build: $(BUILD)/aversive.o

$(BUILD)/aversive.o: $(INCLUDE)/aversive.hpp
$(BUILD)/%.o: %.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $@ -c $<

$(SUB_DIRS):
	$(MAKE) -C $@

lib: $(BUILD)/aversive.o
	ar r $(BUILD)/libaversive.a $?