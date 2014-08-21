#include <aversive.hpp>
#include <client_thread.hpp>
#include <device/device.hpp>

#include <functional>
#include <cstring>

int main(int argc, char* argv[]) {
  (void) argc;
  (void) argv;
  
  Aversive::init();
  Device mole_device("TESTER");
  
  bool ok = ClientThread::instance().
    registerDevice(mole_device,
                   std::function<void(char*)>([] (char* msg) -> void {
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
  
  while(Aversive::sync()) {
  }
  
  return Aversive::exit();
}
