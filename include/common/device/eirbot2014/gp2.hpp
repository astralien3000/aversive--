#ifndef GP2_HPP
#define GP2_HPP


#include <device/device.hpp>
#include <device/input.hpp>
#include <base/integer.hpp>


//! \brief An infrared sensor, used by Eirbot in 2014
//! \param ID : the ADC mask
//! \param REG : the returned value of the ADC
/*!

  This sensor has two working ways. It can be digital or analogical.
  Most of the Eirbot's GP2 are analogical and an ADC treatment must be
  applied.

*/
template<u8 ID>
class GP2 : public Device, public Input<u16> {
public:
  GP2(const char*);

  u16 getValue(void);

private:
  u16 _last_val;
};

#endif//GP2_HPP
