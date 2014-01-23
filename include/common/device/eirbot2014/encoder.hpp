#ifndef ENCODER_HPP
#define ENCODER_HPP

#include <device/input_device.hpp>
#include "../../base/integer.hpp"

#ifndef ENCODER_PRIVATE_DATA
#define ENCODER_PRIVATE_DATA
#endif//ENCODER_PRIVATE_DATA

//! \brief An incremental encoder, used by Eirbot in 2014
//! \param ADDR : the address where to get the encoder value
/*! 

  This sensor is actually connected to a FPGA, which is viewed as an
  external memory by the microcontroller. The address is set by the
  user, so I hope you know how your FPGA works ;) !

*/
template<u32* ADDR>
class Encoder : public InputDevice<u32> {
public:
  inline Encoder(const char*);

  inline u32 getValue(void);

private:
  ENCODER_PRIVATE_DATA
};

#undef  ENCODER_PRIVATE_DATA

#endif//ENCODER_HPP
