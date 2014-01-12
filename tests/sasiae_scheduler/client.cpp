#include <aversive.hpp>
#include <system/scheduler.hpp>

#include <device/output_device.hpp>

#include <base/singleton.hpp>

class Robot : public Singleton<Robot> {
public:
  OutputDevice<int> out;
  Robot() : out("out") {}
};

bool robotInit(void) {
  Task t1([]() {
      Robot::instance().out.setValue(100);
    });

  Task t2([]() {
      Robot::instance().out.setValue(20);
    });

  t1.setPeriod(10);
  t2.setPeriod(50);

  t1.setRepeat();
  t2.setRepeat();

  Scheduler::instance().addTask(t1);
  Scheduler::instance().addTask(t2);
  
  return 1;
}

void robotLoop(void) {
  
  return;
}

void robotExit(void) {
  
  return;
}
