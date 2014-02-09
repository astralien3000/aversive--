#include <aversive.hpp>
#include <system/scheduler.hpp>

#include <device/output_device.hpp>

SimpleOutputDevice<int> out("out");

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Aversive::init();
  // Declare your devices here
  // Initialize your stuff here
  Task t1([]() {
      out.setValue(1);
    });

  Task t2([]() {
      out.setValue(20);
    });
  
  t1.setPeriod(10);
  t2.setPeriod(10);

  t1.setRepeat();
  t2.setRepeat();

  Scheduler::instance().addTask(t1);
  Scheduler::instance().addTask(t2);

  //Scheduler::instance().rmTask(t1);
  //Scheduler::instance().rmTask(t2);
  
  while(Aversive::isRunning()) {
    // Your while(1) code
    Aversive::sleep(); // Very important for simulation purpose
  }
  
  // You can have several "while(Aversive::isRunning())" loops if needed
  // Keep the "Aversive::sleep()" at the end of the loop in each of your loops
  
  // Unintialize your stuff here
  Aversive::setReturnCode(0); // Optional; default value is already 0
  return Aversive::exit();
}
