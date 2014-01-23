#ifndef ODOMETER_HPP
#define ODOMETER_HPP

#include "../input_device.hpp"
#include "../../math/vect.hpp"
#include "../../base/integer.hpp"

#ifndef ODOMETER_PRIVATE_DATA
#define ODOMETER_PRIVATE_DATA
#endif//ODOMETER_PRIVATE_DATA

template<class LeftEncoder, class RightEncoder>
class Odometer : public InputDevice<Vect<2, s32>> {
public:
  inline Odometer(const char*, LeftEncoder&, RightEncoder&);

  inline Vect<2, s32> getValue(void);

  inline s32 distance(void) const;
  inline s32 angle(void) const;

  inline void setImpPerCm(s32);
  inline void setDistEncoders(s32);

  void update(void);
private:
  ODOMETER_PRIVATE_DATA
};

namespace OdometerMaker {
  template<class LeftEncoder, class RightEncoder>
  inline Odometer<LeftEncoder, RightEncoder> make(const char* name, LeftEncoder& le, RightEncoder& re) {
    return Odometer<LeftEncoder, RightEncoder>(name, le, re);
  }
}

#undef  ODOMETER_PRIVATE_DATA

#endif//ODOMETER_HPP
