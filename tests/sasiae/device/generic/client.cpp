#include <aversive.hpp>
#include <device/eirbot2014/encoder.hpp>
#include <device/eirbot2014/motor.hpp>

#include <base/integer.hpp>
#include <base/singleton.hpp>

u32 ENC;
s32 MOT;

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Aversive::init();
  // Declare your devices here
  // Initialize your stuff here
  Encoder<u32> _id("intest", &ENC);
  Motor<s32> _od("outtest", &MOT);

  while(Aversive::sync()) {
    // Your while(1) code
    if(_id.getValue() == 10) {
      Aversive::stop();
    }
  }
  
  // You can have several "while(Aversive::isRunning())" loops if needed
  // Keep the "Aversive::sleep()" at the end of the loop in each of your loops
  
  // Unintialize your stuff here
  _od.setValue(_id.getValue());
  Aversive::setReturnCode(0); // Optional; default value is already 0
  return Aversive::exit();
}
