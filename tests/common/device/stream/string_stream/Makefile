CC=g++
CFLAGS=-Wall -Wextra --std=c++11 -g

CLASS=string_stream
EXEC=$(CLASS).elf

all: $(EXEC)

$(EXEC): main.cpp ../../../../../include/common/device/stream/$(CLASS).hpp
	@$(CC) $(CFLAGS) -I../../../../../include/common/ -o $@ $< -L../../../../../build -laversive_sasiae

clean:
	@rm -rf *~ \#*\#

mrproper: clean
	@rm -rf $(EXEC)
