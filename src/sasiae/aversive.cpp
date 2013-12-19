#include <aversive.hpp>
#include <client_thread.hpp>
#include <iostream>

class AversiveClientThread : public ClientThread {
public:
  AversiveClientThread(void) : ClientThread() { }
  ~AversiveClientThread(void) { }
  
  void quit(void) {
    _keep_going = true;
  }
  
  void start(void) {
    ClientThread::start();
  }
  
  bool wait(unsigned long time = ULONG_MAX) {
    return ClientThread::wait(time);
  }
  
  bool isFinished(void) const {
    return ClientThread::isFinished();
  }
  
  bool isRunning(void) const {
    return ClientThread::isRunning();
  }
  
  static AversiveClientThread* instance(void) {
    return (AversiveClientThread*) _this;
  }
};

bool Aversive::init(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  AversiveClientThread* client = new AversiveClientThread;
  client->start();
  return true;
}

void Aversive::sleep(int ms) {
  // Do synchronisation stuff or simply wait if already synchronised
  (void) ms;
  return;
}

void Aversive::exit(void) {
  AversiveClientThread* client = AversiveClientThread::instance();
  client->quit();
  client->wait();
  delete client;
  return;
}
