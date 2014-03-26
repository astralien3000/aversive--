#include <aversive.hpp>
#include <device/eirbot2014/servomotor_pin.hpp>
#include <device/eirbot2014/servomotor_fpga.hpp>

#include <base/integer.hpp>
#include <base/singleton.hpp>

s32 VAL;

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Aversive::init();
  ServomotorPin<0,0> servo_pin("outservo_pin");
  ServomotorFpga<&VAL> servo_fpga("outservo_fpga");

  servo_pin.setMaxCommand(1024);
  servo_fpga.setMaxCommand(10000);
  
  servo_pin.setValue(100);
  servo_fpga.setValue(200);

  servo_pin.setValue(1024);
  
  Aversive::setReturnCode(0);
  return Aversive::exit();
}
