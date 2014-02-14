#include <aversive.hpp>
#include <system/scheduler.hpp>
#include <device/stream/uart_stream.hpp>

#include <aversive.hpp>

extern "C" {
  void __cxa_pure_virtual(void) {
    while(1);
  }
}

UartStream<0>* st;

void inter(void) {
  st->setValue('b');
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
  t.setPeriod(1000000);
  t.setRepeat();
  
  Scheduler::instance().addTask(t);
  
  while(Aversive::isRunning()) {
    // Your while(1) code
    //inter();
    Aversive::sleep(); // Very important for simulation purpose
  }
  
  // You can have several "while(Aversive::isRunning())" loops if needed
  // Keep the "Aversive::sleep()" at the end of the loop in each of your loops
  
  // Unintialize your stuff here
  Aversive::setReturnCode(0); // Optional; default value is already 0
  return Aversive::exit();
}
