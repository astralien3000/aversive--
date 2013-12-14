#ifndef AVR_TIMER_HPP
#define AVR_TIMER_HPP

#include "../../common/hardware/timer.hpp"
#include "architecture.hpp"

////////////////////////////////////////////////////////
// DATA ////////////////////////////////////////////////
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
    CFG(timer<ID>::control::prescaler::_VALUE(0));
  
  // Set Counter to 0
  REG(timer<ID>::counter) = VAL(timer<ID>::counter, 0);
}

template<int ID> template<typename T>
inline void Timer<ID>::setCounter(const T& val) {
  REG(timer<0>::counter) = 
    VAL(timer<0>::counter, val);
}

template<int ID> template<int PRESCALE>
inline void Timer<ID>::setPrescaler(void) {
  // Set to 0 all prescaler bits
  REG(timer<0>::control) &= 
    ~CFG(timer<0>::control::prescaler::disable);

  // Set prescaler value
  REG(timer<0>::control) |= 
    CFG(timer<0>::control::prescaler::value<PRESCALE>);
}

template<int ID> template<int EID>
inline Timer<ID>::ComparEvent<EID>& Timer<ID>::comparEvent(void) {
  static Timer<ID>::ComparEvent<EID> evt;
  return evt;
}

////////////////////////////////////////////////////////
// Timer::ComparEvent //////////////////////////////////

template<int ID> template<int EID>
inline Timer<ID>::ComparEvent<EID>::ComparEvent(void) : HardwareEvent() {}

// Warning ! interrupts need to be sat with Interrupts::set()
template<int ID> template<int EID>
inline void Timer<ID>::ComparEvent<EID>::start(void) {
  // Enable event interrupt bit
  REG(timer<0>::imask) |=
    CFG(timer<0>::imask::match<0>);
}

template<int ID> template<int EID>
inline void Timer<ID>::ComparEvent<EID>::stop(void) {
  // Disable event interrupt bit
  REG(timer<0>::imask) &=
    ~CFG(timer<0>::imask::match<0>);
}

template<int ID> template<int EID> template<typename T>
inline void Timer<ID>::ComparEvent<EID>::setComparator(const T& val) {
  // Disable event interrupt bit
  REG(timer<0>::compare<0>) =
    VAL(timer<0>::compare<0>, val);
}

#endif//AVR_TIMER_HPP
