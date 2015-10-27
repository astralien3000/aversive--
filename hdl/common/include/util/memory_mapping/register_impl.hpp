#ifndef REGISTER_IMPL_HPP
#define REGISTER_IMPL_HPP

#include <base/integer.hpp>

namespace MemoryMapping {

  template<typename RegType, typename Group>
  inline const RegType VAL(const Register<RegType, Group>& reg) {
    return *(volatile RegType*)reg.ADDRESS;
  }

  template<typename RegType, typename Group>
  inline constexpr Register<RegType, Group>::Register(RegType* const address)
    : ADDRESS((uintptr_t)address) {
  }

  template<typename RegType, typename Group>
  inline constexpr Register<RegType, Group>::Register(volatile RegType* const address)
      : ADDRESS((uintptr_t)address) {
  }

  template<typename RegType, typename Group>
  inline constexpr Register<RegType, Group>::Register(const usys address)
    : ADDRESS(address) {
  }

// Assignment
#define MACRO_DEFINE_ASSIGN(op)			\
  template<typename RegType, typename Group> template<typename OtherRegType, typename OtherGroup, RegType MASK> inline const Register<RegType, Group>& Register<RegType, Group>::operator op(const Config<OtherRegType, OtherGroup, MASK>& ) const { static_assert(!sizeof(RegType) && sizeof(RegType), "Incompatibles Register and Config"); return *this; } \
  template<typename RegType, typename Group> template<RegType MASK> inline const Register<RegType, Group>& Register<RegType, Group>::operator op(const Config<RegType, Group, MASK>& cfg) const { *(volatile RegType*)ADDRESS op cfg.VALUE; return *this; } \
  template<typename RegType, typename Group> template<typename OtherRegType, typename OtherGroup> inline const Register<RegType, Group>& Register<RegType, Group>::operator op(const Register<OtherRegType, OtherGroup>& ) const { static_assert(!sizeof(RegType) && sizeof(RegType), "Incompatibles Registers"); return *this; } \
  template<typename RegType, typename Group> inline const Register<RegType, Group>& Register<RegType, Group>::operator op(const Register<RegType, Group>& reg) const { *(volatile RegType*)ADDRESS op *(RegType*)reg.ADDRESS; return *this; } \
  template<typename RegType, typename Group> inline const Register<RegType, Group>& Register<RegType, Group>::operator op(const RegType val) const { *(volatile RegType*)ADDRESS op val; return *this; }

  MACRO_DEFINE_ASSIGN(=);
  MACRO_DEFINE_ASSIGN(|=);
  MACRO_DEFINE_ASSIGN(&=);
  MACRO_DEFINE_ASSIGN(^=);

#undef MACRO_DEFINE_ASSIGN

// Arithmetic
#define MACRO_DEFINE_ARITH(op)			\
  template<typename RegType, typename Group> template<typename OtherRegType, typename OtherGroup, RegType MASK> inline const RegType Register<RegType, Group>::operator op(const Config<OtherRegType, OtherGroup, MASK>& ) const { static_assert(!sizeof(RegType) && sizeof(RegType), "Incompatibles Register and Config"); return 0; } \
  template<typename RegType, typename Group> template<RegType MASK> inline const RegType Register<RegType, Group>::operator op(const Config<RegType, Group, MASK>& cfg) const { return *(volatile RegType*)ADDRESS op cfg.VALUE; } \
  template<typename RegType, typename Group> template<typename OtherRegType, typename OtherGroup> inline const RegType Register<RegType, Group>::operator op(const Register<OtherRegType, OtherGroup>& ) const { static_assert(!sizeof(RegType) && sizeof(RegType), "Incompatibles Registers"); return 0; } \
  template<typename RegType, typename Group> inline const RegType Register<RegType, Group>::operator op(const Register<RegType, Group>& reg) const { return *(volatile RegType*)ADDRESS op *(volatile RegType*)reg.ADDRESS; } \
  template<typename RegType, typename Group> inline const RegType Register<RegType, Group>::operator op(const RegType val) const { return *(volatile RegType*)ADDRESS op val; }

  MACRO_DEFINE_ARITH(|);
  MACRO_DEFINE_ARITH(&);
  MACRO_DEFINE_ARITH(^);

  template<typename RegType, typename Group> inline const RegType Register<RegType, Group>::operator<<(const RegType val) const { return *(volatile RegType*)ADDRESS << val; }
  template<typename RegType, typename Group> inline const RegType Register<RegType, Group>::operator>>(const RegType val) const { return *(volatile RegType*)ADDRESS >> val; }
}

#endif//REGISTER_IMPL_HPP
