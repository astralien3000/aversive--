CC=g++
CFLAGS=-Wall -Wextra --std=c++11 -g
LDFLAGS=-L../../../../build -laversive_sasiae

CLASS=world
DEP=$(CLASS).hpp shape.hpp point.hpp segment.hpp circle.hpp aabb.hpp triangle.hpp quadrilateral.hpp collision.hpp
EXEC=$(CLASS).elf

all: $(EXEC)

$(EXEC): main.cpp $(addprefix ../../../../include/common/geometry/,$(DEP)) ../../../../build/libaversive_sasiae.a
	@$(CC) $(CFLAGS) -I../../../../include/common -o $@ $< $(LDFLAGS)

clean:
	@rm -rf *~ \#*\#

mrproper: clean
	@rm -rf $(EXEC)
