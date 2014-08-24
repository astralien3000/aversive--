/*

Expected output :

Tester[1] : 1
Tester[1] : 2
Tester[2] : 1
Tester[1] : 3
Tester[3] : 1
Tester[1] : 4
Tester[2] : 2
Tester[4] : 1
Tester[1] : 5
Tester[5] : 1
Tester[1] : 6
Tester[2] : 3
Tester[3] : 2
Tester[6] : 1
Tester[1] : 7
Tester[7] : 1
Tester[1] : 8
Tester[2] : 4
Tester[4] : 2
Tester[8] : 1

 */

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
    count++;
    io << "Tester[" << ID << "] : " << count << "\n\r";
  }

  static void configTask(void) {
    Task t(exec);
    t.setPeriod(1000000 * ID);
    t.setPriority(8 - ID);
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
  Tester<2>::configTask();
  Tester<3>::configTask();
  Tester<4>::configTask();
  Tester<5>::configTask();
  Tester<6>::configTask();
  Tester<7>::configTask();
  Tester<8>::configTask();

  Interrupts::init();

  while(Aversive::sync());
  Aversive::setReturnCode(0);
  return Aversive::exit();
}
