#include <aversive.hpp>
#include <system/scheduler.hpp>

#include <device/output_device.hpp>

SimpleOutputDevice<int> out("out");

bool robotInit(void) {

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
  
  return 1;
}

void robotLoop(void) {
  
  return;
}

void robotExit(void) {
  
  return;
}
