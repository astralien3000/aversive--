#include <iostream>
using namespace std;

#include <aversive.hpp>

#include <filter/pid_filter.hpp>

#include <device/controller/motor_controller.hpp>
#include <device/output_device.hpp>
#include <device/input_device.hpp>

int main(int argc, char* argv[]) {
  (void) argc;
  (void) argv;
  
  Aversive::init();

  PidFilter pid, id;
  SimpleInputDevice<s32> in("in");
  SimpleInputDevice<bool> quit("quit");
  SimpleOutputDevice<s32> out("out");
  MotorController ctrl(out, in, id, id, pid);
  
  id.setGains(1,0,0);
  pid.setGains(1,0,0);
 
  while(Aversive::isRunning()) {
    // Your while(1) code
    ctrl.setValue(10);
    
    Aversive::sleep(); // Very important for simulation purpose
  }
  
  // You can have several "while(Aversive::isRunning())" loops if needed
  // Keep the "Aversive::sleep()" at the end of the loop in each of your loops
  
  // Unintialize your stuff here
  Aversive::setReturnCode(0); // Optional; default value is already 0
  return Aversive::exit();
}

