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
 /* 
  Uart<0>::instance().sendEvent().setFunction([]() {
    });
  Uart<0>::instance().sendEvent().start();
  */
  Interrupts::set();
  _delay_ms(3000);
  //UartStream<0>::instance() << "123456789\n";
  Uart<0>::instance().send('a');

  return true;
}
int i=0;
void robotLoop() {
  //static int i=0;
  //UartStream<0>::instance() << "123456789012345678901234567890123456789012345678901234567890123456789\n";// << (u16)++i;

  UartStream<0>::instance() << (u8)i++;
  //UartStream<0>::instance() << (u8)7;
  UartStream<0>::instance() << " :: " << (u16)i;
  UartStream<0>::instance() << " :: " << (u32)i;
  UartStream<0>::instance() << " :: " << (float)i;
  UartStream<0>::instance() << " :: " << (double)i;
  UartStream<0>::instance() << " :: " << (double)i;
  UartStream<0>::instance() << "128372819120\n";
  //_delay_ms(100);
 // UartStream<0>::instance() << "Bonjour  !\n" << (float)100000 << "                                 " << (float)458012665 << "                                t\n";
  
}

void robotExit() {
}
