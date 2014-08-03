CC=g++
CFLAGS=-Wall -Wextra --std=c++11 -g

CLASS=heap

all: $(CLASS)

$(CLASS): main.cpp ../../../../include/common/container/$(CLASS).hpp
	@$(CC) $(CFLAGS) -I../../../../include/common -o $@ $<

clean:
	@rm -rf *~ \#*\#

mrproper: clean
	@rm -rf $(CLASS)
