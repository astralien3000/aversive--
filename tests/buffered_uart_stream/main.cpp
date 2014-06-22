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
  Interrupts::init();
  
  u16 j;
  str << "Hello, write an (unsigned) integer:\n\r";
  str << "- 0 for reading test\n\r";
  str << "- anything else for writing test\n\r";
  str.flushOutput();
  turnOn(PB7);
  str >> j;
  turnOff(PB7);
  str << "I read " << j << ".\n\r";
  
  if(j == 0) { // Reading test
    str << "Reading test\n\r";
    while(Aversive::sync()) {
      str.flushInput();
      str << "Write an (unsigned) integer:\n\r";
      str >> j;
      str << "I read " << j << ".\n\r";
      for(u32 i = 0; i < 1600000; i++) {
	__asm__ __volatile__ ("NOP\n");
      }
      toggle(PB7);
    }
  }
  else { // Pure writing test
    str << "Writing test\n\r";
    Timer<0>::init();
    Timer<0>::setPrescaler<1024>();
    Timer<0>::overflowEvent().setFunction(writer);
    Timer<0>::overflowEvent().start();
    
    while(Aversive::sync()) {
      for(u32 i = 0; i < 1600000; i++) {
	__asm__ __volatile__ ("NOP\n");
      }
      toggle(PB7);
    }
  }
  
  Aversive::setReturnCode(0);
  return Aversive::exit();
}
