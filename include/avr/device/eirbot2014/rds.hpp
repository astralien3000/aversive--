#ifndef AVR_RDS_HPP
#define AVR_RDS_HPP

#include <device/stream/binary_stream.hpp>

struct RdsPrivateData {
  BinaryStream &rds_io;
};

#include "../../../common/device/eirbot2014/rds.hpp"

inline Rds::Rds(const char* name, BinaryStream& stream) : Device(name), _data{ stream } {}

inline void Rds::setMode(Mode m) {
  (void) m;
  /*
    WARNING

    To be implemented if you wish to be able to change the mode (between CARTESIAN and POLAR)
   */
}

inline List<2, Vect<2, s32> > Rds::getValue(void) {
  return _values;
}

inline void Rds::update(void) {
  u8 n;
  u8 d, a;
  _data.rds_io << 'p';
  _data.rds_io >> n;

  _values.flush();
  for(u8 i = 0 ; i < n ; i++) {
    Vect<2, s32> v;
    _data.rds_io >> a;
    _data.rds_io >> d;
    v.coord(0) = d;
    v.coord(1) = a * 2;
    _values.append(v);
  }
}

#endif//AVR_RDS_HPP
