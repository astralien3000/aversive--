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

#ifndef GP2_HPP
#define GP2_HPP


#include <device/device.hpp>
#include <device/input.hpp>
#include <base/integer.hpp>


//! \brief An infrared sensor, used by Eirbot in 2014
//! \param ID : the ADC mask
//! \param REG : the returned value of the ADC
/*!

  This sensor has two working ways. It can be digital or analogical.
  Most of the Eirbot's GP2 are analogical and an ADC treatment must be
  applied.

*/
template<u8 ID>
class GP2 : public Device, public Input<u16> {
public:
  GP2(const char*);

  u16 getValue(void);

private:
  u16 _last_val;
};

#endif//GP2_HPP
