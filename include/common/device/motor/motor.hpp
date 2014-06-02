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

#ifndef MOTOR_HPP
#define MOTOR_HPP

#include <device/device.hpp>
#include <device/output.hpp>
#include <base/integer.hpp>

//! \brief A direct current motor
class Motor : public Device, public Output<s32> {
protected:
  bool _inverse;
  s32 _min;
  s32 _max;

  //! \brief Create a named motor
  //! \param name : the name of the device (used with sasiae)
  Motor(const char* name)
    : Device(name), _inverse(false) {
  }

public:
  //! \brief Send an command to the motor
  //! \warning The value is saturated if not in a valid interval
  virtual void setValue(s32) = 0;

  //! \brief Switch positive and negative command
  void inverse(void) {
    _inverse = !_inverse;
  }

  //! \brief Set the allowed maximum command
  inline void setMaxCommand(s32 val) {
    _max = val;
  }

  //! \brief Set the allowed minimum command
  inline void setMinCommand(s32 val) {
    _min = val;
  }

  //! \brief Return the allowed maximum command
  inline s32 getMaxCommand(void) {
    return _max;
  }

  //! \brief Return the allowed minimum command
  inline s32 getMinCommand(void) {
    return _min;
  }
};

#endif//MOTOR_HPP

