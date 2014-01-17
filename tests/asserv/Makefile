AVERSIVE_BASE=/home/astralien3000/Bureau/aversive++

CXX=avr-g++
CXX_FLAGS=-Wall -L$(AVERSIVE_BASE)/build/avr -I$(AVERSIVE_BASE)/include/avr -mmcu=atmega128 -std=c++11 -fno-threadsafe-statics -O3
CXX_LIBS=-laversive_atmega128

OBJCOPY=avr-objcopy

ELF=driver.elf
HEX=driver.hex
DEV=/dev/ttyUSB0

all: $(HEX)

load: $(HEX)
	sudo avarice -j /dev/ttyUSB0 --erase --program -f $(HEX)

clean:
	rm -f $(ELF) $(HEX) *~

$(ELF): main.cpp
	$(CXX) $(CXX_FLAGS) $^ -o $@ $(CXX_LIBS)

$(HEX): $(ELF)
	$(OBJCOPY) -O ihex $(ELF) $(HEX)