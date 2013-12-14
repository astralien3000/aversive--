export MMCU=atmega128
export CC=avr-g++
export CFLAGS=-Wall -Wextra --std=c++11 -mmcu=$(MMCU) -fno-threadsafe-statics
BUILD=../../build/atmega128
export BUILD_EXPORT=../../build/atmega128
INCLUDE=../../include/avr
export INCLUDE_EXPORT=$(INCLUDE)

LIB=$(BUILD)/libaversive_atmega128.a
SUB_DIRS= hardware # add the sub directory's names here

all: $(BUILD) build subdirs $(LIB)

# to build local sources
build: 

$(BUILD):
	mkdir $(BUILD)

$(BUILD)/%.o: %.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $@ -c $<

subdirs: 
	$(MAKE) -C $(SUB_DIRS)

$(LIB):	
	ar cr $(LIB) $?
