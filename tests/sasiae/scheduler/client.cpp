#include <iostream>

#include <aversive.hpp>
#include <system/scheduler.hpp>

#include <device/eirbot2014/motor.hpp>

Device d("TESTER");

struct MyConfig : public DefaultSchedulerConfig {};

Scheduler<MyConfig>& sched = Scheduler<MyConfig>::instance();

template<int ID>
struct Tester {
  static u32 count;

  static void exec(void) {
      char buffer[80];
      sprintf(buffer, "value %d", ID);
      ClientThread::instance().sendDeviceMessage(d, buffer);
  }

  static void configTask(void) {
    Task t(exec);
    t.setPeriod(10 * ID);
    t.setPriority(8 - ID);
    t.setRepeat();
    sched.addTask(t);
  }
};

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Aversive::init();

  Tester<1>::configTask();
  Tester<2>::configTask();
  Tester<3>::configTask();
  Tester<4>::configTask();
  Tester<5>::configTask();
  Tester<6>::configTask();
  Tester<7>::configTask();
  Tester<8>::configTask();

  while(Aversive::sync()) {
  }

  Aversive::setReturnCode(0);
  return Aversive::exit();
}
