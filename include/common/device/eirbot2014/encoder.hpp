#ifndef ENCODER_HPP
#define ENCODER_HPP

#include "../input_device.hpp"
#include "../../../base/integer.hpp"

//! \brief An incremental encoder, used by Eirbot in 2014
//! \param VALUE_ADDR : The address where to get the value fromthe FPGA
/*! 

  This sensor is actually connected to a FPGA, which is viewed as an
  external memory by the microcontroller. The address is set by the
  user, so I hope you know how your FPGA works ;) !

*/

template<u32* VALUE_ADDR = 0>
class Encoder : public InputDevice<u32> {
public:
  inline Encoder(const char*);

  inline u32& getValue(void);
}

#endif//ENCODER_HPP
