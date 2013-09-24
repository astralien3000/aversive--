
#include <hardware/timer.hpp>
#include <hardware/interrupts.hpp>
#include <maths/saturate.hpp>

typedef TimerHandler<0> Timer0;
//typedef TimerHandler<1> Timer0;
typedef InterruptsHandler Interrupts;

////////////////

// This port correponds to the "-W 0x20,-" command line option.
#define special_output_port (*((volatile char *)0xFA))

// This port correponds to the "-R 0x22,-" command line option.
#define special_input_port  (*((volatile char *)0xFF))

// Poll the specified string out the debug port.
void debug_puts(const char *str) {
  const char *c;
  for(c = str; *c; c++) {
    special_output_port = *c;
  }
}

////////////////

#include <avr/io.h>
#include <avr/interrupt.h>

int main(int argc, char* argv[]) {
  Timer0::init();
  Timer0::Event<0>::set([](void){ 
      debug_puts("A\n");
      Timer0::counter<u8>() = 0;
    });
  
  Timer0::Event<0>::setComparator((u8)100);
  Timer0::setPrescaler<1024>();
  Timer0::setPrescaler<0>();
  Timer0::Event<0>::start();
  Timer0::Event<0>::stop();
  Timer0::Event<0>::start();

  Interrupts::set();

  int i = 0;
  while(1) {
    debug_puts("l");
    i++;
    if(i == 20) {
      debug_puts("l\n");
    }
    
  }

  Interrupts::clear();
  return 0;
}

#include "timer.cpp"
#include "interrupts.cpp"
