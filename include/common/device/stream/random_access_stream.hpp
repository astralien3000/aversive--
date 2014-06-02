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

#ifndef RANDOM_ACCESS_STREAM
#define RANDOM_ACCESS_STREAM

#include <device/stream/stream.hpp>

//! \class RandomAccessStream random_access_stream.hpp <device/stream/random_access_device.hpp>
//! \brief Abstract random access stream.
class RandomAccessStream : public Stream {
private:
  //! \brief The current position of the stream's reader head.
  volatile u16 _cursor = 0;
  
public:
  //! \brief Default constructor.
  inline RandomAccessStream(void)
    : Stream() {
  }
  
  //! \brief Copy constructor.
  //! \param s : the stream to copy.
  inline RandomAccessStream(const RandomAccessStream& s)
    : Stream(s), _cursor(s._cursor) {
  }
  
  //! \brief Place the cursor at a given position.
  //! \param pos : the new cursor's position.
  inline void seek(u16 pos) {
    _cursor = pos;
  }
  
  //! \brief Move the cursor by a given offset.
  //! \param offset : the offset to move the cursor with.
  inline void move(s16 offset) {
    _cursor += offset;
  }
  
  //! \brief Return the current cursor's position.
  //! \return The cursor's position.
  inline u16 cursor(void) const {
    return _cursor;
  }
};

#endif//RANDOM_ACCESS_STREAM
