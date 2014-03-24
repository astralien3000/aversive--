#ifndef MOTOR_CONTROLLER_HPP
#define MOTOR_CONTROLLER_HPP

#include <device/output.hpp>
#include <device/input.hpp>
#include <filter/feedback_loop_filter.hpp>
#include <filter/filter.hpp>
#include <base/integer.hpp>

class MotorController : public Output<s32> {
private:
  FeedbackLoopFilter _loop;
  Output<s32>& _mot;
  Input<s32>& _enc;

public:
  inline MotorController(Output<s32>& mot, Input<s32>& enc, Filter<s32>& cf, Filter<s32>& ff, Filter<s32>& ef)
    : _loop(cf, ff, ef), _mot(mot), _enc(enc) {
    
  }

  inline void setValue(s32 val) {
    _loop.setFeedback(_enc.getValue());
    val = _loop.doFilter(val);
    _mot.setValue(val);
  }
};

#endif//MOTOR_CONTROLLER_HPP

