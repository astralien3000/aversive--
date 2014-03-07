#ifndef POSITION_MANAGER_HPP
#define POSITION_MANAGER_HPP

#include <device/input.hpp>
#include <math/vect.hpp>
#include <base/integer.hpp>

#include <math.h>

class PositionManager : public Input<Vect<2, s32>> {
  typedef Vect<2, s32> PosVect;
  
 private:
  Input<Vect<2, s32>>& _odo;

  s32 _a_off = 0;

  double _x = 0;
  double _y = 0;

  s32 _last_dist = 0;

public:
  inline PositionManager(Input<Vect<2, s32>>& odo) : _odo(odo) {}

  inline PosVect getValue(void) {
    Vect<2, s32> ret;
    update();
    ret.coord(0) = (s32)_x;
    ret.coord(1) = (s32)_y;
    return ret;
  }

  inline s32 x(void) const {
    return _x;
  }

  inline s32 y(void) const {
    return _y;
  }

  inline s32 angle(void) const {
    return _odo.getValue().coord(0) + _a_off;
  }

  inline void setPosition(const PosVect& pos, s32 angle) {
    _x = (double)pos.coord(0);
    _y = (double)pos.coord(1);
    _a_off = angle - _odo.getValue().coord(1);
  }

  void update(void) {
    Vect<2, s32> da = _odo.getValue();

    s32 diff_d = da.coord(1) - _last_dist;

    double angle = da.coord(0) * 180.0 / 3.14;

    _x += ((double)diff_d * (double)cos(angle));
    _y += ((double)diff_d * (double)sin(angle));

    _last_dist = da.coord(1);
  }
};

#endif//POSITION_MANAGER_HPP
