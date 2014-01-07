CC=g++
CFLAGS=-Wall -Wextra --std=c++11 -DQT_CORE_LIB -DQT_NETWORK_LIB -I/usr/include/qt5 -I/usr/include/qt5/QtCore -fpic -I../../include/sasiae -g
LDFLAGS=-L../../build/sasiae -laversive -lQt5Core -lpthread

all: client

client: client.cpp ../../build/sasiae/libaversive.a
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ $< $(LDFLAGS)

clean:
	@rm -rf *~ \#*\#

mrproper: clean
	@rm -rf client