
#include <hardware/timer.hpp>
#include <hardware/interrupts.hpp>
#include <maths/saturate.hpp>
#include <base/types.hpp>

typedef Timer<0> Timer0;

////////////////

// This port correponds to the "-W 0x20,-" command line option.
#define special_output_port (*((volatile char *)0x20))

// This port correponds to the "-R 0x22,-" command line option.
#define special_input_port  (*((volatile char *)0x22))

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

#include "impl/hardware/timer.cpp"
#include "impl/hardware/interrupts.cpp"

int main(int argc, char* argv[]) {
  Timer0& timer = Timer0::instance();
  timer.init();

  
  Timer0::Event<0>& evt = timer.event<0>();
  evt.set([](void){ 
      debug_puts("A\n");
      Timer0::instance().counter<u8>() = 0;
    });
  
  evt.setComparator<u8>(50);
  timer.setPrescaler<32>();
  evt.start();

  Interrupts::set();

  int i = 0;
  while(1) {
    debug_puts("i");
    i++;
    if(i == 40) {
      debug_puts("li\n");
      i = 0;
    }
    
  }

  Interrupts::clear();
  
  return 0;
}

