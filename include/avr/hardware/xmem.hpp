#ifndef AVR_XMEM_HPP
#define AVR_XMEM_HPP

#include "../../common/hardware/xmem.hpp"
#include "architecture.hpp"

Xmem::Xmem(void) {}

void Xmem::init(void) {
  REG(xmem<0>::control) |= CFG(xmem<0>::control::enable);
  REG(xmem<0>::control) |= CFG(xmem<0>::control::defaultwait);  
}

#endif//AVR_XMEM_HPP
