#include <hardware/uart.hpp>

template<int ID> Uart<ID>::Uart() {}

template Uart<0>::Uart();

#include <avr/interrupt.h>

#define MACRO_INTERRUPT_BIND(uart, method, vect)			\
  ISR(vect, ISR_NAKED) {						\
    uint8_t flags = SREG;						\
    Uart<uart>::instance().method().execFunction();			\
    SREG = flags;							\
    reti();								\
  }

MACRO_INTERRUPT_BIND(0, recvEvent, USART0_RX_vect)
MACRO_INTERRUPT_BIND(0, sendEvent, USART0_TX_vect)
MACRO_INTERRUPT_BIND(0, emptyEvent, USART0_UDRE_vect)
