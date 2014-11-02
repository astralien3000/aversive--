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

#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <base/integer.hpp>

class Shape {
  u8 _shape_id;
  
protected:
  inline Shape(u8 shape_id)
    : _shape_id(shape_id) {
  }
  
public:
  static const u8 ID = 'u';
  
  inline Shape(void)
    : _shape_id(ID) {
  }
  
  inline u8 shapeId(void) const {
    return _shape_id;
  }
};

#endif//SHAPE_HPP
