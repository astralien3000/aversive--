#ifndef SASIAE_AVERSIVE_CLIENT_THREAD_HPP
#define SASIAE_AVERSIVE_CLIENT_THREAD_HPP

#include <client_thread.hpp>

class AversiveClientThread {
public:
  AversiveClientThread(void);
  ~AversiveClientThread(void);
  
  void start(void);
  void quit(void);
  bool isGoing(void);

protected:
  void run(void);
};

#endif//SASIAE_AVERSIVE_CLIENT_THREAD_HPP
