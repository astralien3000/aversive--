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

#ifndef ENCODER_HPP
#define ENCODER_HPP

#include <device/device.hpp>
#include <device/input.hpp>
#include <base/integer.hpp>

//! \brief An incremental encoder, used by Eirbot in 2014
//! \param T the FPGA register type
/*! 

  This sensor is actually connected to a FPGA, which is viewed as an
  external memory by the microcontroller. The address is set by the
  user, so I hope you know how your FPGA works ;) !

*/
template<typename T>
class Encoder : public Device, public Input<s32> {
public:
  //! \brief Create a named encoder
  //! \param name : the name of the device (used with sasiae)
  //! \param addr : the FPGA register address
  Encoder(const char* name, T* addr);

  //! \brief Get the number of impulsion of the incremental encoder
  /*!
    
    If the "wheel" turn in some way, the number of impulsion
    increases. If it turn in the other way, the number of impulsion
    decresases.
    
   */
  s32 getValue(void);

  //! \brief Switch the way of increase/decrease
  void inverse(void);
  
private:
  volatile T* const _addr;
  bool _inverse;
};

////////////////////////////////////////////////////////////////////

template<typename T>
inline Encoder<T>::Encoder(const char* name, T* addr)
  : Device(name), _addr(addr), _inverse(false) {

}

template<typename T>
inline s32 Encoder<T>::getValue(void) {
  if(_inverse) {
    return -(*_addr);
  }
  else {
    return *_addr;
  }
}

template<typename T>
inline void Encoder<T>::inverse(void) {
  _inverse = !_inverse;
}


#endif//ENCODER_HPP
