#ifndef AVR_SERVOMOTOR_HPP
#define AVR_SERVOMOTOR_HPP

#include "../../../common/device/eirbot2014/servomotor.hpp"

inline Servomotor::Servomotor(const char* name) : OutputDevice<u32>(name) {}

inline void Servomotor::setValue(u32 val) {
  OutputDevice<u32>::setValue(val);
}

#endif//AVR_SERVOMOTOR_HPP
