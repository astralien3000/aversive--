#include <aversive.hpp>
#include <client_thread.hpp>
#include <system/scheduler.hpp>

Device d("TESTER");
int i = 0;
char buffer[80];

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Aversive::init();
  
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
  
  while(Aversive::sync()) {
  }
  
  return Aversive::exit();
}
