/*
    Aversive++                                                           
    Copyright (C) 2014 Eirbot                                            
                                                                         
    This program is free software: you can redistribute it and/or modify 
    it under the terms of the GNU General Public License as published by 
    the Free Software Foundation, either version 3 of the License, or    
    (at your option) any later version.                                  
                                                                         
    This program is distributed in the hope that it will be useful,      
    but WITHOUT ANY WARRANTY; without even the implied warranty of       
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        
    GNU General Public License for more details.                         
                                                                         
    You should have received a copy of the GNU General Public License    
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#if defined _AVERSIVE_OLD_SUPPORT

#include <hardware/uart.hpp>

#include "interrupt_bind.hpp"

template<int ID>
void Uart<ID>::init(void) {
  setBaudrate(9600);
  setNBits<8>();
  
  // 1 Stop bit
  REG(uart<ID>::control) |=
    CFG(uart<ID>::control::stopbit::template value<1>);
  
  // Enable RX and TX
  REG(uart<ID>::control) |=
    CFG(uart<ID>::control::enable::send)|
    CFG(uart<ID>::control::enable::recv);
}

template void Uart<0>::init(void);

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


#endif
