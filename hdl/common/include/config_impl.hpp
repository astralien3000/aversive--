#ifndef CONFIG_IMPL_HPP
#define CONFIG_IMPL_HPP

namespace MemoryMapping {

  template<typename RegType, typename Group, RegType MASK>
  inline constexpr Config<RegType, Group, MASK>::Config(const RegType value)
    : VALUE(value) {
  }

  template<typename RegType, typename Group, RegType MASK>
  inline constexpr Config<RegType, Group, MASK>::Config(const Config& other)
    : VALUE(other.VALUE) {
  }

  // WARNING ! this code is only compatible with GCC !
  template<typename RegType, typename Group, typename ValType>
  inline constexpr Config<RegType, Group, IntegerInfo<sizeof(RegType)>::UNSIGNED_MAX> make_config(__attribute__((unused)) const Register<RegType, Group>& reg, const ValType value) {
    return Config<RegType, Group, IntegerInfo<sizeof(RegType)>::UNSIGNED_MAX>((RegType)value);
  }

  // WARNING ! this code is only compatible with GCC !
  template<typename RegType, typename Group, RegType MASK, typename ValType>
  inline constexpr Config<RegType, Group, MASK> make_config(__attribute__((unused)) const Field<RegType, Group, MASK>& field, const ValType value) {
    return Config<RegType, Group, MASK>(Private::field_value(MASK, (RegType)value));
  }

  // WARNING ! this code is only compatible with GCC !
  template<typename RegType, typename Group, int BITNUM>
  inline constexpr Config<RegType, Group, (1<<BITNUM)> make_config(__attribute__((unused)) const BitField<RegType, Group, BITNUM>& bf, const bool value) {
    return Config<RegType, Group, (1<<BITNUM)>(value?0:(1<<BITNUM));
  }

#define OP |
#include "config_impl_arith.hpp"
#undef OP

#define OP &
#include "config_impl_arith.hpp"
#undef OP

#define OP ^
#include "config_impl_arith.hpp"
#undef OP

#define OP <<
#include "config_impl_arith.hpp"
#undef OP

#define OP >>
#include "config_impl_arith.hpp"
#undef OP

#define OP +
#include "config_impl_arith.hpp"
#undef OP

#define OP -
#include "config_impl_arith.hpp"
#undef OP

#define OP *
#include "config_impl_arith.hpp"
#undef OP

#define OP /
#include "config_impl_arith.hpp"
#undef OP

#define OP %
#include "config_impl_arith.hpp"
#undef OP


}

#endif//CONFIG_IMPL_HPP
