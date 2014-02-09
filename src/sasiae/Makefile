export CC=g++
export CFLAGS=-Wall -Wextra --std=c++11 -fno-threadsafe-statics -D__STDC_LIMIT_MACROS -O3 -DQT_CORE_LIB -DQT_NETWORK_LIB -I/usr/include/qt5 -I/usr/include/qt5/QtCore -I/usr/include/qt5/QtNetwork -fPIE -g
BUILD=../../build/sasiae
export BUILD_EXPORT=../../build/sasiae
INCLUDE=../../include/sasiae
export INCLUDE_EXPORT=$(INCLUDE)

export LIBNAME=libaversive

LIB=$(BUILD)/$(LIBNAME).a
SUB_DIRS= # add the sub directory's names here

OBJS = aversive client_thread # add object to compile

all: $(BUILD) $(BUILD) build $(addsuffix .d,$(SUB_DIRS)) common $(LIB)

# to build local sources
build: $(addprefix $(BUILD)/,$(addsuffix .o,$(OBJS)))

$(BUILD):
$(BUILD)/$(MMCU):
	mkdir $@

$(BUILD)/%.o: %.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $@ -c $<

hardware.d: 
	$(MAKE) -C $(@:.d=)

$(LIB):
	ar r $(LIB) $(BUILD)/*.o

common:
	$(MAKE) -C ../common
