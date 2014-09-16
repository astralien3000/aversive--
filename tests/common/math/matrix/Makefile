CC=g++
CFLAGS=-Wall -Wextra --std=c++11 -g
LDFLAGS=-L../../../../build -laversive_sasiae

CLASS=matrix
EXEC=$(CLASS).elf

all: $(EXEC)

$(EXEC): main.cpp ../../../../include/common/math/$(CLASS).hpp ../../../../build/libaversive_sasiae.a
	@$(CC) $(CFLAGS) -I../../../../include/common -o $@ $< $(LDFLAGS)

clean:
	@rm -rf *~ \#*\#

mrproper: clean
	@rm -rf $(EXEC)
