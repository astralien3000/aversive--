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

#ifndef ODOMETER_HPP
#define ODOMETER_HPP

#include <device/input.hpp>
#include <device/device.hpp>
#include <math/vect.hpp>
#include <base/integer.hpp>

class Odometer : public Input<Vect<2, s32> > {
 private:
  Input<s32>& _enc_l;
  Input<s32>& _enc_r;
  s32 _imp_per_u;
  s32 _imp_per_deg;
  s32 _dist;
  s32 _angle;

  s32 _angle_mul;
  s32 _dist_mul;
  
 public:
  inline Odometer(Input<s32>& el, Input<s32>& er) : 
    _enc_l(el), _enc_r(er), 
    _imp_per_u(10), _imp_per_deg(10), 
    _dist(0), _angle(0),
    _angle_mul(1), _dist_mul(1) {

  }
  
  inline Vect<2, s32> getValue(void) {
    update();
    return Vect<2, s32>(distance(), angle());
  }

  inline s32 distance(void) const {
    return (_dist_mul * _dist) / _imp_per_u;
  }

  inline s32 angle(void) const {
    return (_angle_mul * _angle) / _imp_per_deg;
  }

  inline void setImpPerUnit(s32 val) {
    _imp_per_u = val;
  }

  inline void setImpPerDeg(s32 val) {
    _imp_per_deg = val;
  }

  inline void setAngleMultiplicator(s32 val) {
    _angle_mul = val;
  }

  inline void setDistanceMultiplicator(s32 val) {
    _dist_mul = val;
  }

  void update(void) {
    _dist = (s32)((s32)_enc_l.getValue() + (s32)_enc_r.getValue());
    _angle = (s32)(_enc_l.getValue() - _enc_r.getValue());
  }

};

#endif//ODOMETER_HPP
