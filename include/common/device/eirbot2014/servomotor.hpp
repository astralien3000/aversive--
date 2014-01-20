#ifndef SERVOMOTOR_HPP
#define SERVOMOTOR_HPP

#include <device/output_device.hpp>
#include "../../base/integer.hpp"

//! \brief A servomotor, used by Eirbot in 2014
//! \param ADDR : the address where to set the motor pwm

template<s32* ADDR>
class Servomotor : public OutputDevice<s32> {
public:
  Servomotor(const char*);

  void setValue(s32);
};

#endif//SERVOMOTOR_HPP

