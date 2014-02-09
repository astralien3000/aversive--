export CC=avr-g++
export CFLAGS=-Wall -Wextra --std=c++11 -mmcu=$(MMCU) -fno-threadsafe-statics -D__STDC_LIMIT_MACROS -O3
BUILD=../../build/$(MMCU)
export BUILD_EXPORT=$(BUILD)
INCLUDE=../../include/avr
export INCLUDE_EXPORT=$(INCLUDE)

export LIBNAME=libaversive_$(MMCU)

LIB=$(BUILD)/../$(LIBNAME).a
SUB_DIRS= hardware # add the sub directory's names here

OBJS = aversive # add object to compile

all: $(BUILD) build $(addsuffix .d,$(SUB_DIRS)) common $(LIB)

# to build local sources
build: $(addprefix $(BUILD)/,$(addsuffix .o,$(OBJS)))

$(BUILD):
	mkdir -p $@

$(BUILD)/%.o: %.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $@ -c $<

hardware.d: 
	$(MAKE) -C $(@:.d=)

$(LIB):
	avr-ar r $(LIB) $(BUILD)/*.o

common:
	$(MAKE) -C ../common
