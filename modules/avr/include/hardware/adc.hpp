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

#ifndef ADC_HPP
#define ADC_HPP

#include <base/singleton.hpp>

//! \brief class providing routines for microcontroller's analog-to-digital functionalities management
//! \param ID : the ID of the ADC port to use
template<int ID>
class Adc : public Singleton<Adc<ID>> {
public:
  inline void init(void);
  inline void reset(void);

  template<typename T> inline T getValue(void);

  template<typename Callable> inline void setEvent(Callable func);
  inline void launch(void);

private:
  inline Adc(void);

  class PrivateData;
  PrivateData data;
};

#endif//ADC_HPP
