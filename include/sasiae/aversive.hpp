#ifndef SASIAE_AVERSIVE_HPP
#define SASIAE_AVERSIVE_HPP

#include "../common/aversive.hpp"

#include <base/singleton.hpp>

extern void aversiveInit(void);

// A class defined to correctly init the ClientThread before creating any Device.
class AversiveInitializer : public Singleton<AversiveInitializer> {
  friend class Singleton<AversiveInitializer>;
private:
  inline AversiveInitializer() {
    aversiveInit();
  }
};

#endif//SASIAE_AVERSIVE_HPP
