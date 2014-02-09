#include <aversive.hpp>
#include <client_thread.hpp>
#include <device/device.hpp>

#include <functional>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <QThread>


int main(int argc, char* argv[]) {
  (void) argc;
  (void) argv;
  
  Aversive::init();
  // Declare your devices here
  // Initialize your stuff here
  Device mole_device("TESTER");
  
  bool ok = ClientThread::instance().
    registerDevice(mole_device,
		   std::function<void(char*)>([] (char* msg) mutable -> void {
		       if(strcmp(msg, "Stop") == 0) {
			 ClientThread::instance().sendData("D TESTER Stop? :'(");
			 Aversive::stop();
		       }
		       else if(strcmp(msg, "Love u") == 0) {
			 ClientThread::instance().sendData("D TESTER Love u too");
		       }
		     }));
  if(ok) {
    ClientThread::instance().sendData("D TESTER I'm new");
  }

  while(Aversive::isRunning()) {
    // Your while(1) code
    Aversive::sleep(); // Very important for simulation purpose
  }
  
  // You can have several "while(Aversive::isRunning())" loops if needed
  // Keep the "Aversive::sleep()" at the end of the loop in each of your loops
  
  // Unintialize your stuff here
  Aversive::setReturnCode(0); // Optional; default value is already 0
  return Aversive::exit();

  return 0;
}
