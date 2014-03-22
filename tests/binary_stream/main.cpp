#include <aversive.hpp>
#include <device/stream/buffered_uart_stream.hpp>
#include <hardware/interrupts.hpp>
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

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Aversive::init();
  
  DDRB = (1<<PB7) | (1<<PB4);
  
  BufferedUartStream<0>& str = BufferedUartStream<0>::instance();
  str.setMode(Stream::BINARY);
  Interrupts::init();
  
  u32 i = 0;
  while(Aversive::sync()) {
    str >> i;
    str << i;
    toggle(PB7);
    for(u32 i = 0; i < 1600000; i++) {
      __asm__ __volatile__ ("NOP\n");
    }
  }
  
  Aversive::setReturnCode(0);
  return Aversive::exit();
}
