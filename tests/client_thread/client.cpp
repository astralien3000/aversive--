#include <aversive.hpp>
#include <client_thread.hpp>

#include <functional>
#include <cstdlib>
#include <cstring>
#include <iostream>

bool robotInit(void) {
  return ClientThread::instance().
    registerDevice("TESTER",
		   std::function<void(char*)>([] (char* msg) mutable -> void {
		       if(strcmp(msg, "Stop") == 0) {
			 Aversive::stop();
		       }
		       std::cout << "Received: " << msg << std::endl;
		     }));
}

void robotLoop(void) {
  return;
}

void robotExit(void) {
  return;
}
