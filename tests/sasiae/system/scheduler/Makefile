SASIAE_TESTS=$(AVERSIVE_ROOT)/tests/sasiae

CC=g++
CFLAGS=-Wall -Wextra --std=c++11 -DQT_CORE_LIB -fpic -g
LDFLAGS=-L$(AVERSIVE_ROOT)/build/sasiae_x86/lib -laversive_sasiae_x86 -lQt5Core -lpthread
INCLUDE=-I$(AVERSIVE_ROOT)/build/sasiae_x86/include -I/usr/include/qt5 -I/usr/include/qt5/QtCore
EXECS=client.elf server.elf

all: $(EXECS)

client.elf: client.cpp $(AVERSIVE_ROOT)/build/sasiae_x86/lib/libaversive_sasiae_x86.a
	@$(CC) $(CFLAGS) $(INCLUDE) -o $@ $< $(LDFLAGS)

server.elf: server.cpp $(SASIAE_TESTS)/util.o
	@$(CC) $(CFLAGS) $(INCLUDE) -o $@ $^ $(LDFLAGS)

$(SASIAE_TESTS)/%.o: $(SASIAE_TESTS)/%.cpp $(SASIAE_TESTS)/%.hpp
	@$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $< $(LDFLAGS)

clean:
	@rm -rf *~ \#*\#

mrproper: clean
	@rm -rf $(EXECS) $(SASIAE_TESTS)/util.o
