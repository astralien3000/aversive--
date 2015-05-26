CC=g++
CFLAGS=-Wall -Wextra --std=c++11 -g
LDFLAGS=-L$(AVERSIVE_ROOT)/build/sasiae_x86/lib -laversive_sasiae_x86

CLASS=world
DEP=$(CLASS).hpp shape.hpp point.hpp segment.hpp circle.hpp aabb.hpp triangle.hpp quadrilateral.hpp collision.hpp
EXEC=$(CLASS).elf

all: $(EXEC)

$(EXEC): main.cpp $(addprefix $(AVERSIVE_ROOT)/modules/geometry/include/geometry/,$(DEP)) $(AVERSIVE_ROOT)/build/sasiae_x86/lib/libaversive_sasiae_x86.a
	@$(CC) $(CFLAGS) -I$(AVERSIVE_ROOT)/modules/{base,geometry,math,container}/include -o $@ $< $(LDFLAGS)

clean:
	@rm -rf *~ \#*\#

mrproper: clean
	@rm -rf $(EXEC)
