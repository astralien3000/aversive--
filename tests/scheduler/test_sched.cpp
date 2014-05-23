#include <aversive.hpp>
#include <system/scheduler.hpp>
#include <device/stream/uart_stream.hpp>

#include <hardware/interrupts.hpp>

#include <aversive.hpp>

UartStream<0>* st;
long long count = 0;

void inter(void) {
  *st << count++ << "\n\r";
}

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Aversive::init();
  // Declare your devices here
  // Initialize your stuff here
  UartStream<0> stream(0);
  st = &stream;
  
  Task t(inter);
  t.setPeriod(10000);
  t.setRepeat();
  
  Scheduler::instance().addTask(t);
  
  Interrupts::init();

  while(Aversive::sync()) {
    // Your while(1) code
    st->setValue('a');
    //inter();
  }
  
  // You can have several "while(Aversive::isRunning())" loops if needed
  // Keep the "Aversive::sleep()" at the end of the loop in each of your loops
  
  // Unintialize your stuff here
  Aversive::setReturnCode(0); // Optional; default value is already 0
  return Aversive::exit();
}
