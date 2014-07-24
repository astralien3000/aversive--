AVERSIVE_ROOT=../..

CC=g++
CFLAGS=-Wall -Wextra --std=c++11 -DQT_CORE_LIB -fpic -g
LDFLAGS=-L$(AVERSIVE_ROOT)/build -laversive_sasiae -lQt5Core -lpthread
INCLUDE=-I$(AVERSIVE_ROOT)/include/sasiae -I/usr/include/qt5 -I/usr/include/qt5/QtCore

all: world

world: main.cpp
	@$(CC) $(CFLAGS) $(INCLUDE) -o $@ $< $(LDFLAGS)

clean:
	@rm -rf *~ \#*\#

test: world
	@./world

mrproper: clean
	@rm -rf world
