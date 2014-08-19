#include <aversive.hpp>
#include <system/scheduler.hpp>
#include <device/stream/uart_stream.hpp>

#include <hardware/interrupts.hpp>

#include <aversive.hpp>

UartStream<0> io("io");

Scheduler<DefaultSchedulerConfig>& sched = Scheduler<DefaultSchedulerConfig>::instance();

template<int ID>
struct Tester {
  static u32 count;

  static void exec(void) {
    io << "Tester[" << ID << "] : " << count << "\n\r";
    count++;
  }

  static void configTask(void) {
    Task t(exec);
    t.setPeriod(1000000 * ID);
    t.setRepeat();
    sched.addTask(t);
  }
};

template<int ID>
u32 Tester<ID>::count = 0;

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Aversive::init();

  Tester<1>::configTask();
//  Tester<2>::configTask();
//  Tester<3>::configTask();
//  Tester<4>::configTask();
//  Tester<5>::configTask();
//  Tester<6>::configTask();
//  Tester<7>::configTask();
//  Tester<8>::configTask();

  Interrupts::init();

  while(Aversive::sync());
  Aversive::setReturnCode(0);
  return Aversive::exit();
}
