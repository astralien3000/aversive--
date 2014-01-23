#ifndef ODOMETER_HPP
#define ODOMETER_HPP

#include "../input_device.hpp"
#include "../../math/vect.hpp"
#include "../../base/integer.hpp"

#ifndef ODOMETER_PRIVATE_DATA
#define ODOMETER_PRIVATE_DATA
#endif//ODOMETER_PRIVATE_DATA

template<class LeftGP2, class RightGP2>
class Odometer : public InputDevice<Vect<2, s32>> {
public:
  inline Odometer(const char*, LeftGP2&, RightGP2&);

  inline Vect<2, s32> getValue(void);

  inline s32 distance(void) const;
  inline s32 angle(void) const;

  inline void setImpPerCm(s32);
  inline void setDistGP2s(s32);

  void update(void);
private:
  ODOMETER_PRIVATE_DATA
};

namespace OdometerMaker {
  template<class LeftGP2, class RightGP2>
  inline Odometer<LeftGP2, RightGP2> make(const char* name, LeftGP2& le, RightGP2& re) {
    return Odometer<LeftGP2, RightGP2>(name, le, re);
  }
}

#undef  ODOMETER_PRIVATE_DATA

#endif//ODOMETER_HPP
