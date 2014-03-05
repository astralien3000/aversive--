#include <aversive.hpp>
#include <device/stream/buffered_uart_stream.hpp>
#include <hardware/interrupts.hpp>
#include <hardware/timer.hpp>
#include <avr/io.h>

inline bool isOn(u16 p) {
  return (PORTB & (1<<p));
}

inline void turnOn(u16 p) {
  PORTB = PORTB | (1<<p);
  __asm__ __volatile__ ("NOP\n");
}

inline void turnOff(u16 p) {
  PORTB = PORTB & ~(1<<p);
  __asm__ __volatile__ ("NOP\n");
}

void toggle(u16 p) {
  if(isOn(p)) {
    turnOff(p);
    return;
  }
  else {
    turnOn(p);
    return;
  }
}

const char* data = "abcdef";

void writer(void) {
  static u32 i = 0;
  Interrupts::lock();
  BufferedUartStream<0>& out = BufferedUartStream<0>::instance();
  if(out.outputFreeSpace() >= 32) {
    out << data << " " << i++ << "\n\r";
  }
  Interrupts::unlock();
}

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Aversive::init();
  
  DDRB = (1<<PB7) | (1<<PB4);
  
  BufferedUartStream<0>& str = BufferedUartStream<0>::instance();
  (void) str;
  
  Timer<0>& t = Timer<0>::instance();
  t.init();
  t.setPrescaler<1024>();
  t.overflowEvent().setFunction(writer);
  t.overflowEvent().start();
  
  Interrupts::set();
  
  while(Aversive::sync()) {
    for(u32 i = 0; i < 1600000; i++) {
      __asm__ __volatile__ ("NOP\n");
    }
    toggle(PB7);
  }
  
  Aversive::setReturnCode(0);
  return Aversive::exit();
}
