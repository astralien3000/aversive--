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
