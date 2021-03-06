#include <aversive.hpp>

#include <device/pin/digital_pin.hpp>

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Aversive::init();

  DigitalPin<15> led("LED");
  led.setOutput();
  led.setValue(true);
  
  while(Aversive::sync()) {
  }
  
  Aversive::setReturnCode(0);
  return Aversive::exit();
}
