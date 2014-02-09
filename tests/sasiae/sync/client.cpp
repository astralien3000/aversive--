#include <aversive.hpp>
#include <client_thread.hpp>
#include <device/device.hpp>

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Aversive::init();
  // Declare your devices here
  // Initialize your stuff here
  Device d("TESTER");
  int i = 0;
  char buffer[80];

  while(Aversive::isRunning()) {
    // Your while(1) code
    sprintf(buffer, "value is %d", i++);
    ClientThread::instance().sendDeviceMessage(d, buffer);
    Aversive::sleep(); // Very important for simulation purpose
  }
  
  // You can have several "while(Aversive::isRunning())" loops if needed
  // Keep the "Aversive::sleep()" at the end of the loop in each of your loops
  
  // Unintialize your stuff here
  Aversive::setReturnCode(0); // Optional; default value is already 0
  return Aversive::exit();
}
