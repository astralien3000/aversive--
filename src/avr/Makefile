export MMCU=atmega128
export CC=avr-g++
export CFLAGS=-Wall -Wextra --std=c++11 -mmcu=$(MMCU) -fno-threadsafe-statics
BUILD=../../build/avr
export BUILD_EXPORT=../../build/avr
INCLUDE=../../include/avr
export INCLUDE_EXPORT=$(INCLUDE)

LIB=$(BUILD)/libaversive_$(MMCU).a
SUB_DIRS= hardware # add the sub directory's names here

OBJS = # add object to compile

all: $(BUILD) $(BUILD)/$(MMCU) build subdirs $(LIB)

# to build local sources
build: $(addprefix $(BUILD)/$(MMCU)/,$(addsuffix .o,$(OBJS)))

$(BUILD):
$(BUILD)/$(MMCU):
	mkdir $@

$(BUILD)/$(MMCU)/%.o: %.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $@ -c $<

subdirs: 
	$(MAKE) -C $(SUB_DIRS)

$(LIB):	$(addprefix $(BUILD)/$(MMCU)/,$(addsuffix .o,$(OBJS)))
	ar cr $(LIB) $?
