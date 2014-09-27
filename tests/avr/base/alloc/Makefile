CC=g++
CFLAGS=-Wall -Wextra --std=c++11 -g

CLASS=alloc
EXEC=$(CLASS).elf

all: $(EXEC)

$(EXEC): tester.cpp ../../../../include/common/base/$(CLASS).hpp ../../../../include/avr/base/$(CLASS).hpp
	@$(CC) $(CFLAGS) -I../../../../include/sasiae -I../../../../../aversive--serial/include -o $@ $< -L../../../../build -laversive_sasiae -L../../../../../aversive--serial/build -laversive_serial
	$(MAKE) -f Makefile2 atmega2560
	./deploy.sh

clean:
	@rm -rf *~ \#*\#

mrproper: clean
	@rm -rf $(EXEC) robot_atmega2560.hex
	@$(MAKE) -sf Makefile2 $@
