#ifndef ODOMETER_HPP
#define ODOMETER_HPP

#include <device/input.hpp>
#include <device/device.hpp>
#include <math/vect.hpp>
#include <base/integer.hpp>

class Odometer : public Input<Vect<2, s32>> {
 private:
  Input<s32>& _enc_l;
  Input<s32>& _enc_r;
  s32 _last_enc_l;
  s32 _last_enc_r;
  s32 _imp_per_cm;
  s32 _dist_enc_imp;
  s32 _dist;
  s32 _angle;
  
 public:
  inline Odometer(Input<s32>& el, Input<s32>& er) : 
    _enc_l(el), _enc_r(er), 
    _last_enc_l(0), _last_enc_r(0), 
    _imp_per_cm(1), _dist_enc_imp(1), 
    _dist(0), _angle(0) {}
  
  inline Vect<2, s32> getValue(void) {
    Vect<2, s32> ret;
    update();
    ret.coord(0) = distance();
    ret.coord(1) = angle();
    return ret;
  }

  inline s32 distance(void) const {
    return (_dist / 2) / _imp_per_cm;
  }

  inline s32 angle(void) const {
    return _angle / _dist_enc_imp;
  }

  inline void setImpPerCm(s32 val) {
    _imp_per_cm = val;
  }

  inline void setDistEncoders(s32 val) {
    _dist_enc_imp = _imp_per_cm * val;
  }

  void update(void) {
    SafeInteger<s32> diff_l = s32(_enc_l.getValue()) - s32(_last_enc_l);
    SafeInteger<s32> diff_r = s32(_enc_r.getValue()) - s32(_last_enc_r);

    _dist += (s32)(diff_l + diff_r);
    _angle += (s32)(diff_l - diff_r);

    _last_enc_l = _enc_l.getValue();
    _last_enc_r = _enc_r.getValue();
  }

};

#undef  ODOMETER_PRIVATE_DATA

#endif//ODOMETER_HPP
