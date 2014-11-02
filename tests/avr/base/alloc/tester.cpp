#include <cstdlib>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include "../../../my_assert.hpp"

#include <device/stream/serial_stream.hpp>

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  SerialStream io("/dev/ttyACM0");
  myAssert(io.opened(), "Line " S__LINE__ ": Stream could not be properly opened");  
  
  // Leave some time for the board to boot.
  sleep(1);
  
  // Tell the board to start the test.
  io.setValue('S');
  
  char buffer[80] = { '\0' };
  io.setMode(Stream::FORMATTED);
  io.setSeparatorMode(FormattedStream::LINE);
  buffer[0] = io.getValue();
  buffer[1] = io.getValue();
  //io >> buffer;
  
  std::cout << "Buffer content: \"" << buffer << "\"" << std::endl;
  //myAssert(strncmp(buffer, "OK", 2) == 0, buffer);
  
  //std::cout << "OK" << std::endl;
  return EXIT_SUCCESS;
}
