#ifndef REGISTER_HPP
#define REGISTER_HPP

#include "config.hpp"

template<int SIZE, int ID>
class Register {
  const int reg_size;
  typename Integer<SIZE>::Unsigned* const reg[3];
public:
  inline Register(void);
  
  template<typename Config>
  inline Register& operator=(const Config& cfg) {
    for(int i = 0 ; i < reg_size ; i++) {
      *reg[i] = cfg.value(i);
    }
    return *this;
  }

  template<typename Config>
  inline Register& operator|=(const Config& cfg) {
    for(int i = 0 ; i < reg_size ; i++) {
      *reg[i] |= cfg.value(i);
    }
    return *this;
  }

  template<typename Config>
  inline Register& operator&=(const Config& cfg) {
    for(int i = 0 ; i < reg_size ; i++) {
      *reg[i] &= cfg.value(i);
    }
    return *this;
  }
};

#define REG(r) Register<r::SIZE, r::REG>()

#endif//REGISTER_HPP
