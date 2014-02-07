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
  Output<s32>& _mot_l, _mot_r;
  Input<Vect<2, s32>>& _odo;
  
 public:
  RobotController(Output<s32>& mot_l, Output<s32>& mot_r, Input<Vect<2, s32>>& odo, Filter& cfd, Filter& ffd, Filter& efd, Filter& cfa, Filter& ffa, Filter& efa) : 
    _loop_d(cfd, ffd, efd), _loop_a(cfa, ffa, efa), _mot_l(mot_l), _mot_r(mot_r), _odo(odo) {}
  
  void setValue(Vect<2, s32> val) {
    Vect<2, s32> fb(_odo.getValue());

    _loop_d.setFeedback(fb.coord(0));
    _loop_a.setFeedback(fb.coord(1));

    s32 corr_d = _loop_d.doFilter(val.coord(0));
    s32 corr_a = _loop_a.doFilter(val.coord(1));
    
    _mot_l.setValue(corr_d + corr_a/2);
    _mot_r.setValue(corr_d - corr_a/2);
  }
};

#endif//ROBOT_CONTROLLER_HPP

