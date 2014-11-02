#include <aversive.hpp>
#include <client_thread.hpp>
#include <device/device.hpp>

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Aversive::init();
  Device d("TESTER");
  int i = 0;
  char buffer[80];
  
  while(Aversive::sync()) {
    sprintf(buffer, "value is %d", i++);
    ClientThread::instance().sendDeviceMessage(d, buffer);
  }
  
  return Aversive::exit();
}
