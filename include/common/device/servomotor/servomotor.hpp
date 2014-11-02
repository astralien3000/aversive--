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

#ifndef SERVOMOTOR_HPP
#define SERVOMOTOR_HPP

#include <device/device.hpp>
#include <device/output.hpp>
#include <base/integer.hpp>

//! \brief A servomotor INTERFACE, used by Eirbot in 2014. Can not be used (see ServomotorFpga or ServomotorPin).
class Servomotor : public Device, public Output<u32> {
protected:
  //! \brief Protected Constructor
  Servomotor(const char*);

public:
  //! \brief Send a command to the servomotor
  virtual void setValue(u32) = 0;

private:
  u32 _min;
  u32 _max;

public:
  //! \brief Set the allowed maximum command
  inline void setMaxCommand(u32 val) {
    _max = val;
  }

  //! \brief Set the allowed minimum command
  inline void setMinCommand(u32 val) {
    _min = val;
  }

  //! \brief Return the allowed maximum command
  inline u32 getMaxCommand(void) {
    return _max;
  }

  //! \brief Return the allowed minimum command
  inline u32 getMinCommand(void) {
    return _min;
  }
};

#endif//SERVOMOTOR_HPP

