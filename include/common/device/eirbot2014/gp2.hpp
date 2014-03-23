#ifndef GP2_HPP
#define GP2_HPP


#include <device/device.hpp>
#include <device/input.hpp>
#include <base/integer.hpp>


//! \brief An infrared sensor, used by Eirbot in 2014
//! \param ADDR : the address where to get the GP2 value
/*! 

 This sensor has two working ways. It can be digital or analogical.
 Most of the Eirbot's GP2 are analogical and an ADC treatment must be applied.

*/
template<u32* ADDR>
class GP2 : public Device, public Input<u32> {
public:
  GP2(const char*);

  u32 getValue(void);
};

#endif//GP2_HPP
