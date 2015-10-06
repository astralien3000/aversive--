#ifndef BITFIELD_IMPL_HPP
#define BITFIELD_IMPL_HPP

namespace MemoryMapping {

  template<typename RegType, typename Group, int BITNUM>
  inline constexpr BitField<RegType, Group, BITNUM>::BitField(const Register<RegType, Group>& reg)
    : REGISTER(reg) {
  }

  // Assignment

  template<typename RegType, typename Group, int BITNUM>
  inline const BitField<RegType, Group, BITNUM>& BitField<RegType, Group, BITNUM>::operator=(const Config<RegType, Group, (1<<BITNUM)>& cfg) const {
    REGISTER = (REGISTER & ~(1 << BITNUM)) | cfg.VALUE;
    return *this;
  }

  template<typename RegType, typename Group, int BITNUM>
  inline const BitField<RegType, Group, BITNUM>& BitField<RegType, Group, BITNUM>::operator=(const BitField<RegType, Group, BITNUM>& bf) const {
    REGISTER = (REGISTER & ~(1 << BITNUM)) | (bf.REGISTER & (1 << BITNUM));
    return *this;
  }

  template<typename RegType, typename Group, int BITNUM> template<int OTHER_BITNUM>
  inline const BitField<RegType, Group, BITNUM>& BitField<RegType, Group, BITNUM>::operator=(const BitField<RegType, Group, OTHER_BITNUM>& bf) const {
    REGISTER = (REGISTER & ~(1 << BITNUM)) | (((bf.REGISTER >> OTHER_BITNUM) & 1) << BITNUM);
    return *this;
  }

  template<typename RegType, typename Group, int BITNUM>
  inline const BitField<RegType, Group, BITNUM>& BitField<RegType, Group, BITNUM>::operator=(const bool val) const {
    
    if(val) {
      REGISTER |= (1 << BITNUM);
    }
    else {
      REGISTER &= (RegType)(~(1 << BITNUM));
    }
    
    /*
    const RegType v = val?1:0;
    REGISTER = (REGISTER & ~(1 << BITNUM)) | (v << BITNUM);
    */
    return *this;
  }

  template<typename RegType, typename Group, int BITNUM>
  BitField<RegType, Group, BITNUM>::operator bool(void) const {
    return (REGISTER >> BITNUM) & 1;
  }

  // Logic
  #define OP &&
  #include "bitfield_impl_logic.hpp"
  #undef OP

  #define OP ||
  #include "bitfield_impl_logic.hpp"
  #undef OP


}

#endif//BITFIELD_IMPL_HPP
