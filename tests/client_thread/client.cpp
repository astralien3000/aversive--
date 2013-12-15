#include <aversive.hpp>
#include <client_thread.hpp>
#include <functional>

#include <cstring>
#include <iostream>
#include <QThread>

int main(int argc, char** argv)
{
  if(!Aversive::init(argc, argv)) {
    std::cerr << "Error while initializing Aversive++" << std::endl;
    return 1;
  }
  std::cout << "Properly initialized Aversive++" << std::endl;
  
  bool keep_going = true;
  if(!ClientThread::registerDevice("TESTER",
				   std::function<void(char*)>([&keep_going] (char* msg) mutable -> void {
				       if(strcmp(msg, "TESTER Stop\n") == 0) {
					 keep_going = false;
				       }
				       std::cout << "Received: " << msg;
				     }))) {
    std::cerr << "Error while registering a new device" << std::endl;
    Aversive::exit();
    return 1;
  }
  std::cout << "Properly registered a new device" << std::endl;
  
  ClientThread::sendData("TESTER I'm new\n");
  
  while(keep_going) {
    QThread::msleep(10);
  }
  
  Aversive::exit();
  return 0;
}
