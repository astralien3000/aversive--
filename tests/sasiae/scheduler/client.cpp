#include <iostream>

#include <aversive.hpp>
#include <system/scheduler.hpp>

#include <device/eirbot2014/motor.hpp>

Device d("TESTER");

template<int i>
void send_value(void) {
    char buffer[80];
    sprintf(buffer, "value %d", i);
    ClientThread::instance().sendDeviceMessage(d, buffer);
}

struct MyConfig : public DefaultSchedulerConfig {};


Scheduler<MyConfig>& sched = Scheduler<MyConfig>::instance();

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Aversive::init();

  Task tasks[16];

  tasks[0] = Task(send_value<0>);
  tasks[1] = Task(send_value<1>);
  tasks[2] = Task(send_value<2>);
  tasks[3] = Task(send_value<3>);
  tasks[4] = Task(send_value<4>);
  tasks[5] = Task(send_value<5>);
  tasks[6] = Task(send_value<6>);
  tasks[7] = Task(send_value<7>);

  for(int i = 0 ; i < 16 ; i++) {
      tasks[i].setPeriod(10);
      tasks[i].setRepeat();
      sched.addTask(tasks[i]);
  }

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
