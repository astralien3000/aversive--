#ifndef MOTOR_CONTROLLER_HPP
#define MOTOR_CONTROLLER_HPP

#include "../output_device.hpp"
#include "../../filter/feedback_loop_filter.hpp"
#include "../../base/integer.hpp"

template<class Motor, class GP2, class ConsignFilter, class FeedbackFilter, class ErrorFilter>
class MotorController : public OutputDevice<s32> {
private:
  typedef FeedbackLoopFilter<ConsignFilter, FeedbackFilter, ErrorFilter> LoopFilter;

  LoopFilter _loop;
  Motor& _mot;
  GP2& _enc;

public:
  inline MotorController(const char* name, Motor& mot, GP2& enc, ConsignFilter& cf, FeedbackFilter& ff, ErrorFilter& ef) : OutputDevice<s32>(name), _loop(cf, ff, ef), _mot(mot), _enc(enc) {}

  inline void setValue(s32 val) {
    _loop.setFeedback(_enc.getValue());
    _mot.setValue(_loop.doFilter(val));
  }
};

namespace MotorControllerMaker {
  template<class Motor, class GP2, class ConsignFilter, class FeedbackFilter, class ErrorFilter>
  inline MotorController<Motor, GP2, ConsignFilter, FeedbackFilter, ErrorFilter> make(const char* name, Motor& mot, GP2& enc, ConsignFilter& cf, FeedbackFilter& ff, ErrorFilter& ef) {
    return MotorController<Motor, GP2, ConsignFilter, FeedbackFilter, ErrorFilter>(name, mot, enc, cf, ff, ef);
  }
}

#endif//MOTOR_CONTROLLER_HPP

