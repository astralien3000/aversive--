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

#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <base/integer.hpp>
#include <math/vect.hpp>
#include <geometry/shape.hpp>

//! \attention The points A, B and C defining the triangle must be clockwise.
class Triangle : public Shape {
  Vect<2, s32> _a;
  Vect<2, s32> _b;
  Vect<2, s32> _c;
public:
  static const u8 ID = 't';
  
  inline Triangle(void)
    : Shape(ID), _a(0, 0), _b(0, 0), _c(0, 0) {
  }
  
  inline Triangle(const Vect<2, s32>& a, const Vect<2, s32>& b, const Vect<2, s32>& c)
    : Shape(ID), _a(a), _b(b), _c(c) {
  }
  
  inline Triangle(const s32& x1, const s32& y1, const s32& x2, const s32& y2, const s32& x3, const s32& y3)
    : Shape(ID), _a(x1, y1), _b(x2, y2), _c(x3, y3) {
  }
  
  inline Triangle(const Triangle& t)
    : Shape(ID), _a(t._a), _b(t._b), _c(t._c) {
  }
  
  inline Triangle& operator=(const Triangle& t) {
    _a = t._a;
    _b = t._b;
    _c = t._c;
    return (*this);
  }
  
  inline bool operator==(const Triangle& t) const {
    return _a == t._a && _b == t._b && _c == t._c;
  }
  
  inline Vect<2, s32>& a(void) {
    return _a;
  }
  
  inline Vect<2, s32>& b(void) {
    return _b;
  }
  
  inline Vect<2, s32>& c(void) {
    return _c;
  }
  
  inline Vect<2, s32>& operator[](u8 index) {
    switch(index) {
    case 0:
      return _a;
    case 1:
      return _b;
    case 2:
      return _c;
    default:
      return *((Vect<2, s32>*) 0);
    }
  }
  
  inline const Vect<2, s32>& a(void) const {
    return _a;
  }
  
  inline const Vect<2, s32>& b(void) const {
    return _b;
  }
  
  inline const Vect<2, s32>& c(void) const {
    return _c;
  }
  
  inline const Vect<2, s32>& operator[](u8 index) const {
    switch(index) {
    case 0:
      return _a;
    case 1:
      return _b;
    case 2:
      return _c;
    default:
      return *((Vect<2, s32>*) 0);
    }
  }
};

#endif//TRIANGLE_HPP
