#ifndef INTERRUPT_BIND_HPP
#define INTERRUPT_BIND_HPP

#include <avr/interrupt.h>

#define MACRO_INTERRUPT_BIND(hardware, method, vect)		\
  ISR(vect) {							\
    uint8_t flags = SREG;					\
    hardware::method().execFunction();				\
    SREG = flags;						\
  }

#endif//INTERRUPT_BIND_HPP
