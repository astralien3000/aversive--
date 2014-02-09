#include <aversive.hpp>
#include <client_thread.hpp>
#include <cstdlib>
#include <iostream>
#include <QThread>

#include <device/device.hpp>

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

static bool keep_going;

void aversiveInit(void) {
  AversiveClientThread* client = new AversiveClientThread;
  client->start();
  keep_going = true;
}

void Aversive::sleep(int ms) {
  // Do synchronisation stuff
  (void) ms;
  AversiveClientThread* client = &AversiveClientThread::instance();
  client->iterate();
  return;
}

void Aversive::stop(void) {
  keep_going = false;
  AversiveClientThread* client = &AversiveClientThread::instance();
  client->unlock();
}

inline void aversiveExit(void) {
  Aversive::stop();
  AversiveClientThread* client = &AversiveClientThread::instance();
  client->sendData("S");
  client->wait();
  delete client;
  return;
}

int main(int argc, char** argv) {
  (void)argc;
  (void)argv;
  
  // To call aversiveInit even if there is no Device
  (void)AversiveInitializer::instance();

  if(!robotInit()) {
    std::cerr << "Error while initializing the robot" << std::endl;
    return EXIT_FAILURE;
  }
  
  while(keep_going) {
    Aversive::sleep(0);
    if(!keep_going) {
      break;
    }
    robotLoop();
  }
  
  robotExit();
  aversiveExit();
  return EXIT_SUCCESS;
}
