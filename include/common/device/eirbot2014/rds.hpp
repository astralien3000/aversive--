#ifndef RDS_HPP
#define RDS_HPP


#include <device/io_device.hpp>
#include <base/array.hpp>
#include <stdint.h>

//! \brief A complex sensor which gives the relative position of others robots
//! \param CHANNEL : uart channel to get the messages from.
/*!
  This sensor can possibly return the position of all robots in a 2-meter radius.
  The protocol is [nb of robots] [x_r1 y_r1] [x_r2 y_r2] ...
  For example : 2 120 65 -20 30 means 2 robots at (120, 65) and (-20, 30)
  The values returned depend on the choosen mode (cartesian or polar).
*/

template<int CHANNEL>
class Rds : public IODevice<Array<13, int16_t> > {
private:
  Array<13, int16_t> _values;

public:
  Rds(void);

  //! \bried Default mode is CARTESIAN. 
  void setModeCartesian(void);
  void setModePolar(void);

  //! \brief Return the position of robots as : [number of robots] [position1] [position2] where a position is a couple (x, y) or (a, r); see setMode{Cartesian,Polar}().
  const Array<13, int16_t>& getValue(void) const;

};


#endif//RDS_HPP
