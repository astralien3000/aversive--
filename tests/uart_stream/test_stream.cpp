#include <device/stream/uart_stream.hpp>
#include <hardware/interrupts.hpp>

#define F_CPU 16000000L
#include <util/delay.h>


int main(void) {
  UartStream<0> uart;

  _delay_ms(100);
  unsigned int i;
  while(1) {
    uart >> i;
    uart << i << "\n";
  }

  return 0;
}
