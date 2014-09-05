AVERSIVE_ROOT=../../../../..
SASIAE_TESTS=$(AVERSIVE_ROOT)/tests/sasiae

CC=g++
CFLAGS=-Wall -Wextra --std=c++11 -DQT_CORE_LIB -fpic -g
LDFLAGS=-L$(AVERSIVE_ROOT)/build -laversive_sasiae -lQt5Core -lpthread
INCLUDE=-I$(AVERSIVE_ROOT)/include/sasiae -I/usr/include/qt5 -I/usr/include/qt5/QtCore
EXECS=client.elf server.elf

all: $(EXECS)

client.elf: client.cpp $(AVERSIVE_ROOT)/build/libaversive_sasiae.a
	@$(CC) $(CFLAGS) $(INCLUDE) -o $@ $< $(LDFLAGS)

server.elf: server.cpp $(SASIAE_TESTS)/util.o
	@$(CC) $(CFLAGS) $(INCLUDE) -o $@ $^ $(LDFLAGS)

$(SASIAE_TESTS)/%.o: $(SASIAE_TESTS)/%.cpp $(SASIAE_TESTS)/%.hpp
	@$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $< $(LDFLAGS)

clean:
	@rm -rf *~ \#*\#

mrproper: clean
	@rm -rf $(EXECS) $(SASIAE_TESTS)/util.o
