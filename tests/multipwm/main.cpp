#include <aversive.hpp>
#include <system/multipwm.hpp>
#include <device/other/pin.hpp>

#include <hardware/interrupts.hpp>
//#include <hardware/timer.hpp>



//extern "C" void __cxa_guard_acquire(void) {}
//extern "C" void __cxa_guard_release(void) {}


//#include <base/array.hpp>
//#include <device/output.hpp>

//class MultiServo {
//public:
//  static const u32 MAX_SERVO = 8;

//  static const u32 FCLOCK = 16000000;
//  static const u32 PRESCALER = 1;
//  static const u32 OVF = 256;

//  static const u32 FOVF = FCLOCK / (PRESCALER * OVF);
//  static const u32 POVF = 1000000 / FOVF;

//  static const u32 PSERVO = 11000;
//  static const u32 PPWM = 400;

//  static const u32 SERVO = PSERVO / POVF;
//  static const u32 PWM = PPWM / POVF;

//public:
//  class Servo : public Output<u32> {
//    friend class MultiServo;

//  private:
//    Output<bool>* _out;
//    u32 _pwm;

//  public:
//    Servo(void)
//      : _out(0), _pwm(0) {

//    }
    

//    Servo(Output<bool>& out)
//      : _out(&out), _pwm(0) {

//    }

//    Servo(const Servo& other)
//      : _out(other._out), _pwm(other._pwm) {

//    }

//    Servo& operator=(const Servo& other) {
//      _out = other._out;
//      _pwm = other._pwm;
//    }

//    void setValue(u32 val) {
//      _pwm = val / POVF;
//    }
//  };

//private:
//  static u32 count;
//  static int _servo_count;

//  static Array<MAX_SERVO, Servo> _servo;
//public:
//  MultiServo(void) {

//    Timer<0>::init();
//    Timer<0>::overflowEvent().setFunction([]() {

//	for(int i = 0 ; i < MAX_SERVO ; i++) {
//	  if(_servo[i]._out && count == _servo[i]._pwm) {
//	    _servo[i]._out->setValue(false);
//	  }
//	}
	
//	if(count == SERVO) {
//	  for(int i = 0 ; i < MAX_SERVO ; i++) {
//	    if(_servo[i]._out) {
//	      _servo[i]._out->setValue(true);
//	    }
//	  }
//	  count = 0;
//	}
//	count++;
//      });
//    Timer<0>::overflowEvent().start();
//    Timer<0>::setPrescaler<0>();
//  }

//  Servo& createServo(Output<bool>& out) {
//    _servo[_servo_count] = Servo(out);
//    _servo_count++;
//    return _servo[_servo_count - 1];
//  }
//};

//// #include <avr/interrupt.h>
//// #include <avr/io.h>

//// ISR(TIMER0_OVF_vect) {
////   PWM++;
////   //while(1);
//// }

//u32 MultiServo::count = 0;
//int MultiServo::_servo_count = 0;
//Array<MultiServo::MAX_SERVO, MultiServo::Servo> MultiServo::_servo;

Pin<12> pin("");


int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Aversive::init();

  pin.setMode(PinMode::OUTPUT);

  MultiPWM<DefaultMultiPWMConfig>::Pin servo =
      MultiPWM<DefaultMultiPWMConfig>::instance().createPin(pin);

  servo.setValue(900);

  Interrupts::set();

  while(Aversive::sync()) {
  }
  
  Aversive::setReturnCode(0);
  return Aversive::exit();
}
