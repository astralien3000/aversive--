#include <hardware/interrupts.hpp>

inline void InterruptsHandler::clear(void) {
  __asm__ __volatile__ ("CLI\n");
}

inline void InterruptsHandler::set(void) {
  __asm__ __volatile__ ("SEI\n");
}

inline void InterruptsHandler::lock(ArchiHandler::RegType& flag) {
  flag = SREG;
  InterruptsHandler::clear();
}

inline void InterruptsHandler::unlock(ArchiHandler::RegType& flag) {
  SREG = flag;
  InterruptsHandler::set();
}
