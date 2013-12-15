CC=g++
CFLAGS=-Wall -Wextra --std=c++11 -DQT_CORE_LIB -DQT_NETWORK_LIB -I/usr/include/qt5 -I/usr/include/qt5/QtCore -I/usr/include/qt5/QtNetwork -fpic -I../../include/sasiae -g
LDFLAGS=-L../../build/sasiae -laversive -lQt5Core -lQt5Network -lpthread

all: client server

client: client.cpp ../../build/sasiae/libaversive.a
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ $< $(LDFLAGS)

server: server.cpp ../../build/sasiae/libaversive.a
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ $< $(LDFLAGS)