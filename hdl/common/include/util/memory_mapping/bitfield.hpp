#ifndef BITFIELD_HPP
#define BITFIELD_HPP

namespace MemoryMapping {

  template<typename RegType, typename Group, int BITNUM>
  struct BitField {
  public:
    const Register<RegType, Group>& REGISTER;

  public:
    constexpr BitField(const Register<RegType, Group>& reg);

    operator bool(void) const;

    // Assignment
    const BitField& operator=(const Config<RegType, Group, (1<<BITNUM)>& cfg) const;
    const BitField& operator=(const BitField<RegType, Group, BITNUM>& bf) const;
    template<int OTHER_BITNUM> const BitField& operator=(const BitField<RegType, Group, OTHER_BITNUM>& bf) const;
    const BitField& operator=(const bool val) const;

    // Logic
    #define OP &&
    #include "bitfield_decl_logic.hpp"
    #undef OP

    #define OP ||
    #include "bitfield_decl_logic.hpp"
    #undef OP

  };

}

#endif//BITFIELD_HPP
