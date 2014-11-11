/*
    Aversive++                                                           
    Copyright (C) 2014 Eirbot                                            
                                                                         
    This program is free software: you can redistribute it and/or modify 
    it under the terms of the GNU General Public License as published by 
    the Free Software Foundation, either version 3 of the License, or    
    (at your option) any later version.                                  
                                                                         
    This program is distributed in the hope that it will be useful,      
    but WITHOUT ANY WARRANTY; without even the implied warranty of       
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        
    GNU General Public License for more details.                         
                                                                         
    You should have received a copy of the GNU General Public License    
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef RDS_HPP
#define RDS_HPP


#include <device/device.hpp>
#include <device/input.hpp>
#include <math/vect.hpp>
#include <container/list.hpp>
#include <base/integer.hpp>
#include <device/stream/binary_stream.hpp>


#include <device/stream/binary_stream.hpp>

struct RdsPrivateData {
  BinaryStream &rds_io;
};

//////////////////////////////////////////////////////////////////

//! \brief A complex sensor which gives the relative position of others robots
/*!
  This sensor can possibly return the position of all robots in a 2-meter radius.
  The protocol is [nb of robots] [x_r1] [y_r1] [x_r2] [y_r2] ...
  For example : 2 120 65 -20 30 means 2 robots at (120, 65) and (-20, 30)
  The values returned depend on the choosen mode (cartesian or polar).
*/

class Rds : public Device, public Input<List<2, Vect<2, s32> > > {
private:
  List<2, Vect<2, s32> > _values;
  
public:
  enum Mode {
    CARTESIAN,
    POLAR
  };

public:
  //! \brief Constructor
  Rds(const char* name, BinaryStream& stream);

  //! \brief Default mode is CARTESIAN. 
  void setMode(Mode);

  //! \brief Return the position (x, y) (or (d, a) depending the mode) of the spceficied robot.
  List< 2, Vect<2, s32> > getValue(void);

  //! \brief Only used by the AVR (for the moment)
  void update(void);

private:
  RdsPrivateData _data;
};

//////////////////////////////////////////////////////////////////////////////

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


#endif//RDS_HPP
