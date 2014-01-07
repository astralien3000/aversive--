#include <aversive.hpp>
#include <client_thread.hpp>
#include <functional>

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <QThread>

int main(int argc, char** argv)
{
  if(!Aversive::init(argc, argv)) {
    std::cerr << "Error while initializing Aversive++" << std::endl;
    return EXIT_FAILURE;
  }
  
  bool keep_going = true;
  if(!ClientThread::instance().registerDevice("TESTER",
				   std::function<void(char*)>([&keep_going] (char* msg) mutable -> void {
				       if(strcmp(msg, "Stop") == 0) {
					 keep_going = false;
				       }
				       std::cout << "Received: " << msg << std::endl;
				     }))) {
    std::cerr << "Error while registering a new device" << std::endl;
    Aversive::exit();
    return EXIT_FAILURE;
  }
  
  ClientThread::instance().sendData("D TESTER I'm new");
  
  while(keep_going) {
    QThread::msleep(10);
  }
  
  Aversive::exit();
  return EXIT_SUCCESS;
}
