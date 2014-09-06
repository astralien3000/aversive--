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

#ifndef AVERSIVE_CONFIG_HPP
#define AVERSIVE_CONFIG_HPP

#include <aversive.hpp>
#include <base/integer.hpp>

//! \class Aversive::Config config.hpp <config.hpp>
//! \brief Class holding the configuration of Aversive++.
class Aversive::Config {
  //! \brief Private default constructor to prevent instantiation.
  Config(void);

  //! \brief A dummy parameter that just stands there as an examle.
  static const void* __PARAM_DUMMY;
public:

  //! \brief Get the value of the dummy parameter.
  //! \return The dummy parameter's value.
  static inline ssys dummy(void) {
    return (ssys) &__PARAM_DUMMY;
  }
};

#endif//AVERSIVE_CONFIG_HPP
