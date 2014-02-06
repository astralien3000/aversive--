#ifndef ENCODER_HPP
#define ENCODER_HPP

#include <device/input_device.hpp>
#include "../../base/integer.hpp"

//! \brief An incremental encoder, used by Eirbot in 2014
//! \param ADDR : the address where to get the encoder value
/*! 

  This sensor is actually connected to a FPGA, which is viewed as an
  external memory by the microcontroller. The address is set by the
  user, so I hope you know how your FPGA works ;) !

*/
template<typename T>
class Encoder : public InputDevice<T> {
public:
  inline Encoder(const char*, T*);

  inline T getValue(void);

private:
  T* _addr;
};

#endif//ENCODER_HPP
