#ifndef FIELD_HPP
#define FIELD_HPP

#include "memory_mapping.hpp"

namespace MemoryMapping {

  template<typename RegType, typename Group, RegType MASK>
  struct Field {
  public:
    const Register<RegType, Group>& REGISTER;

  public:
    constexpr Field(const Register<RegType, Group>& reg);
  };

}

#endif//FIELD_HPP
