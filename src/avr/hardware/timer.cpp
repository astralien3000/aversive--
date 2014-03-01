#include <hardware/timer.hpp>

template<int ID> Timer<ID>::Timer() {}

template Timer<0>::Timer();
template Timer<1>::Timer();

#include "interrupt_bind.hpp"

MACRO_INTERRUPT_BIND(Timer<0>, overflowEvent, TIMER0_OVF_vect)
MACRO_INTERRUPT_BIND(Timer<1>, overflowEvent, TIMER1_OVF_vect)

MACRO_INTERRUPT_BIND(Timer<1>, comparEvent<0>, TIMER1_COMPA_vect)
MACRO_INTERRUPT_BIND(Timer<1>, comparEvent<1>, TIMER1_COMPB_vect)

#if defined (__AVR_ATmega128__)
MACRO_INTERRUPT_BIND(Timer<1>, comparEvent<2>, TIMER1_COMPC_vect)
#endif

#if defined (__AVR_ATmega2560__)
MACRO_INTERRUPT_BIND(Timer<0>, comparEvent<0>, TIMER0_COMPA_vect)
#else
MACRO_INTERRUPT_BIND(Timer<0>, comparEvent<0>, TIMER0_COMP_vect)
#endif
