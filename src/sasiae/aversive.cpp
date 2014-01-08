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
  
  static AversiveClientThread& instance(void) {
    return *((AversiveClientThread*) _inst);
  }
};

static bool keep_going;

inline bool aversiveInit(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  AversiveClientThread* client = new AversiveClientThread;
  client->start();
  keep_going = true;
  return true;
}

void Aversive::sleep(int ms) {
  // Do synchronisation stuff or simply wait if already synchronised
  (void) ms;
  QThread::sleep(0);
  return;
}

void Aversive::stop(void) {
  keep_going = false;
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
  if(!aversiveInit(argc, argv)) {
   std::cerr << "Error while initializing Aversive++" << std::endl;
    return EXIT_FAILURE;
  }
 
  if(!robotInit()) {
    std::cerr << "Error while initializing the robot" << std::endl;
    return EXIT_FAILURE;
  }
  
  while(keep_going) {
    robotLoop();
    Aversive::sleep(0);
  }
  
  robotExit();
  aversiveExit();
  return EXIT_SUCCESS;
}
