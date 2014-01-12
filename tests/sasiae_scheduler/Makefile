CC=g++
CFLAGS=-Wall -Wextra --std=c++11 -DQT_CORE_LIB -I/usr/include/qt5 -I/usr/include/qt5/QtCore -fpic -g
LDFLAGS=-lQt5Core -lpthread

all: client

client: client.cpp ../../build/sasiae/libaversive.a
	@$(CC) $(CFLAGS) -I../../include/sasiae -o $@ $< -L../../build/sasiae -laversive $(LDFLAGS)

clean:
	@rm -rf *~ \#*\#

test: all
	@./server

mrproper: clean
	@rm -rf client server
