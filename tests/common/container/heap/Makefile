CC=g++
CFLAGS=-Wall -Wextra --std=c++11 -g
LDFLAGS=-pthread

MODULE=container
CLASS=heap
EXEC=$(CLASS).elf

all: $(EXEC)

$(EXEC): main.cpp $(AVERSIVE_ROOT)/modules/$(MODULE)/include/$(MODULE)/$(CLASS).hpp
	@$(CC) $(CFLAGS) -I$(AVERSIVE_ROOT)/modules/base/include -I$(AVERSIVE_ROOT)/modules/$(MODULE)/include -o $@ $< $(LDFLAGS)

clean:
	@rm -rf *~ \#*\#

mrproper: clean
	@rm -rf $(EXEC)
