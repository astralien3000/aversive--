# Minimal project makefile

########################################
# User Configuration

## The root aversive directory
AVERSIVE_ROOT=../..

## Your project's object .o files
OBJ=main.o

## Your executable file name
GEN_EXEC=robot

########################################
# Aversive++ Configuration
# You can retrieve these values from Aversive::Config class

## Dummy parameter
PARAM_DUMMY=42

########################################
# Automatic Configuration

## Compiler
SASIAE_CC=g++
AVR_CC=avr-g++

## Flags
GEN_CFLAGS=-Wall -Wextra --std=c++11
SASIAE_CFLAGS=$(GEN_CFLAGS) -DQT_CORE_LIB -fpic
AVR_CFLAGS=$(GEN_CFLAGS) -fno-threadsafe-statics -D__STDC_LIMIT_MACROS -O3

## Include
GEN_INCLUDE= -I$(AVERSIVE_ROOT)/include
SASIAE_INCLUDE= $(GEN_INCLUDE)/sasiae -I/usr/include/qt5 -I/usr/include/qt5/QtCore
AVR_INCLUDE= $(GEN_INCLUDE)/avr

## Config symbols
DUMMY_SYM=_ZN8Aversive6Config13__PARAM_DUMMYE=$(PARAM_DUMMY)

SYMBOL_LIST=$(DUMMY_SYM)

## Link
DEFSYM=-Wl,--defsym=
GEN_LDFLAGS= -L$(AVERSIVE_ROOT)/build $(addprefix $(DEFSYM), $(SYMBOL_LIST))
SASIAE_LDFLAGS= $(GEN_LDFLAGS) -laversive_sasiae -lQt5Core -lpthread
AVR_LDFLAGS= $(GEN_LDFLAGS) 

## Build Directory
GEN_BUILD_DIR=build
SASIAE_BUILD_DIR=$(GEN_BUILD_DIR)/sasiae
AVR_BUILD_DIR=$(GEN_BUILD_DIR)

########################################
# Rules
all:
	@echo "Usage :"
	@echo "\t- make sasiae: Compile your project for sasiae"
	@echo "\t- make atmegaX: Compile your project for atmegaX (X may be 16, 32, 128 or 2560)"
	@echo "\t- make clean: Remove all temporary files"
	@echo "\t- make mrproper: Remove all temporary files + the binary files"

sasiae: export CC=$(SASIAE_CC)
sasiae: export CFLAGS=$(SASIAE_CFLAGS)
sasiae: export INCLUDE=$(SASIAE_INCLUDE)
sasiae: export LDFLAGS=$(SASIAE_LDFLAGS)
sasiae: export BUILD_DIR=$(SASIAE_BUILD_DIR)
sasiae: export EXEC=$(GEN_EXEC)_sasiae.elf
sasiae: compile

atmega128: export AVERSIVE_MMCU=atmega128
atmega128: avr

atmega2560: export AVERSIVE_MMCU=atmega2560
atmega2560: avr

avr: export CC=$(AVR_CC)
avr: export CFLAGS=$(AVR_CFLAGS) -mmcu=$(AVERSIVE_MMCU)
avr: export INCLUDE=$(AVR_INCLUDE)
avr: export LDFLAGS=$(AVR_LDFLAGS) -laversive_$(AVERSIVE_MMCU)
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
