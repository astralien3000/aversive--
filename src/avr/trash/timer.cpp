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

#include <base/types.hpp>
#include <hardware/timer.hpp>
#include <hardware/interrupts.hpp>

#include <base/static_container.hpp>

#include "../config/atmega32.hpp"

////////////////////////////////////////////////////////
// DATA ////////////////////////////////////////////////

template<int ID> template<int EID>
class Timer<ID>::Event<EID>::PrivateData {
public:
  InterruptFunc func = 0;
};

template<int ID>
class Timer<ID>::PrivateData {
public:
  typedef EnumerateStaticContainer<0, AVR::Timer<ID>::EVENTS, Timer::Event> EventList;
  EventList events;
};

////////////////////////////////////////////////////////
// INTERRUPTION FUNCS //////////////////////////////////

#include <avr/interrupt.h>

#define MACRO_INTERRUPT_BIND(timer, comp, ev)				\
  ISR(TIMER##timer##_COMP##comp##_vect, ISR_NAKED) {			\
    uint8_t flags = SREG;						\
    Timer<timer>::Event<ev>& evt = Timer<timer>::instance().event<ev>(); \
    if(evt.activated())							\
      evt.exec();							\
    SREG = flags;							\
    reti();								\
  }

MACRO_INTERRUPT_BIND(0,,0)
MACRO_INTERRUPT_BIND(1,A,0)
MACRO_INTERRUPT_BIND(1,B,1)
#if defined (__AVR_ATmega128__)
MACRO_INTERRUPT_BIND(1,C,2)
#endif

////////////////////////////////////////////////////////
// EVENT FUNC HELPER ///////////////////////////////////

// Used to disable and enable interrupts, but finally the user need to control that
// Now just check some compilation variables...
template<int ID, int EID, bool TYPE_OK = true>
struct TimerFuncHelper {
  inline TimerFuncHelper(void) {
    // Check type
    static_assert(TYPE_OK, "ERROR : Wrong type used during register manipulation");

    // Check if event exist
    static_assert(EID < AVR::Timer<ID>::EVENTS, "ERROR : Invalid Event ID");
  }
};

////////////////////////////////////////////////////////

template<int ID>
inline Timer<ID>::Timer() {
  
}

template<int ID>
inline void Timer<ID>::init(void) {
  TimerFuncHelper<ID,0> helper();

  // Set Waveform Generator Mode to Normal
  StaticListOperation<
    Assign,
    typename AVR::Timer<ID>::Control, 
    typename AVR::Timer<ID>::WGM::Normal
    >::exec();

  // Set Prescaler to 0
  this->setPrescaler<0>();
  
  // Set Counter to 0
  this->counter<typename Integer<AVR::Timer<ID>::SIZE>::Unsigned>() = 0;
}

template<int ID> template<typename T>
inline T& Timer<ID>::counter(void) {
  TimerFuncHelper<ID,0,AVR::Timer<ID>::SIZE == sizeof(T)*8> helper;

  // Set counter value
  return REG<AVR::Timer<ID>::SIZE>(AVR::Timer<ID>::Counter::ELEM);
}

template<int ID> template<int PRESCALE>
inline void Timer<ID>::setPrescaler(void) {
  TimerFuncHelper<ID,0> helper;

  // Set to 0 all prescaler bits
  StaticListOperation<
    BitNotAndAssign,
    typename AVR::Timer<ID>::Control,
    // TODO : replace by MASK !!
    typename AVR::Timer<ID>::template Prescaler<PRESCALE>::Config
    >::exec();

  // Set prescaler value
  StaticListOperation<
    BitOrAssign,
    typename AVR::Timer<ID>::Control, 
    typename AVR::Timer<ID>::template Prescaler<PRESCALE>::Config
    >::exec();
}

template<int ID> template<int EID>
inline void Timer<ID>::Event<EID>::start(void) {
  TimerFuncHelper<ID,EID> helper;

  // Enable event interrupt bit
  StaticListOperation<
    BitOrAssign,
    typename AVR::TimerInterrupt::Mask, 
    typename AVR::Timer<ID>::template InterruptMask<EID>::Match
    >::exec();
}

template<int ID> template<int EID>
inline void Timer<ID>::Event<EID>::stop(void) {
  TimerFuncHelper<ID,EID> helper;

  // Disable event interrupt bit
  StaticListOperation<
    BitNotAndAssign,
    typename AVR::TimerInterrupt::Mask, 
    typename AVR::Timer<ID>::template InterruptMask<EID>::Match
    >::exec();
}

template<int ID> template<int EID> template<typename Callable> 
inline void Timer<ID>::Event<EID>::set(Callable func) {
  TimerFuncHelper<ID,EID> helper;

  this->data.func = static_cast<InterruptFunc>(func);
}

template<int ID> template<int EID> template<typename T>
inline void Timer<ID>::Event<EID>::setComparator(T val) {
  TimerFuncHelper<ID,EID,AVR::Timer<ID>::SIZE == sizeof(T)*8> helper;

  REG<AVR::Timer<ID>::SIZE>(StaticListIterator<typename AVR::Timer<ID>::Compare, EID>::VALUE) = val;
}

template<int ID> template<int EID>
inline void Timer<ID>::Event<EID>::exec(void) {
  this->data.func();
}

template<int ID> template<int EID>
inline bool Timer<ID>::Event<EID>::activated(void) {
  return this->data.func != 0;
}

template<int ID> template<int EID>
inline Timer<ID>::Event<EID>& Timer<ID>::event() {
  return StaticContainerIterator<typename Timer<ID>::PrivateData::EventList, EID>::value(this->data.events);
}
