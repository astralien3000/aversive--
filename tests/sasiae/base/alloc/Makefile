CC=g++
CFLAGS=-Wall -Wextra --std=c++11 -g

CLASS=alloc
EXEC=$(CLASS).elf

all: $(EXEC)

$(EXEC): main.cpp ../../../../include/common/base/$(CLASS).hpp ../../../../include/sasiae/base/$(CLASS).hpp
	@$(CC) $(CFLAGS) -I../../../../include/sasiae/ -o $@ $< -L../../../../build -laversive_sasiae

clean:
	@rm -rf *~ \#*\#

mrproper: clean
	@rm -rf $(EXEC)
