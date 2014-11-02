// Minimal main code

#include <aversive.hpp>
#include <device/eirbot2014/rds.hpp>
#include <device/stream/fpga_uart_stream.hpp>
#include "fpga.hpp"

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Aversive::init();
  // Declare your devices here
  // Initialize your stuff here
  FpgaUartStream rds_stream("rds_stream", UART_TX_1_DATA, UART_TX_1_OCUP, UART_RX_1_DATA, UART_RX_1_AVA);
  Rds rds("rds", rds_stream);
  
  List<2, Vect<2, s32> > coords;

  while(Aversive::sync()) {
    // Your while(1) code
    rds.update();
    coords = rds.getValue();
  }
  
  // You can have several "while(Aversive::sync())" loops if needed
  
  // Unintialize your stuff here
  Aversive::setReturnCode(0); // Optional; default value is already 0
  return Aversive::exit();
}
