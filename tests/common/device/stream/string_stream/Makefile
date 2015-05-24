CC=g++
CFLAGS=-Wall -Wextra --std=c++11 -g

CLASS=string_stream
EXEC=$(CLASS).elf

all: $(EXEC)

$(EXEC): main.cpp $(AVERSIVE_ROOT)/modules/stream/include/stream/$(CLASS).hpp
	@$(CC) $(CFLAGS) -I$(AVERSIVE_ROOT)/modules/{base,device,container,stream}/include -o $@ $< -L$(AVERSIVE_ROOT)/build/sasiae_x86/lib -laversive_sasiae_x86

clean:
	@rm -rf *~ \#*\#

mrproper: clean
	@rm -rf $(EXEC)
