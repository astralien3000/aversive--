CC=g++
CFLAGS=-Wall -Wextra --std=c++11 -g

all: bool_ref

bool_ref: main.cpp ../../../../include/common/base/bool_ref.hpp
	@$(CC) $(CFLAGS) -I../../../../include/common -o $@ $<

clean:
	@rm -rf *~ \#*\#

mrproper: clean
	@rm -rf bool_ref
