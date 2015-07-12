#include <aversive.hpp>
#include <base/alloc.hpp>
#include <base/integer.hpp>
#include <device/stream/buffered_uart_stream.hpp>
#include <hardware/interrupts.hpp>

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Aversive::init();
  
  BufferedUartStream<0>& io = BufferedUartStream<0>::instance();

  Interrupts::init();

  while(io.getValue() != 'S') {
    // We first wait for the tester to tell the board to start
  }
  
  io << "OK\n";
  
  while(Aversive::sync()) {
  }

  Interrupts::stop();
  
  return Aversive::exit();
}
