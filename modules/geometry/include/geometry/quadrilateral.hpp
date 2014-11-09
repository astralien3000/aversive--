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

#ifndef QUADRILATERAL_HPP
#define QUADRILATERAL_HPP

#include <base/integer.hpp>
#include <math/vect.hpp>
#include <geometry/shape.hpp>

//! \attention The points A, B, C and D defining the quadrilateral must be clockwise.
//! \attention The quadrilateral must be convex.
class Quadrilateral : public Shape {
  Vect<2, s32> _a;
  Vect<2, s32> _b;
  Vect<2, s32> _c;
  Vect<2, s32> _d;
public:
  static const u8 ID = 'q';
  
  inline Quadrilateral(void)
    : Shape(ID), _a(0, 0), _b(0, 0), _c(0, 0), _d(0, 0) {
  }
  
  inline Quadrilateral(const Vect<2, s32>& a, const Vect<2, s32>& b, const Vect<2, s32>& c, const Vect<2, s32>& d)
    : Shape(ID), _a(a), _b(b), _c(c), _d(d) {
  }
  
  inline Quadrilateral(const s32& x1, const s32& y1, const s32& x2, const s32& y2, const s32& x3, const s32& y3, const s32& x4, const s32& y4)
    : Shape(ID), _a(x1, y1), _b(x2, y2), _c(x3, y3), _d(x4, y4) {
  }
  
  inline Quadrilateral(const Quadrilateral& q)
    : Shape(ID), _a(q._a), _b(q._b), _c(q._c), _d(q._d) {
  }
  
  inline Quadrilateral& operator=(const Quadrilateral& q) {
    _a = q._a;
    _b = q._b;
    _c = q._c;
    _d = q._d;
    return (*this);
  }
  
  inline bool operator==(const Quadrilateral& q) const {
    return _a == q._a && _b == q._b && _c == q._c && _d == q._d;
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
  
  inline Vect<2, s32>& d(void) {
    return _d;
  }
  
  inline Vect<2, s32>& operator[](u8 index) {
    switch(index) {
    case 0:
      return _a;
    case 1:
      return _b;
    case 2:
      return _c;
    case 3:
      return _d;
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
  
  inline const Vect<2, s32>& d(void) const {
    return _d;
  }
  
  inline const Vect<2, s32>& operator[](u8 index) const {
    switch(index) {
    case 0:
      return _a;
    case 1:
      return _b;
    case 2:
      return _c;
    case 3:
      return _d;
    default:
      return *((Vect<2, s32>*) 0);
    }
  }
};

#endif//QUADRILATERAL_HPP
