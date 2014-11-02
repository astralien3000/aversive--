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

#ifndef INPUT_HPP
#define INPUT_HPP

//! \class Input input.hpp <device/input.hpp>
//! \brief Input interface used by physical and virtual input devices.
//! \param T : the type of the data read from the input.
template<typename T>
class Input {
public:
  //! \brief Return the current value of the input.
  //! \return The current value of the input.
  virtual T getValue(void) = 0;
};

#endif//INPUT_HPP
