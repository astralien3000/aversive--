CC=g++
CFLAGS=-Wall -Wextra --std=c++11 -g
LDFLAGS=

all: stack

stack: main.cpp ../../include/common/container/stack.hpp
	@$(CC) $(CFLAGS) -I../../include/common -o $@ $< $(LDFLAGS)

clean:
	@rm -rf *~ \#*\#

test: all
	@./stack

mrproper: clean
	@rm -rf stack
