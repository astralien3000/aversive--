AVERSIVE_BASE=../../

CXX=g++
CXX_FLAGS=-Wall -L$(AVERSIVE_BASE)/build -I$(AVERSIVE_BASE)/include/sasiae -std=c++11 -fno-threadsafe-statics -O1 -D__STDC_LIMIT_MACROS
CXX_LIBS=-laversive_sasiae

ELF=test.elf

all: $(ELF)

clean:
	rm -f $(ELF) $(HEX) *~

$(ELF): main.cpp
	$(CXX) $(CXX_FLAGS) $^ -o $@ $(CXX_LIBS)

