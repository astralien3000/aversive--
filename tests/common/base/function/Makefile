CC=g++
CFLAGS=-Wall -Wextra --std=c++11 -g

all: function

function: main.cpp ../../../../include/common/base/function.hpp
	@$(CC) $(CFLAGS) -I../../../../include/common -o $@ $<

clean:
	@rm -rf *~ \#*\#

mrproper: clean
	@rm -rf function
