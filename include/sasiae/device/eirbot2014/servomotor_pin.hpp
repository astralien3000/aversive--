#ifndef SASIAE_SERVOMOTOR_PIN_HPP
#define SASIAE_SERVOMOTOR_PIN_HPP

#include "../../../common/device/eirbot2014/servomotor_pin.hpp"

template<u8 PORT, u8 PIN>
ServomotorPin<PORT, PIN>::ServomotorPin(const char* name) : Servomotor(name) {}

template<u8 PORT, u8 PIN>
void ServomotorPin<PORT, PIN>::setValue(u32 val) {
  Servomotor::setValue(val);
}

#endif//SASIAE_SERVOMOTOR_PIN_HPP
