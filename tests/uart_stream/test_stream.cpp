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

static u16 i = 0;

bool robotInit() {
  (void)UartStream<0>::instance();
  /*
  Uart<0>::instance().init();

  Uart<0>::instance().recvEvent().setFunction([]() {
      char c = Uart<0>::instance().recv<u8>();      
      Uart<0>::instance().send(c);
    });
  Uart<0>::instance().recvEvent().start();
  
  Uart<0>::instance().sendEvent().setFunction([]() {
    });
  Uart<0>::instance().sendEvent().start();
  */
  Interrupts::set();
  _delay_ms(500);
  UartStream<0>::instance() << "Bonjour !\n";
  return true;
}

void robotLoop() {
  //_delay_ms(5000);
  //char c = Uart<0>::instance().recv<u8>();
  //Uart<0>::instance().send('a');
  UartStream<0>::instance() << "test : " << 10l << "\n";
}

void robotExit() {
}
