CC=g++
CFLAGS=-Wall -Wextra --std=c++11 -DQT_CORE_LIB -I/usr/include/qt5 -I/usr/include/qt5/QtCore -fpic -g
LDFLAGS=-L../../../build/sasiae -laversive -lQt5Core -lpthread

all: test_rds

test_rds: test_rds.o
	@$(CC) $(CFLAGS) -I../../../include/sasiae -o $@ $< -L../../../build/sasiae -laversive $(LDFLAGS)

test_rds.o: 
	g++ -c -o test_rds.o test_rds.cpp -I../../../include/sasiae/ $(CFLAGS)


clean:
	@rm -rf *~ *.o \#*\#

test: all
	@./test_rds

