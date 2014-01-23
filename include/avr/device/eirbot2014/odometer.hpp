#ifndef AVR_ODOMETER_HPP
#define AVR_ODOMETER_HPP

#define ODOMETER_PRIVATE_DATA				\
  LeftEncoder& _enc_l;					\
  RightEncoder& _enc_r;					\
  s32 _last_enc_l;					\
  s32 _last_enc_r;					\
  s32 _imp_per_cm;					\
  s32 _dist_enc_imp;					\
  s32 _dist;						\
  s32 _angle;


#include "../../../common/device/eirbot2014/odometer.hpp"

#include <device/stream/uart_stream.hpp>

template<class EL, class ER>
inline Odometer<EL, ER>::Odometer(const char* name, EL& el, ER& er) : 
  InputDevice<Vect<2, s32>>(name), 
    _enc_l(el), _enc_r(er), 
    _last_enc_l(0), _last_enc_r(0), 
    _imp_per_cm(1), _dist_enc_imp(1), 
    _dist(0), _angle(0) {}

template<class EL, class ER>
inline void Odometer<EL, ER>::setImpPerCm(s32 val) {
  _imp_per_cm = val;
}

template<class EL, class ER>
inline void Odometer<EL, ER>::setDistEncoders(s32 val) {
  _dist_enc_imp = _imp_per_cm * val;
}

template<class EL, class ER>
void Odometer<EL, ER>::update(void) {
  SafeInteger<s32> diff_l = s32(_enc_l.getValue()) - s32(_last_enc_l);
  SafeInteger<s32> diff_r = s32(_enc_r.getValue()) - s32(_last_enc_r);

  _dist += (s32)(diff_l + diff_r);
  _angle += (s32)(diff_l - diff_r);

  _last_enc_l = _enc_l.getValue();
  _last_enc_r = _enc_r.getValue();
}

template<class EL, class ER>
inline s32 Odometer<EL, ER>::distance(void) const {
  return (_dist / 2) / _imp_per_cm;
}

template<class EL, class ER>
inline s32 Odometer<EL, ER>::angle(void) const {
  return _angle / _dist_enc_imp;
}

template<class EL, class ER>
inline Vect<2, s32> Odometer<EL, ER>::getValue(void) {
  Vect<2, s32> ret;
  update();
  ret.coord(0) = distance();
  ret.coord(1) = angle();
  return ret;
}

#endif//AVR_ODOMETER_HPP
