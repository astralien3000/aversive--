CC=g++
CFLAGS=-Wall -Wextra --std=c++11 -g
LDFLAGS=

all: heap

heap: heap.cpp ../../include/common/container/heap.hpp
	@$(CC) $(CFLAGS) -I../../include/common -o $@ $< $(LDFLAGS)

clean:
	@rm -rf *~ \#*\#

test: all
	@./heap

mrproper: clean
	@rm -rf heap
