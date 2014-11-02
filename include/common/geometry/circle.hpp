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

#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <base/integer.hpp>
#include <math/vect.hpp>
#include <geometry/shape.hpp>

class Circle : public Shape {
  Vect<2, s32> _centre;
  s32 _radius;
public:
  static const u8 ID = 'c';
  
  inline Circle(void)
    : Shape(ID), _centre(0, 0), _radius(0) {
  }
  
  inline Circle(const Vect<2, s32>& centre, s32 radius)
    : Shape(ID), _centre(centre), _radius(radius) {
  }
  
  inline Circle(s32 x, s32 y, s32 radius)
    : Shape(ID), _centre(x, y), _radius(radius) {
  }
  
  inline Circle(const Circle& other)
    : Shape(ID), _centre(other._centre), _radius(other._radius) {
  }
  
  inline Circle& operator=(const Circle& other) {
    _centre = other._centre;
    _radius = other._radius;
    return (*this);
  }
  
  inline bool operator==(const Circle& other) const {
    return _centre == other._centre && _radius == other._radius;
  }
  
  inline Vect<2, s32>& centre(void) {
    return _centre;
  }
  
  inline s32& radius(void) {
    return _radius;
  }
  
  inline const Vect<2, s32>& centre(void) const {
    return _centre;
  }
  
  inline const s32& radius(void) const {
    return _radius;
  }
};

#endif//CIRCLE_HPP
