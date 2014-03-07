AVERSIVE_BASE=../../

MMCU=atmega2560

OPTI=-O3
CXX=avr-g++
CXX_FLAGS=-Wall -L$(AVERSIVE_BASE)/build -I$(AVERSIVE_BASE)/include/avr -mmcu=$(MMCU) -std=c++11 -fno-threadsafe-statics $(OPTI) -D__STDC_LIMIT_MACROS 
CXX_LIBS=-laversive_$(MMCU)

OBJCOPY=avr-objcopy

ELF=sched.elf
HEX=sched.hex
DEV=/dev/ttyACM0

all: $(HEX)

asm: test_sched.cpp
	$(CXX) $(CXX_FLAGS) -S $^ -o test_sched.asm $(CXX_LIBS)

load: $(HEX)
	sudo avrdude -cwiring -p$(MMCU) -P $(DEV) -U flash:w:$(HEX) -D
#	sudo avarice -j /dev/ttyUSB0 --erase --program -f $(HEX)

clean:
	rm -f $(ELF) $(HEX)

$(ELF): test_sched.cpp
	$(CXX) $(CXX_FLAGS) $^ -o $@ $(CXX_LIBS)

$(HEX): $(ELF)
	$(OBJCOPY) -O ihex $(ELF) $(HEX)
