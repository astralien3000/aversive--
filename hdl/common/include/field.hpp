#ifndef FIELD_HPP
#define FIELD_HPP

#include "memory_mapping.hpp"

namespace MemoryMapping {

  template<typename RegType, typename Group, RegType MASK>
  struct Field {
  public:
    const Register<RegType, Group> REGISTER;

  public:
    constexpr Field(const Register<RegType, Group> reg);
    
    // Assignment
    const Field& operator=(const Config<RegType, Group, MASK>& cfg) const;
    const Field& operator=(const Field<RegType, Group, MASK>& field) const;
    const Field& operator=(const RegType val) const;

  };

}

#endif//FIELD_HPP
