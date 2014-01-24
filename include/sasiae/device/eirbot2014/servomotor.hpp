#ifndef SASIAE_SERVOMOTOR_HPP
#define SASIAE_SERVOMOTOR_HPP

#include "../../../common/device/eirbot2014/servomotor.hpp"

Servomotor::Servomotor(const char* name) : OutputDevice<u32>(name) {}

void Servomotor::setValue(u32 val) {
  OutputDevice<u32>::setValue(val);
}


#endif//SASIAE_SERVOMOTOR_HPP
