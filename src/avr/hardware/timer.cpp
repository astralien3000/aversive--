#include <hardware/timer.hpp>

template<int ID> Timer<ID>::Timer() {}

template Timer<0>::Timer();
template Timer<1>::Timer();

#include <avr/interrupt.h>

#define MACRO_INTERRUPT_BIND(timer, comp, ev)				\
  ISR(TIMER##timer##_COMP##comp##_vect) {				\
    uint8_t flags = SREG;						\
    Timer<timer>::instance().comparEvent<ev>().execFunction();		\
    SREG = flags;							\
  }


#define MACRO_OVERFLOW_INTERRUPT_BIND(timer)				\
  ISR(TIMER##timer##_OVF_vect) {					\
    uint8_t flags = SREG;						\
    Timer<timer>::instance().overflowEvent().execFunction();		\
    SREG = flags;							\
  }

MACRO_OVERFLOW_INTERRUPT_BIND(0)
MACRO_OVERFLOW_INTERRUPT_BIND(1)

MACRO_INTERRUPT_BIND(1,A,0)
MACRO_INTERRUPT_BIND(1,B,1)
#if defined (__AVR_ATmega128__)
MACRO_INTERRUPT_BIND(1,C,2)
#endif

#if defined (__AVR_ATmega2560__)
MACRO_INTERRUPT_BIND(0,A,0)
#else
MACRO_INTERRUPT_BIND(0,,0)
#endif
