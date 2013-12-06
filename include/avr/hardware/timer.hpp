#ifndef AVR_TIMER_HPP
#define AVR_TIMER_HPP

#include "../../common/hardware/timer.hpp"

////////////////////////////////////////////////////////
// DATA ////////////////////////////////////////////////
typedef void (InterruptFunc*)(void);

template<int ID> template<int EID>
struct Timer<ID>::Event<EID>::PrivateData {
  InterruptFunc func = 0;
};

template<int ID>
struct Timer<ID>::PrivateData {};

////////////////////////////////////////////////////////
// Timer ///////////////////////////////////////////////

template<int ID>
inline Timer<ID>::Timer() {}

template<int ID>
inline void Timer<ID>::init(void) {
  // Set Waveform Generator Mode to Normal
  // Set Prescaler to 0
  REG(timer<ID>::control) = 
    CFG(timer<ID>::control::wgm::normal) | 
    CFG(timer<ID>::control::prescaler::value<0>);
  
  // Set Counter to 0
  // ERROR !!! size can be more than 8 bits
  REG(timer<ID>::counter) = 0;
}

template<int ID> template<int PRESCALE>
inline void Timer<ID>::setPrescaler(void) {
  // Set to 0 all prescaler bits
  REG(timer<ID>::control) &= 
    ~CFG(timer<ID>::control::prescaler::disable);

  // Set prescaler value
  REG(timer<ID>::control) |= 
    CFG(timer<ID>::control::prescaler::value<PRESCALE>);
}

template<int ID> template<int EID>
inline void Timer<ID>::Event<EID>::start(void) {
  // Enable event interrupt bit
  REG(timer<ID>::imask) =
    CFG(timer<ID>::imask::match<0>);
}



#endif//AVR_TIMER_HPP
