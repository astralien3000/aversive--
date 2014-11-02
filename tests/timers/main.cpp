/*
Expected output :
b00000100010001000100010001000100010001000100010001000100010001000100100010001000100010001000100010001000100010001000100010001000100101111111111111111111111111111111111111111111111111111111111111111111
*/

#include <aversive.hpp>

#include <hardware/timer.hpp>
#include <hardware/interrupts.hpp>
#include <hardware/uart.hpp>

extern "C" {
  void __cxa_guard_acquire(void) {
    Uart<0>::send('z');
  }
  void __cxa_guard_release(void) {
    Uart<0>::send('e');
  }
}

template<typename MyTimer, char C>
void configure_timer(void) {
  static u32 count = 0;

  MyTimer::overflowEvent().setFunction([]() {
      if(count < 100) {
	Uart<0>::send(C);
	count++;
      }
    });
  MyTimer::init();
  MyTimer::template setPrescaler<1>();
  MyTimer::overflowEvent().start();
  MyTimer::setCounter(0);
}

typedef Timer<1> MyTimer;

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Aversive::init();
  Uart<0>::init();

  Uart<0>::send('b');

  configure_timer<Timer<0>, '0'>();
  configure_timer<Timer<1>, '1'>();
  
  Interrupts::set();
    
  while(1) {
  }
  
  Interrupts::clear();
  Aversive::setReturnCode(0);
  return Aversive::exit();
}
