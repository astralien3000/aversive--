#ifndef AVR_SERVOMOTOR_HPP
#define AVR_SERVOMOTOR_HPP

#include "../../../common/device/servomotor/servomotor.hpp"

inline Servomotor::Servomotor(const char* name)
  : Device(name) {
}

inline void Servomotor::setValue(u32 val) {
  (void)val;
}

#endif//AVR_SERVOMOTOR_HPP
