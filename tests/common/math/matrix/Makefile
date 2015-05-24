CC=g++
CFLAGS=-Wall -Wextra --std=c++11 -g
LDFLAGS=-L$(AVERSIVE_ROOT)/build/sasiae_x86/lib -laversive_sasiae_x86

CLASS=matrix
EXEC=$(CLASS).elf

all: $(EXEC)

$(EXEC): main.cpp $(AVERSIVE_ROOT)/modules/math/include/math/$(CLASS).hpp $(AVERSIVE_ROOT)/build/sasiae_x86/lib/libaversive_sasiae_x86.a
	@$(CC) $(CFLAGS) -I$(AVERSIVE_ROOT)/modules/{base,math}/include -o $@ $< $(LDFLAGS)

clean:
	@rm -rf *~ \#*\#

mrproper: clean
	@rm -rf $(EXEC)
