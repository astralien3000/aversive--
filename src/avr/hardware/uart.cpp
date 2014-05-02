#include <hardware/uart.hpp>

#include "interrupt_bind.hpp"

template<int ID> Uart<ID>::Uart() {}

template Uart<0>::Uart();

#if defined (__AVR_ATmega128__)
MACRO_INTERRUPT_BIND(Uart<0>, recvEvent, USART0_RX_vect)
MACRO_INTERRUPT_BIND(Uart<0>, sendEvent, USART0_TX_vect)
MACRO_INTERRUPT_BIND(Uart<0>, emptyEvent, USART0_UDRE_vect)
#endif

#if defined (__AVR_ATmega2560__)
MACRO_INTERRUPT_BIND(Uart<0>, recvEvent, USART0_RX_vect)
MACRO_INTERRUPT_BIND(Uart<0>, sendEvent, USART0_TX_vect)
MACRO_INTERRUPT_BIND(Uart<0>, emptyEvent, USART0_UDRE_vect)
#endif

#if defined (__AVR_ATmega32__)
MACRO_INTERRUPT_BIND(Uart<0>, recvEvent, USART_RXC_vect)
MACRO_INTERRUPT_BIND(Uart<0>, sendEvent, USART_TXC_vect)
MACRO_INTERRUPT_BIND(Uart<0>, emptyEvent, USART_UDRE_vect)
#endif

