#include <aversive.hpp>
#include <client_thread.hpp>

#include <functional>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <QThread>

bool robotInit(void) {
  bool ok = ClientThread::instance().
    registerDevice("TESTER",
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
  return ok;
}

void robotLoop(void) {
  return;
}

void robotExit(void) {
  return;
}
