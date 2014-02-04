AVERSIVE_BASE=../../

MMCU=atmega128

CXX=avr-g++
CXX_FLAGS=-Wall -L$(AVERSIVE_BASE)/build/avr -I$(AVERSIVE_BASE)/include/avr -mmcu=$(MMCU) -std=c++11 -fno-threadsafe-statics -O1 -D__STDC_LIMIT_MACROS
CXX_LIBS=-laversive_$(MMCU)

OBJCOPY=avr-objcopy

ELF=driver.elf
HEX=driver.hex
DEV=/dev/ttyUSB0

all: $(HEX)

load: $(HEX)
	sudo avarice -j /dev/ttyUSB0 --erase --program -f $(HEX)

clean:
	rm -f $(ELF) $(HEX) *~

$(ELF): test_asserv.cpp
	$(CXX) $(CXX_FLAGS) $^ -o $@ $(CXX_LIBS)

$(HEX): $(ELF)
	$(OBJCOPY) -O ihex $(ELF) $(HEX)
