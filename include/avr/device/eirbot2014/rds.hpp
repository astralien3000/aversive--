#ifndef AVR_RDS_HPP
#define AVR_RDS_HPP

#include <device/stream/stream.hpp>

struct RdsPrivateData {
  Stream &rds_io;
};

#include "../../../common/device/eirbot2014/rds.hpp"

Rds::Rds(const char* name, Stream &stream) : Device(name), _data{ stream } {}

void Rds::setMode(Mode m) {
  (void) m;
  /*
    WARNING

    To be implemented if you wish to be able to change the mode (between CARTESIAN and POLAR)
   */
}

List<2, Vect<2, s32> > Rds::getValue(void) {
  return _values;
}

void Rds::update(void) {
  u8 n;
  s32 d, a;
  _data.rds_io << 'p';
  _data.rds_io >> n;

  _values.flush();
  for(u8 i = 0 ; i < n ; i++) {
    Vect<2, s32> v;
    _data.rds_io >> d;
    _data.rds_io >> a;
    v.coord(0) = d;
    v.coord(1) = a;
    _values.append(v);
  }
}

#endif//AVR_RDS_HPP
