#ifndef SASIAE_SERVOMOTOR_HPP
#define SASIAE_SERVOMOTOR_HPP

#include "../../../common/device/eirbot2014/servomotor.hpp"

template<s32* ADDR>
Servomotor<ADDR>::Servomotor(const char* name) : OutputDevice(name) {}

template<s32* ADDR>
void Servomotor<ADDR>::setValue(s32 val) {
  OutputDevice::setValue(*ADDR = val);
}


#endif//SASIAE_SERVOMOTOR_HPP
