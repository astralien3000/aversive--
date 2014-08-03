CC=g++
CFLAGS=-Wall -Wextra --std=c++11 -g
LDFLAGS=-pthread

CLASS=buffer

all: $(CLASS)

$(CLASS): main.cpp ../../../../include/common/container/$(CLASS).hpp
	@$(CC) $(CFLAGS) -I../../../../include/common -o $@ $< $(LDFLAGS)

clean:
	@rm -rf *~ \#*\#

mrproper: clean
	@rm -rf $(CLASS)
