#include <aversive.hpp>
#include <client_thread.hpp>
#include <iostream>

bool Aversive::init(int argc, char** argv) {
  if(argc == 1) {
    return false;
  }
  else {
    ClientThread& client = ClientThread::instance();
    client.setId(argv[1]);
    client.start();
    while(!client.isReady()) {
      QThread::msleep(10);
    }
    return true;
  }
}

void Aversive::sleep(int ms) {
  // Do synchronisation stuff or simply wait if already synchronised
  (void) ms;
  return;
}

void Aversive::exit(void) {
  // Do stuff to free used memory or anything else that would need to be end properly
  ClientThread& client = ClientThread::instance();
  client.quit();
  client.wait();
  return;
}
