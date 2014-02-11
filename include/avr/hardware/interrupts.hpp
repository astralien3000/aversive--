#ifndef AVR_INTERRUPTS_HPP
#define AVR_INTERRUPTS_HPP

#include "../../common/hardware/interrupts.hpp"

inline void Interrupts::init(void) {
  unlock();
}

inline void Interrupts::stop(void) {
  lock();
}

inline void Interrupts::lock(void) {
  if(!counter) {
    clear();
  }
  counter++;
}

inline void Interrupts::unlock(void) {
  if(counter) {
    counter--;
  }
  if(!counter) {
    set();
  }
}

inline void Interrupts::clear(void) {
  __asm__ __volatile__ ("CLI\n");
}

inline void Interrupts::set(void) {
  __asm__ __volatile__ ("SEI\n");
}

#endif//AVR_INTERRUPTS_HPP
