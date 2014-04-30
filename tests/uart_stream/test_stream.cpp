#include <device/stream/uart_stream.hpp>
#include <hardware/interrupts.hpp>

#define F_CPU 16000000L
#include <util/delay.h>

int main(void) {
  UartStream<0> uart(0);

  _delay_ms(100);
  s8 i;
  while(1) {
    uart >> i;
    uart << "Read : " << i << " !\n";
  }

  return 0;
}
