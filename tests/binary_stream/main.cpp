#include <aversive.hpp>
#include <device/stream/buffered_uart_stream.hpp>
#include <hardware/interrupts.hpp>

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Aversive::init();
  BufferedUartStream<0>& str = BufferedUartStream<0>::instance();
  str.setMode(Stream::BINARY);
  Interrupts::init();
  
  u32 i;
  while(Aversive::sync()) {
    str >> i;
    str << i;
  }
  
  Aversive::setReturnCode(0);
  return Aversive::exit();
}
