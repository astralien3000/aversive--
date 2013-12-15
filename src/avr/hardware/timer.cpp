#include <hardware/timer.hpp>

#include <avr/interrupt.h>

#define MACRO_INTERRUPT_BIND(timer, comp, ev)				\
  ISR(TIMER##timer##_COMP##comp##_vect, ISR_NAKED) {			\
    uint8_t flags = SREG;						\
    Timer<timer>::instance().comparEvent<ev>().execFunction();		\
    SREG = flags;							\
    reti();								\
  }

MACRO_INTERRUPT_BIND(0,,0)
MACRO_INTERRUPT_BIND(1,A,0)
MACRO_INTERRUPT_BIND(1,B,1)
#if defined (__AVR_ATmega128__)
MACRO_INTERRUPT_BIND(1,C,2)
#endif
