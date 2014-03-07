#include <aversive.hpp>
#include <client_thread.hpp>
#include <cstdlib>
#include <iostream>
#include <QThread>

class AversiveClientThread : public ClientThread {
public:
  AversiveClientThread(void) : ClientThread() { }
  ~AversiveClientThread(void) { }
  
  void start(void) {
    ClientThread::start();
  }
  
  bool wait(unsigned long time = ULONG_MAX) {
    return ClientThread::wait(time);
  }

  void unlock(void) {
    _iteration.release();
  }
  
  void iterate(void) {
    // Let synchronize if we have finished
    if(_iteration.available() == 0) {
      sync();
    }
    _iteration.acquire();
  }
  
  static AversiveClientThread& instance(void) {
    return *((AversiveClientThread*) _inst);
  }
};

static bool initialized = false;
static bool running = false;
static int ret = 0;

void Aversive::init(void) {
  if(!initialized) {
    AversiveClientThread& client = *(new AversiveClientThread);
    client.start();
    running = initialized = true;
  }
}

bool Aversive::sync(void) {
  // Synchronisation
  AversiveClientThread& client = AversiveClientThread::instance();
  client.iterate();
  return Aversive::isRunning();
}

void Aversive::sleep(int ms) {
  (void) ms;
}

void Aversive::stop(void) {
  running = false;
  AversiveClientThread& client = AversiveClientThread::instance();
  client.unlock();
}

int Aversive::exit(void) {
  Aversive::stop();
  AversiveClientThread& client = AversiveClientThread::instance();
  client.sendData("S");
  client.wait();
  delete &client;
  return ret;
}

bool Aversive::isInitialized(void) {
  return initialized;
}

bool Aversive::isRunning(void) {
  return running;
}

int Aversive::returnCode(void) {
  return ret;
}

void Aversive::setReturnCode(int returnCode) {
  ret = returnCode;
}
