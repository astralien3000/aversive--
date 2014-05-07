#ifndef XMEM_HPP
#define XMEM_HPP

#include <base/singleton.hpp>
#include "architecture.hpp"

class Xmem : public Singleton<Xmem> {
  friend class Singleton<Xmem>;

private:
  //! \brief Private Default Constructor
Xmem(void) {}

public:
  //! \brief Enable external memory management
  void init(void) {
    REG(xmem<0>::control) |= CFG(xmem<0>::control::enable);
    REG(xmem<0>::control) |= CFG(xmem<0>::control::defaultwait);  
  }
  
  //! \brief Disable external memory management
  void quit(void);
};

#endif//XMEM_HPP
