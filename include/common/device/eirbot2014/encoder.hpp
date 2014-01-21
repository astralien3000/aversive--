#ifndef GP2_HPP
#define GP2_HPP

#include <device/input_device.hpp>
#include "../../base/integer.hpp"


//! \brief An incremental GP2, used by Eirbot in 2014
//! \param ADDR : the address where to get the GP2 value
/*! 

  This sensor is actually connected to a FPGA, which is viewed as an
  external memory by the microcontroller. The address is set by the
  user, so I hope you know how your FPGA works ;) !

*/
template<u32* ADDR>
class GP2 : public InputDevice<u32> {
public:
  GP2(const char*);

  u32 getValue(void);
};

#endif//GP2_HPP
