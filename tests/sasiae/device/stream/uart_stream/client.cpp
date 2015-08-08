#include <aversive.hpp>
#include <device/stream/uart_stream.hpp>

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Aversive::init();

  UartStream<0> io("io");
  
  while(Aversive::sync()) {
    io.setValue(io.getValue()+1);
  }
  
  return Aversive::exit();
}





