CC=g++
CFLAGS=-Wall -Wextra --std=c++11 -g
LDFLAGS=

all: list

list: main.cpp ../../include/common/container/list.hpp
	@$(CC) $(CFLAGS) -I../../include/common -o $@ $< $(LDFLAGS)

clean:
	@rm -rf *~ \#*\#

test: all
	@./list

mrproper: clean
	@rm -rf list
