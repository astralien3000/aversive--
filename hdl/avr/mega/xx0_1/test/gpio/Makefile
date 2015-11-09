# Minimal project makefile

########################################
# User Configuration

## The root aversive directory
AVERSIVE_ROOT=../../../../../..

## Your project's object .o files
OBJ=main.o

## Your executable file name
GEN_EXEC=test

########################################
# Automatic Configuration

## Compiler
AVR_CC=avr-g++

## Flags
GEN_CFLAGS=-Wall -Wextra --std=c++11
AVR_CFLAGS=$(GEN_CFLAGS) -fno-threadsafe-statics -D__STDC_LIMIT_MACROS -O3

## Include
GEN_INCLUDE= -I$(AVERSIVE_ROOT)/include -I$(AVERSIVE_ROOT)/base/include
AVR_INCLUDE= $(GEN_INCLUDE) -I$(AVERSIVE_ROOT)/hdl/common/include

## Link
GEN_LDFLAGS= -lAversive++
AVR_LDFLAGS= $(GEN_LDFLAGS) -Wl,--whole-archive -lAversive++_startup -Wl,--no-whole-archive -nostartfiles

## Build Directory
GEN_BUILD_DIR=build
AVR_BUILD_DIR=$(GEN_BUILD_DIR)

########################################
# Rules
all:
	make atmega2560
	make atmega2561
	make atmega1280
	make atmega1281
	make atmega640

atmega128: export AVERSIVE_MMCU=atmega128
atmega128: avr

atmega2560: export AVERSIVE_MMCU=atmega2560
atmega2560: avr

atmega2561: export AVERSIVE_MMCU=atmega2561
atmega2561: avr

atmega1280: export AVERSIVE_MMCU=atmega1280
atmega1280: avr

atmega1281: export AVERSIVE_MMCU=atmega1281
atmega1281: avr

atmega640: export AVERSIVE_MMCU=atmega640
atmega640: avr

avr: export CC=$(AVR_CC)
avr: export CFLAGS=$(AVR_CFLAGS) $(WCFLAGS) -mmcu=$(AVERSIVE_MMCU)
avr: export INCLUDE=$(AVR_INCLUDE)
avr: export LDFLAGS=-L$(AVERSIVE_ROOT)/build/$(AVERSIVE_MMCU) $(AVR_LDFLAGS)
avr: export BUILD_DIR=$(AVR_BUILD_DIR)/$(AVERSIVE_MMCU)
avr: export EXEC=$(GEN_EXEC)_$(AVERSIVE_MMCU).elf
avr: compile

# Add additional files you need to compile
# Add additional dependencies if needed for each .o files (apart from the .cpp file)
%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -o $(BUILD_DIR)/$@ -c $<

compile: make_build_dir $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(addprefix $(BUILD_DIR)/, $(OBJ)) $(LDFLAGS)

make_build_dir:
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(shell find . -name "*~" -o -name "#*#" -o -name "*.o") $(GEN_BUILD_DIR)

mrproper: clean
	rm -rf $(GEN_EXEC)_*.elf
