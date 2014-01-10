CC=g++
CFLAGS=-Wall -Wextra --std=c++11 -g
LDFLAGS= -lpthread

all: buffer

buffer: buffer.cpp ../../include/common/container/buffer.hpp
	@$(CC) $(CFLAGS) -I../../include/common -o $@ $< $(LDFLAGS)

clean:
	@rm -rf *~ \#*\#

test: all
	@./buffer 1073741824

mrproper: clean
	@rm -rf buffer
