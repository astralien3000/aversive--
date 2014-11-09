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

#ifndef SEGMENT_HPP
#define SEGMENT_HPP

#include <base/integer.hpp>
#include <math/vect.hpp>
#include <geometry/shape.hpp>

class Segment : public Shape {
  Vect<2, s32> _a;
  Vect<2, s32> _b;
public:
  static const u8 ID = 's';
  
  inline Segment(void)
    : Shape(ID), _a(0, 0), _b(0, 0) {
  }
  
  inline Segment(const Vect<2, s32>& a, const Vect<2, s32>& b)
    : Shape(ID), _a(a), _b(b) {
  }
  
  inline Segment(const s32& x1, const s32& y1, const s32& x2, const s32& y2)
    : Shape(ID), _a(x1, y1), _b(x2, y2) {
  }
  
  inline Segment(const Segment& s)
    : Shape(ID), _a(s._a), _b(s._b) {
  }
  
  inline Segment& operator=(const Segment& s) {
    _a = s._a;
    _b = s._b;
    return (*this);
  }
  
  inline bool operator==(const Segment& s) const {
    return _a == s._a && _b == s._b;
  }
  
  inline Vect<2, s32>& a(void) {
    return _a;
  }
  
  inline Vect<2, s32>& b(void) {
    return _b;
  }
  
  inline Vect<2, s32>& operator[](u8 index) {
    switch(index) {
    case 0:
      return _a;
    case 1:
      return _b;
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
  
  inline s32 length(void) const {
    return (Vect<2, s32>(_a.coord(0) -_b.coord(0), _a.coord(1) - _b.coord(0))).norm();
  }
  
  inline const Vect<2, s32>& operator[](u8 index) const {
    switch(index) {
    case 0:
      return _a;
    case 1:
      return _b;
    default:
      return *((Vect<2, s32>*) 0);
    }
  }
};

#endif//SEGMENT_HPP
