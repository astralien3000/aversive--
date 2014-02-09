export CC=g++
export CFLAGS=-Wall -Wextra --std=c++11 -fno-threadsafe-statics -D__STDC_LIMIT_MACROS -O3 -DQT_CORE_LIB -I/usr/include/qt5 -I/usr/include/qt5/QtCore -fPIE -g
BUILD=../../build/sasiae
export BUILD_EXPORT=$(BUILD)
INCLUDE=../../include/sasiae
export INCLUDE_EXPORT=$(INCLUDE)
LIB=$(BUILD)/../libaversive_sasiae.a
OBJ=aversive client_thread

SUB_DIRS=system # add the sub directory's names here

all: $(BUILD) build $(addsuffix .d,$(SUB_DIRS)) common $(LIB)

# to build local sources
build: $(addprefix $(BUILD)/,$(addsuffix .o,$(OBJ)))

$(BUILD):
	mkdir -p $@

$(BUILD)/aversive.o: $(INCLUDE)/aversive.hpp
$(BUILD)/client_thread.o: $(INCLUDE)/client_thread.hpp $(INCLUDE)/base/singleton.hpp
$(BUILD)/%.o: %.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $@ -c $<

system.d:
	$(MAKE) -C $(@:.d=)

$(LIB):
	ar r $(LIB) $(BUILD)/*.o

common:
	$(MAKE) -C ../common
