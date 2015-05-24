CC=g++
CFLAGS=-Wall -Wextra --std=c++11 -g

CLASS=alloc
EXEC=$(CLASS).elf

all: $(EXEC)

$(EXEC): main.cpp $(AVERSIVE_ROOT)/modules/base/include/base/_base_$(CLASS).hpp $(AVERSIVE_ROOT)/modules/sasiae/include/base/$(CLASS).hpp
	@$(CC) $(CFLAGS) -I$(AVERSIVE_ROOT)/build/sasiae_x86/include -o $@ $< -L$(AVERSIVE_ROOT)/build/sasiae_x86/lib -laversive_sasiae_x86

clean:
	@rm -rf *~ \#*\#

mrproper: clean
	@rm -rf $(EXEC)
