#ifndef RDS_HPP
#define RDS_HPP


#include <device/input_device.hpp>
#include <math/vect.hpp>
#include <stdint.h>

//! \brief A complex sensor which gives the relative position of others robots
/*!
  This sensor can possibly return the position of all robots in a 2-meter radius.
  The protocol is [nb of robots] [x_r1] [y_r1] [x_r2] [y_r2] ...
  For example : 2 120 65 -20 30 means 2 robots at (120, 65) and (-20, 30)
  The values returned depend on the choosen mode (cartesian or polar).
*/

class Rds : public InputDevice<Vect<6, Vect<2, int16_t> > > {
private:
  uint8_t _nb;
  Vect<6, Vect<2, int16_t> > _pos;

public:
  Rds(const char* name);

  //! \bried Default mode is CARTESIAN. 
  void setModeCartesian(void);
  void setModePolar(void);

  //! \brief Return the position (x, y) (or (d, a) depending the mode) of the spceficied robot.
  const Vect<2, int16_t>& getPosition(uint8_t index) const;

  //! \brief Return the number of robots seen by the RDS.
  uint8_t robotsNumber(void) const;
};


#endif//RDS_HPP
