CC=g++
CFLAGS=-Wall -Wextra --std=c++11 -g

CLASS=integer
EXEC=$(CLASS).elf

all: $(EXEC)

$(EXEC): main.cpp ../../../../include/common/base/$(CLASS).hpp
	@$(CC) $(CFLAGS) -I../../../../include/common -o $@ $<

clean:
	@rm -rf *~ \#*\#

mrproper: clean
	@rm -rf $(EXEC)
