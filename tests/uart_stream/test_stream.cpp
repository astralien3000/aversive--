#include <device/stream/uart_stream.hpp>

#define F_CPU 16000000L
#include <util/delay.h>

static uint8_t i;

bool robotInit() {
  i = 0;
  UartStream<0>::instance() << "Bonjour !\n";
}

void robotLoop() {
  _delay_ms(500);
  UartStream<0>::instance() << i++ << "\n";
}

void robotExit() {
}
