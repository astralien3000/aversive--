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

#ifndef ROBOT_CONTROLLER_HPP
#define ROBOT_CONTROLLER_HPP

#include <device/output.hpp>
#include <device/input.hpp>
#include <filter/feedback_loop_filter.hpp>
#include <base/integer.hpp>
#include <math/vect.hpp>

class RobotController : public Output<Vect<2, s32>> {
 private:
  FeedbackLoopFilter _loop_d, _loop_a;
  Output<s32>& _mot_l;
  Output<s32>& _mot_r;
  Input<Vect<2, s32>>& _odo;
  
 public:
  RobotController(Output<s32>& mot_l, Output<s32>& mot_r, Input<Vect<2, s32>>& odo, Filter<s32>& cfd, Filter<s32>& ffd, Filter<s32>& efd, Filter<s32>& cfa, Filter<s32>& ffa, Filter<s32>& efa) : 
    _loop_d(cfd, ffd, efd), _loop_a(cfa, ffa, efa), _mot_l(mot_l), _mot_r(mot_r), _odo(odo) {}
  
  void setValue(Vect<2, s32> val) {
    Vect<2, s32> fb(_odo.getValue());

    _loop_d.setFeedback(fb.coord(0));
    _loop_a.setFeedback(fb.coord(1));

    s32 corr_d = _loop_d.doFilter(val.coord(0));
    s32 corr_a = _loop_a.doFilter(val.coord(1));
    
    _mot_l.setValue(corr_d - corr_a/2);
    _mot_r.setValue(corr_d + corr_a/2);
  }
};

#endif//ROBOT_CONTROLLER_HPP

