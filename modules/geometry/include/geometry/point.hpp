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

#ifndef POINT_HPP
#define POINT_HPP

#include <base/integer.hpp>
#include <math/vect.hpp>
#include <geometry/shape.hpp>

class Point : public Shape {
  Vect<2, s32> _p;
public:
  static const u8 ID = 'p';
  
  inline Point(void)
    : Shape(ID), _p(0, 0) {
  }
  
  inline Point(const s32& x, const s32& y)
    : Shape(ID), _p(x, y) {
  }
  
  inline Point(const Vect<2, s32>& p)
    : Shape(ID), _p(p) {
  }
  
  inline Point(const Point& p)
    : Shape(ID), _p(p._p) {
  }
  
  inline Point& operator=(const Point& p) {
    _p = p._p;
    return (*this);
  }
  
  inline Point& operator=(const Vect<2, s32>& p) {
    _p = p;
    return (*this);
  }
  
  inline bool operator==(const Point& p) const {
    return _p == p._p;
  }
  
  inline Vect<2, s32>& p(void) {
    return _p;
  }
  
  inline const Vect<2, s32>& p(void) const {
    return _p;
  }
  
  inline const s32& x(void) const {
    return _p.coord(0);
  }
  
  inline s32& x(void) {
    return _p.coord(0);
  }
  
  inline s32& operator[](u8 index) {
    switch(index) {
    case 0:
      return _p[0];
    case 1:
      return _p[1];
    default:
      return *((s32*) 0);
    }
  }
  
  inline const s32& y(void) const {
    return _p.coord(1);
  }
  
  inline s32& y(void) {
    return _p.coord(1);
  }
  
  inline const s32& operator[](u8 index) const {
    switch(index) {
    case 0:
      return _p[0];
    case 1:
      return _p[1];
    default:
      return *((s32*) 0);
    }
  }
};

#endif//POINT_HPP
