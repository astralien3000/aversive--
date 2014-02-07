#ifndef MOTOR_CONTROLLER_HPP
#define MOTOR_CONTROLLER_HPP

#include <device/output.hpp>
#include <device/input.hpp>
#include <filter/feedback_loop_filter.hpp>
#include <base/integer.hpp>

class MotorController : public Output<s32> {
private:
  FeedbackLoopFilter _loop;
  Output<s32>& _mot;
  Input<s32>& _enc;

  bool _inv;

public:
  inline MotorController(Output<s32>& mot, Input<s32>& enc, Filter& cf, Filter& ff, Filter& ef) : _loop(cf, ff, ef), _mot(mot), _enc(enc), _inv(false) {}

  inline void setValue(s32 val) {
    _loop.setFeedback(_enc.getValue());
    val = Math::saturate<-127,127>(_loop.doFilter(val));
    if(_inv) {
      val = -val;
    }
    _mot.setValue(val);
  }

  inline void inverse(void) {
    _inv = !_inv;
  }
};

#endif//MOTOR_CONTROLLER_HPP

