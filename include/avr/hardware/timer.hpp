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
inline void Timer<ID>::init(void) {
  // Set Waveform Generator Mode to Normal
  // Set Prescaler to 0
  REG(timer<ID>::control) = 
    CFG(timer<ID>::control::wgm::normal) |
    CFG(timer<ID>::control::prescaler::template value<0>);
  
  // Set Counter to 0
  REG(timer<ID>::counter) = VAL(timer<ID>::counter, 0);
}

template<int ID> template<typename T>
inline const T& Timer<ID>::counter(void) {
  return REG(timer<ID>::counter);
}

template<int ID> template<typename T>
inline void Timer<ID>::setCounter(const T& val) {
  REG(timer<ID>::counter) = 
    VAL(timer<ID>::counter, val);
}

template<int ID> template<int PRESCALE>
inline void Timer<ID>::setPrescaler(void) {
  // Set to ID all prescaler bits
  REG(timer<ID>::control) &= 
    ~CFG(timer<ID>::control::prescaler::disable);

  // Set prescaler value
  REG(timer<ID>::control) |= 
    CFG(timer<ID>::control::prescaler::template value<PRESCALE>);
}

template<int ID> template<int EID>
inline Timer<ID>::ComparEvent<EID>& Timer<ID>::comparEvent(void) {
  static Timer<ID>::ComparEvent<EID> evt;
  return evt;
}

template<int ID>
inline typename Timer<ID>::OverflowEvent& Timer<ID>::overflowEvent(void) {
  static Timer<ID>::OverflowEvent evt;
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
  REG(timer<ID>::imask) |=
    CFG(timer<ID>::imask::template match<EID>);
}

template<int ID> template<int EID>
inline void Timer<ID>::ComparEvent<EID>::stop(void) {
  // Disable event interrupt bit
  REG(timer<ID>::imask) &=
    ~CFG(timer<ID>::imask::template match<EID>);
}

template<int ID> template<int EID> template<typename T>
inline void Timer<ID>::ComparEvent<EID>::setComparator(const T& val) {
  // Disable event interrupt bit
  REG(timer<ID>::template compare<EID>) =
    VAL(timer<ID>::template compare<EID>, val);
}

////////////////////////////////////////////////////////
// Timer::Overflow /////////////////////////////////////

// Warning ! interrupts need to be sat with Interrupts::set()
template<int ID>
inline void Timer<ID>::OverflowEvent::start(void) {
  // Enable event interrupt bit
  REG(timer<ID>::imask) |=
    CFG(timer<ID>::imask::overflow);
}

template<int ID>
inline void Timer<ID>::OverflowEvent::stop(void) {
  // Disable event interrupt bit
  REG(timer<ID>::imask) &=
    ~CFG(timer<ID>::imask::overflow);
}

#endif//AVR_TIMER_HPP
