#include <device/stream/uart_stream.hpp>
#include <hardware/interrupts.hpp>

#define F_CPU 16000000L
#include <util/delay.h>
/*
int main(void) {
  Uart<0>::instance().init();

  while(1) {
    _delay_ms(500);
    Uart<0>::instance().send('a');
  }

  return 0;
}
*/

bool robotInit() {
  (void)UartStream<0>::instance();
  
    Interrupts::set();


  return true;
}

void robotLoop() {

  _delay_ms(100);
  UartStream<0>::instance() << "Bonjour  !\n" << (float)100000 << "                                 " << (float)458012665 << "                                t\n";
  
}

void robotExit() {
}
