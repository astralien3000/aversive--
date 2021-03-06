# Minimal project makefile

SASIAE_CC=g++
AVR_CC=avr-g++

GEN_CFLAGS=-Wall -Wextra --std=c++11
SASIAE_CFLAGS=$(GEN_CFLAGS) -DQT_CORE_LIB -fPIE
AVR_CFLAGS=$(GEN_CFLAGS) -fno-threadsafe-statics -D__STD_LIMIT_MACROS -O3

# Add the path to the directory where Aversive++'s .h files are after -I (with no space)
GEN_INCLUDE= -I../../include
SASIAE_INCLUDE= $(GEN_INCLUDE)/sasiae -I/usr/include/qt5 -I/usr/include/qt5/QtCore
AVR_INCLUDE= $(GEN_INCLUDE)/avr

# Add the path to the directory where Aversive++'s .a files are after -L (with no space)
GEN_LDFLAGS= -L../../build
SASIAE_LDFLAGS= $(GEN_LDFLAGS) -laversive_sasiae -lQt5Core -lpthread
AVR_LDFLAGS= $(GEN_LDFLAGS) 

GEN_BUILD_DIR=build
SASIAE_BUILD_DIR=$(GEN_BUILD_DIR)/sasiae
AVR_BUILD_DIR=$(GEN_BUILD_DIR)/avr

# Your project's object .o files
OBJ= main.o
EXEC=robot

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
sasiae: compile

atmega128: export ATMEGA=atmega128
atmega128: avr

atmega2560: export ATMEGA=atmega2560
atmega2560: avr

avr: export CC=$(AVR_CC)
avr: export CFLAGS=$(AVR_CFLAGS) -mmcu=$(ATMEGA)
avr: export INCLUDE=$(AVR_INCLUDE)
avr: export LDFLAGS=$(AVR_LDFLAGS) -laversive_$(ATMEGA)
avr: export BUILD_DIR=$(AVR_BUILD_DIR)
avr: compile

# Add additional files you need to compile
# Add additional dependencies if needed for each .o files (apart from the .c file)
%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -o $(BUILD_DIR)/$@ -c $<

compile: make_build_dir $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(addprefix $(BUILD_DIR)/, $(OBJ)) $(LDFLAGS)

make_build_dir:
#	mkdir build $(BUILD_DIR)

clean:
	rm -f $(shell find . -name "*~" -o -name "#*#" -o -name "*.o")

mrproper: clean
	rm -rf $(GEN_BUILD_DIR)