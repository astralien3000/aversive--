CC=g++
CFLAGS=-Wall -Wextra --std=c++11 -g

CLASS=heap
EXEC=$(CLASS).elf

all: $(EXEC)

$(EXEC): main.cpp ../../../../include/common/container/$(CLASS).hpp
	@$(CC) $(CFLAGS) -I../../../../include/common -o $@ $<

clean:
	@rm -rf *~ \#*\#

mrproper: clean
	@rm -rf $(EXEC)
