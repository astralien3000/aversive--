#include <hardware/timer.hpp>

template<int ID>
void Timer<ID>::init(void) {
  // Set Waveform Generator Mode to Normal
  // Set Prescaler to 0
  REG(timer<ID>::control) = 
    CFG(timer<ID>::control::wgm::normal) |
      CFG(timer<ID>::control::prescaler::template value<0>);
  
  // Set Counter to 0
  REG(timer<ID>::counter) = VAL(timer<ID>::counter, 0);
}


template void Timer<0>::init(void);

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
