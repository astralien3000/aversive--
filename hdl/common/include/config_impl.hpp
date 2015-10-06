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

  template<typename RegType, typename Group, typename ValType>
  inline constexpr Config<RegType, Group, IntegerInfo<sizeof(RegType)>::UNSIGNED_MAX> make_config(const Register<RegType, Group>& , const ValType value) {
    return Config<RegType, Group, IntegerInfo<sizeof(RegType)>::UNSIGNED_MAX>((RegType)value);
  }

  template<typename RegType, typename Group, RegType MASK, typename ValType>
  inline constexpr Config<RegType, Group, MASK> make_config(const Field<RegType, Group, MASK>& , const ValType value) {
    return Config<RegType, Group, MASK>(Private::field_value(MASK, (RegType)value));
  }

  template<typename RegType, typename Group, int BITNUM>
  inline constexpr Config<RegType, Group, (1<<BITNUM)> make_config(const BitField<RegType, Group, BITNUM>& , const bool value) {
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
