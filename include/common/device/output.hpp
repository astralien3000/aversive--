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

#ifndef OUTPUT_HPP
#define OUTPUT_HPP

//! \class Output output.hpp <device/output.hpp>
//! \brief Output interface used by physical and virtual output devices.
//! \param T : the type of the data written into the output.
template<typename T>
class Output {
public:
  //! \brief Set the value of the output to a new value.
  //! \param value : the new value of the output.
  //! \todo Turn the parameter into a const reference (and then update all child classes + re-run tests)
  virtual void setValue(T value) = 0;
};

#endif//OUTPUT_HPP
