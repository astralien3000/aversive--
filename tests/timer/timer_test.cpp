
#include <hardware/timer.hpp>
#include <hardware/interrupts.hpp>
#include <base/integer.hpp>

typedef Timer<0> Timer0;

////////////////

// This port correponds to the "-W 0x20,-" command line option.
#define special_output_port (*((volatile char *)0xFF))

// This port correponds to the "-R 0x22,-" command line option.
#define special_input_port  (*((volatile char *)0xFA))

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
  Timer0& timer = Timer0::instance();
  timer.init();

  Timer0::ComparEvent<0>& evt = timer.comparEvent<0>();
  evt.setFunction([](void){ 
      debug_puts("A\n");
      Timer0::instance().setCounter(0);
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
      debug_puts("mmm\n");
      i = 0;
    }
    
  }

  Interrupts::clear();

  return 0;
}

