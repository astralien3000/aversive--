#include <device/stream/uart_stream.hpp>
#include <hardware/interrupts.hpp>

#define F_CPU 16000000L
#include <util/delay.h>

#include <avr/io.h>

void EEPROM_write(u16 uiAddress, s8 ucData) {
  while(EECR & (1<<EEPE));
  // Set up address and data registers
  EEAR = uiAddress;
  EEDR = ucData;
  // Write logical one to EEMWE
  EECR |= (1<<EEMPE);
  // Start eeprom write by setting EEWE
  EECR |= (1<<EEPE);
}

s8 EEPROM_read(u16 uiAddress) {
  // Wait for completion of previous write
  while(EECR & (1<<EEPE));
  // Set up address register
  EEAR = uiAddress;
  // Start eeprom read by writing EERE 
  EECR |= (1<<EERE);
  // Return data from data register
  return EEDR;
}

int main(void) {
  UartStream<0> uart;

  _delay_ms(100);
  s8 i;
  while(1) {
    i = EEPROM_read(0);
    uart << "Reading : " << i << " in EEPROM\n";

    uart >> i;
    uart << "Writing : " << i << " in EEPROM\n";

    EEPROM_write(0, i);
  }

  return 0;
}
