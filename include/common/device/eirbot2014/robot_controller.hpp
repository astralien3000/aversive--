#ifndef ROBOT_CONTROLLER_HPP
#define ROBOT_CONTROLLER_HPP

#include "../output_device.hpp"
#include "../../filter/feedback_loop_filter.hpp"
#include "../../base/integer.hpp"


template<class LeftMotor, class RightMotor, class Odometer, class ConsignFilter, class FeedbackFilter, class ErrorFilter>
class RobotController : OutputDevice<Vect<2, s32>> {
 private:
  typedef FeedbackLoopFilter<ConsignFilter, FeedbackFilter, ErrorFilter> LoopFilter;
  
  LoopFilter _loop_d, _loop_a;
  LeftMotor& _mot_l;
  RightMotor& _mot_r;
  Odometer& _odo;
  
 public:
  RobotController(const char* name, LeftMotor& mot_l, RightMotor& mot_r, Odometer& odo, ConsignFilter& cfd, FeedbackFilter& ffd, ErrorFilter& efd, ConsignFilter& cfa, FeedbackFilter& ffa, ErrorFilter& efa) : 
    OutputDevice<Vect<2, s32>>(name), _loop_d(cfd, ffd, efd), _loop_a(cfa, ffa, efa), _mot_l(mot_l), _mot_r(mot_r), _odo(odo) {}
  
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

namespace RobotControllerMaker {
  template<class LeftMotor, class RightMotor, class Odometer, class ConsignFilter, class FeedbackFilter, class ErrorFilter>
  RobotController<LeftMotor, RightMotor, Odometer, ConsignFilter, FeedbackFilter, ErrorFilter> make(const char* name, LeftMotor& mot_l, RightMotor& mot_r, Odometer& odo, ConsignFilter& cfd, FeedbackFilter& ffd, ErrorFilter& efd, ConsignFilter& cfa, FeedbackFilter& ffa, ErrorFilter& efa) {
    return RobotController<LeftMotor, RightMotor, Odometer, ConsignFilter, FeedbackFilter, ErrorFilter>(name, mot_l, mot_r, odo, cfd, ffd, efd, cfa, ffa, efa);
  }
}

#endif//ROBOT_CONTROLLER_HPP

