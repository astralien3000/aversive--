CC=g++
CFLAGS=-Wall -Wextra --std=c++11 -g
LDFLAGS=

all: queue

queue: main.cpp ../../include/common/container/queue.hpp
	@$(CC) $(CFLAGS) -I../../include/common -o $@ $< $(LDFLAGS)

clean:
	@rm -rf *~ \#*\#

test: all
	@./queue

mrproper: clean
	@rm -rf queue
