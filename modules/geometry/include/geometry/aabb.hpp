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

#ifndef AABB_HPP
#define AABB_HPP

#include <base/integer.hpp>
#include <math/vect.hpp>
#include <geometry/shape.hpp>

class AABB : public Shape {
  Vect<2, s32> _o;
  u32 _w;
  u32 _h;
public:
  static const u8 ID = 'a';
  
  inline AABB(void)
    : Shape(ID), _o(0, 0), _w(0), _h(0) {
  }
  
  inline AABB(const Vect<2, s32>& o, const u32& w, const u32& h)
    : Shape(ID), _o(o), _w(w), _h(h) {
  }
  
  inline AABB(const s32& x, const s32& y, const u32& w, const u32& h)
    : Shape(ID), _o(x, y), _w(w), _h(h) {
  }
  
  inline AABB(const AABB& a)
    : Shape(ID), _o(a._o), _w(a._w), _h(a._h) {
  }
  
  inline AABB& operator=(const AABB& other) {
    _o = other._o;
    _w = other._w;
    _h = other._h;
    return (*this);
  }
  
  inline bool operator==(const AABB& other) const {
    return _o == other._o && _w == other._w && _h == other._h;
  }
  
  //! \brief Returns AABB's bottom left point.
  inline Vect<2, s32>& o(void) {
    return _o;
  }
  
  inline u32& w(void) {
    return _w;
  }
  
  inline u32& h(void) {
    return _h;
  }
  
  inline const Vect<2, s32>& o(void) const {
    return _o;
  }
  
  inline const u32& w(void) const {
    return _w;
  }
  
  inline const u32& h(void) const {
    return _h;
  }
};

#endif//AABB_HPP
