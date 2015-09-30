#ifndef CONFIG_HPP
#define CONFIG_HPP

#include "memory_mapping.hpp"

namespace MemoryMapping {

  template<typename RegType, typename Group, RegType MASK>
  struct Config {
  public:
    const RegType VALUE;

  public:
    constexpr Config(const RegType value);
    constexpr Config(const Config& other);

    // Arithmetic
    #define OP |
    #include "config_decl_arith.hpp"
    #undef OP

    #define OP &
    #include "config_decl_arith.hpp"
    #undef OP

    #define OP ^
    #include "config_decl_arith.hpp"
    #undef OP

    #define OP <<
    #include "config_decl_arith.hpp"
    #undef OP

    #define OP >>
    #include "config_decl_arith.hpp"
    #undef OP

    #define OP +
    #include "config_decl_arith.hpp"
    #undef OP

    #define OP -
    #include "config_decl_arith.hpp"
    #undef OP

    #define OP *
    #include "config_decl_arith.hpp"
    #undef OP

    #define OP /
    #include "config_decl_arith.hpp"
    #undef OP

    #define OP %
    #include "config_decl_arith.hpp"
    #undef OP

  };

  template<typename RegType, typename Group, typename ValType>
  constexpr Config<RegType, Group, IntegerInfo<sizeof(RegType)>::UNSIGNED_MAX> make_config(const Register<RegType, Group>& reg, const ValType value);

  template<typename RegType, typename Group, RegType MASK, typename ValType>
  constexpr Config<RegType, Group, MASK> make_config(const Field<RegType, Group, MASK>& field, const ValType value);

  template<typename RegType, typename Group, int BITNUM>
  constexpr Config<RegType, Group, (1<<BITNUM)> make_config(const BitField<RegType, Group, BITNUM>& bf, const bool value);

}

#endif//CONFIG_HPP
