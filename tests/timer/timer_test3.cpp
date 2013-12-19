#include <hardware/timer.hpp>
#include <hardware/interrupts.hpp>
#include <base/integer.hpp>
#include <stdio.h>

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

void debug_puts_int(u8 i) {
  char BUF[128];
  sprintf(BUF, "%d", i);
  const char *c;
  for(c = BUF; *c; c++) {
    special_output_port = *c;
  }
}

void debug_puts_counter(void) {
  debug_puts_int((u8)REG(timer<0>::counter));
}

////////////////

#include <avr/io.h>
#include <avr/interrupt.h>

// #define MACRO_OVERFLOW_INTERRUPT_BIND(timer)				\
// ISR(TIMER##timer##_OVF_vect, ISR_NAKED) { \
//   debug_puts("TEST\n");\
//   Timer<timer>::instance().overflowEvent().execFunction();	\
// }\

// MACRO_OVERFLOW_INTERRUPT_BIND(0)

int main(int argc, char* argv[]) {
  Timer0& timer = Timer0::instance();
  timer.init();

  Timer0::OverflowEvent& evt = timer.overflowEvent();
  evt.setFunction([](void){ 
      debug_puts("Victoire\n");
      Timer0::instance().setCounter(0);
    });
  

  timer.setPrescaler<32>();
  evt.start();

  TIMSK = (1 << TOIE0);
  
  Interrupts::set();
  
  int i = 0;
  while(1) {
    debug_puts_counter();
    debug_puts("\n");
    i++;
  }

  Interrupts::clear();

  return 0;
}

