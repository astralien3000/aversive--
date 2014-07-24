CC=g++
CFLAGS=-Wall -Wextra --std=c++11 -g
LDFLAGS=-pthread

all: buffer

buffer: main.cpp ../../include/common/container/buffer.hpp
	@$(CC) $(CFLAGS) -I../../include/common -o $@ $< $(LDFLAGS)

clean:
	@rm -rf *~ \#*\#

test: all
	@./buffer

mrproper: clean
	@rm -rf buffer
