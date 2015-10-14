## The root aversive directory
AVERSIVE_ROOT=../../..

## Your project's object .o files
OBJ=test.o

## Your executable file name
GEN_EXEC=test

## Compiler
GEN_CC=g++

## Flags
GEN_CFLAGS=-Wall -Wextra --std=c++11

## Include
GEN_INCLUDE= -I$(AVERSIVE_ROOT)/hdl/common/include -I$(AVERSIVE_ROOT)/hal/common/include

## Link
GEN_LDFLAGS=

## Build Directory
GEN_BUILD_DIR=build

########################################
# Rules
all: build

build: export CC=$(GEN_CC)
build: export CFLAGS=$(GEN_CFLAGS)
build: export INCLUDE=$(GEN_INCLUDE)
build: export LDFLAGS=$(GEN_LDFLAGS)
build: export BUILD_DIR=$(GEN_BUILD_DIR)
build: export EXEC=$(GEN_EXEC).elf
build: compile

# Add additional files you need to compile
# Add additional dependencies if needed for each .o files (apart from the .cpp file)
%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -o $(BUILD_DIR)/$@ -c $<

compile: make_build_dir $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(addprefix $(BUILD_DIR)/, $(OBJ)) $(LDFLAGS)

make_build_dir:
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(shell find . -name "*~" -o -name "#*#" -o -name "*.o" -o -name "*.log") $(BUILD_DIR)

mrproper: clean
	rm -rf *.elf
