#include <aversive.hpp>
#include <system/multipwm.hpp>

//#include <device/other/pin.hpp>

//#include <hardware/timer.hpp>
//#include <hardware/interrupts.hpp>



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

//Pin<8 * 4 + 3> servopin("");
//Pin<8 * 7 + 3> servopin2("");
//Pin<8 * 7 + 4> servopin3("");


int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Aversive::init();

//  servopin.setMode(PinMode::OUTPUT);
//  servopin2.setMode(PinMode::OUTPUT);
//  servopin3.setMode(PinMode::OUTPUT);

//  MultiServo ms;
//  MultiServo::Servo& s = ms.createServo(servopin);
//  MultiServo::Servo& s2 = ms.createServo(servopin2);
//  MultiServo::Servo& s3 = ms.createServo(servopin3);

//  // ARM2(s3) : MIN = 800 ; MAX = 1900
//  // ARM1(s ) : MIN = 800 ; MAX = 1400
//  // SLDR(s2) : MIN = 500 : MAX = 1400

//  Interrupts::set();

//  u32 i = 500;
//  s32 dir = 10;
//  u32 j = 1200;
//  u32 k = 1500;
//  while(Aversive::sync()) {
//    s2.setValue(i);


//    if(dir > 0) {
//      if(j < 1300) j += 30;
//      s.setValue(j);
//      if(k > 1600) k -= 30;
//      s3.setValue(k);
//    }
//    else {
//      if(j > 800) j -=30;
//      s.setValue(j);
//      if(k < 1900) k += 30;
//      s3.setValue(k);
//    }

//    for(volatile u32 i = 0 ; i < 500 ; i++) {}
//    i += dir;
//    if(i < 500 || i > 1400) {
//      dir = -dir;
//      i += 2 * dir;
//    }
    
//    // s.setValue(700);
//    // s2.setValue(600);
//    // s3.setValue(700);
//    // for(volatile u32 i = 0 ; i < 500000 ; i++) {}

//    // if(i == PWM) {
//    //   servopin.setValue(false);
//    //   //PORTE = 0x00;
//    // }
//    // if(i == PERIOD) {
//    //   servopin.setValue(true);
//    //   //PORTE = 0xFF;
//    //   i = 0;
//    //   //test();
//    //   //PWM++;
//    // }
//    // i++;
//    //PWM++;
//  }
  
  Aversive::setReturnCode(0);
  return Aversive::exit();
}
