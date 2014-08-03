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
template void Timer<1>::init(void);

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
