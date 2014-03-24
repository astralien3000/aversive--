#include <aversive.hpp>
#include <system/scheduler.hpp>

#include <device/eirbot2014/motor.hpp>

Device d("TESTER");
int i = 0;
char buffer[80];

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Aversive::init();
  // Declare your devices here
  // Initialize your stuff here

  Task t1([]() {
      sprintf(buffer, "value 1");
      ClientThread::instance().sendDeviceMessage(d, buffer);
    });

  Task t2([]() {
      sprintf(buffer, "value 2");
      ClientThread::instance().sendDeviceMessage(d, buffer);
    });
  
  t1.setPeriod(10);
  t2.setPeriod(10);

  t1.setRepeat();
  t2.setRepeat();

  Scheduler::instance().addTask(t1);
  Scheduler::instance().addTask(t2);

  //Scheduler::instance().rmTask(t1);
  //Scheduler::instance().rmTask(t2);
  
  while(Aversive::sync()) {
    // Your while(1) code
  }
  
  // You can have several "while(Aversive::isRunning())" loops if needed
  // Keep the "Aversive::sleep()" at the end of the loop in each of your loops
  
  // Unintialize your stuff here
  Aversive::setReturnCode(0); // Optional; default value is already 0
  return Aversive::exit();
}
