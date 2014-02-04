#include <device/stream/uart_stream.hpp>
#include <hardware/interrupts.hpp>
#include <hardware/eeprom.hpp>

#define F_CPU 16000000L
#include <util/delay.h>

#include <avr/io.h>

int main(void) {
  UartStream<0> uart;

  _delay_ms(100);
  s8 i;
  while(1) {
    i = Eeprom::instance().read(0);
    uart << "Reading : " << i << " in EEPROM\n";

    uart >> i;
    uart << "Writing : " << i << " in EEPROM\n";

    Eeprom::instance().write(0, i);
  }

  return 0;
}
