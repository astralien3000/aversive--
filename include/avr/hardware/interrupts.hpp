#ifndef AVR_INTERRUPTS_HPP
#define AVR_INTERRUPTS_HPP

#include "../../common/hardware/interrupts.hpp"

inline void Interrupts::clear(void) {
  __asm__ __volatile__ ("CLI\n");
}

inline void Interrupts::set(void) {
  __asm__ __volatile__ ("SEI\n");
}

template<typename T> inline void Interrupts::lock(T& flag) {
  flag = SREG;
  Interrupts::clear();
}

template<typename T> inline void Interrupts::unlock(T& flag) {
  SREG = flag;
  Interrupts::set();
}

#endif//AVR_INTERRUPTS_HPP
