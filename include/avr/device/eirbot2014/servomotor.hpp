#ifndef AVR_SERVOMOTOR_HPP
#define AVR_SERVOMOTOR_HPP

#include "../../../common/device/eirbot2014/servomotor.hpp"

template<s32* ADDR>
inline Servomotor<ADDR>::Servomotor(const char* name) : OutputDevice<s32>(name) {}

template<s32* ADDR>
inline void Servomotor<ADDR>::setValue(s32 val) {
  (*ADDR) = val;
}

#endif//AVR_SERVOMOTOR_HPP
