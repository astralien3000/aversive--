#ifndef RDS_HPP
#define RDS_HPP


#include <device/stream/uart_stream.hpp>

//! \brief A complex sensor which gives the relative position of others robots
//! \param CHANNEL : uart channel where to get messages.
/*!
  This sensor can possibly return the position of all robots in a radius of 2 meters.
  The protocol is [number of robots] [position robot1] [position robot2] where
  position is a couple of ints.
  For example : 2 120 65 -20 30
*/

template<int CHANNEL>
class Rds : public UartStream<CHANNEL> {
  Rds(void);

  //! \param [CARTESIAN/POLAR] : how to get relative positions (default is CARTESIAN)
  void setMode(int mode);

  //! \brief Writes in tab the position of robots as : [number of robots] [position1] [position2] where a position is a couple (x, y) or (a, r); see setMode.
  void getPositions(int* tab);

}

#endif//RDS_HPP
