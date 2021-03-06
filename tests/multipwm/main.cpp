#include <aversive.hpp>
#include <system/multipwm.hpp>
#include <device/other/pin.hpp>

#include <hardware/interrupts.hpp>

static constexpr u32 MAX = 2100;
static constexpr u32 MIN = 550;

template<u32 PIN_ID>
class ServoTester {
private:
  Pin<PIN_ID> _pin;
  MultiPWM<DefaultMultiPWMConfig>::Pin _servo;
  u32 _counter;
  u32 _dir;
  
public:
  ServoTester(void)
    : _pin(""),
      _servo(MultiPWM<DefaultMultiPWMConfig>::instance().createPin(_pin)) {
    
    _pin.setMode(PinMode::OUTPUT);
    
    _counter = MIN;
    _dir = 1;
    
    _servo.setValue(_counter);
  }
  
  void update(void) {
    _counter += _dir;
    if(_counter <= MIN || MAX <= _counter) _dir = -_dir;
    
    _servo.setValue(_counter);
  }
};

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Aversive::init();
  
  ServoTester<12> test1; // D10
  ServoTester<13> test2; // D11
  ServoTester<14> test3; // D12
  
  Interrupts::set();
  
  while(Aversive::sync()) {
    test1.update();
    test2.update();
    test3.update();
    for(volatile u32 t = 0 ; t < 2 ; t++) {
    }
  }
  
  Aversive::setReturnCode(0);
  return Aversive::exit();
}
