#include <aversive.hpp>
#include <device/stream/buffered_uart_stream.hpp>
#include <device/stream/uart_stream.hpp> // For debugging purpose
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
  
  //BufferedUartStream<0>& str = BufferedUartStream<0>::instance();
  UartStream<0> str("");
  Interrupts::set();
  
  u16 j;
  // Writing here with BufferedUartStream does not work but it does in writer function above.
  str << "Hello, write an (unsigned) integer:\n\r";
  str << "- 0 for reading test\n\r";
  str << "- anything else for writing test\n\r";
  turnOn(PB7);
  str >> j;
  turnOff(PB7);
  str << "I read " << j << ".\n\r";
  
  if(j == 0) { // Reading test
    // Works with UartStream, but we would like to make it work with BufferUartStream as well once its writting has been fixed.
    str << "Reading test\n\r";
    while(Aversive::sync()) {
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
    Timer<0>& t = Timer<0>::instance();
    t.init();
    t.setPrescaler<1024>();
    t.overflowEvent().setFunction(writer);
    t.overflowEvent().start();
    
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
