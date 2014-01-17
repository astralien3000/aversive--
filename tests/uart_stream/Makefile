AVERSIVE_BASE=../../

MMCU=atmega128

CXX=avr-g++
CXX_FLAGS=-Wall -L$(AVERSIVE_BASE)/build/avr -I$(AVERSIVE_BASE)/include/avr -mmcu=$(MMCU) -std=c++11 -fno-threadsafe-statics -O0 -D__STDC_LIMIT_MACROS 
CXX_LIBS=-laversive_$(MMCU) -Wl,-u,vfprintf -lprintf_flt

OBJCOPY=avr-objcopy

ELF=stream.elf
HEX=stream.hex
DEV=/dev/ttyUSB0

all: $(HEX)

load: $(HEX)
#	sudo avrdude -cwiring -p$(MMCU) -P $(DEV) -U flash:w:$(HEX) -D
	sudo avarice -j /dev/ttyUSB0 --erase --program -f $(HEX)

clean:
	rm -f $(ELF) $(HEX)

$(ELF): test_stream.cpp
	$(CXX) $(CXX_FLAGS) $^ -o $@ $(CXX_LIBS)

$(HEX): $(ELF)
	$(OBJCOPY) -O ihex $(ELF) $(HEX)
