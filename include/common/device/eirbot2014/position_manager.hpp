#ifndef POSITION_MANAGER_HPP
#define POSITION_MANAGER_HPP

#include "../input_device.hpp"
#include "../../math/vect.hpp"
#include "../../base/integer.hpp"

#ifndef POSITION_MANAGER_PRIVATE_DATA
#define POSITION_MANAGER_PRIVATE_DATA
#endif//POSITION_MANAGER_PRIVATE_DATA

template<typename Odometer>
class PositionManager : public InputDevice<Vect<2, s32>> {
  typedef Vect<2, s32> PosVect;

public:
  inline PositionManager(const char*, Odometer&);

  inline PosVect getValue(void);

  inline s32 x(void) const;
  inline s32 y(void) const;
  inline s32 angle(void) const;

  inline void setOffset(const PosVect&, s32);
  inline void setCurrentPosition(const PosVect&, s32);
private:
  POSITION_MANAGER_PRIVATE_DATA
};

#undef  POSITION_MANAGER_PRIVATE_DATA

#endif//POSITION_MANAGER_HPP
