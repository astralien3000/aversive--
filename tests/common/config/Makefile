CC=g++
CFLAGS=-Wall -Wextra --std=c++11 -g
LDFLAGS=-L../../../build -laversive_sasiae

CLASS=config

all: $(CLASS)

$(CLASS): main.cpp ../../../include/common/$(CLASS).hpp ../../../build/libaversive_sasiae.a
	@$(CC) $(CFLAGS) -I../../../include/common -o $@ $< $(LDFLAGS) -Wl,--defsym=_ZN8Aversive6Config13__PARAM_DUMMYE=42

clean:
	@rm -rf *~ \#*\#

mrproper: clean
	@rm -rf $(CLASS)
