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

#ifndef AX12_HPP
#define AX12_HPP

#include <device/input.hpp>
#include <device/output.hpp>
#include <device/device.hpp>

#include <base/integer.hpp>

//! \brief A digital servomotor, used by Eirbot in 2014
/*!

  This actuator is very specific because he works as an extern card so
  you can communicate with him. It is based on UART communication
  that's why you should read UartStream instructions.

*/
class AX12: public Device, Input<u16>, Output<u16> {
private:
  AX12PrivateData data;

public:
  enum WorkingMode{WHEEL,JOIN};
  enum ComMode{POSITION,SPEED,TORQUE};

public:
  AX12(char*);
  ~AX12();

  u16 getValue();
  void setValue(u16);

  u16 getAngle();
  u16 getSpeed();
  u16 getTorque();

  void setAngle(u16);
  void setSpeed(u16);

  void setRecvMode(ComMode);
  void setSendMode(WorkingMode);

  void setAngleMax(u16, u16);
  void setTorqueMax(u16);
};

#endif//AX12_HPP
