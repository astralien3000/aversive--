CC=g++
CFLAGS=-Wall -Wextra --std=c++11 -DQT_CORE_LIB -I/usr/include/qt5 -I/usr/include/qt5/QtCore -fpic -g
LDFLAGS=-lQt5Core -lpthread

all: test_rds

test_rds: test_rds.o ../../../build/sasiae/libaversive.a
	@$(CC) $(CFLAGS) -I../../../include/sasiae -o $@ $< -L../../../build/sasiae -laversive $(LDFLAGS)

test_rds.o: 
	g++ -o test_rds.o test_rds.cpp -I../../../include/sasiae/ $(CFLAGS)


clean:
	@rm -rf *~ \#*\#

test: all
	@./test_rds

