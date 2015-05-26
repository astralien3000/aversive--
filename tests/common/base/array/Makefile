CC=g++
CFLAGS=-Wall -Wextra --std=c++11 -g

MODULE=base
CLASS=array
EXEC=$(CLASS).elf

all: $(EXEC)

$(EXEC): main.cpp $(AVERSIVE_ROOT)/modules/$(MODULE)/include/$(MODULE)/$(CLASS).hpp
	@$(CC) $(CFLAGS) -I$(AVERSIVE_ROOT)/modules/$(MODULE)/include/ -o $@ $<

clean:
	@rm -rf *~ \#*\#

mrproper: clean
	@rm -rf $(EXEC)
