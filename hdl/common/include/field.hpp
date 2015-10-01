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
    
    // Assignment
    #define OP =
    #include "field_decl_assign.hpp"
    #undef OP

    #define OP |=
    #include "field_decl_assign.hpp"
    #undef OP

    #define OP &=
    #include "field_decl_assign.hpp"
    #undef OP

    #define OP ^=
    #include "field_decl_assign.hpp"
    #undef OP

    #define OP <<=
    #include "field_decl_assign.hpp"
    #undef OP

    #define OP >>=
    #include "field_decl_assign.hpp"
    #undef OP

    #define OP +=
    #include "field_decl_assign.hpp"
    #undef OP

    #define OP -=
    #include "field_decl_assign.hpp"
    #undef OP

    #define OP *=
    #include "field_decl_assign.hpp"
    #undef OP

    #define OP /=
    #include "field_decl_assign.hpp"
    #undef OP

    #define OP %=
    #include "field_decl_assign.hpp"
    #undef OP

    // Arithmetic
    #define OP |
    #include "field_decl_arith.hpp"
    #undef OP

    #define OP &
    #include "field_decl_arith.hpp"
    #undef OP

    #define OP ^
    #include "field_decl_arith.hpp"
    #undef OP

    #define OP <<
    #include "field_decl_arith.hpp"
    #undef OP

    #define OP >>
    #include "field_decl_arith.hpp"
    #undef OP

    #define OP +
    #include "field_decl_arith.hpp"
    #undef OP

    #define OP -
    #include "field_decl_arith.hpp"
    #undef OP

    #define OP *
    #include "field_decl_arith.hpp"
    #undef OP

    #define OP /
    #include "field_decl_arith.hpp"
    #undef OP

    #define OP %
    #include "field_decl_arith.hpp"
    #undef OP

  };

}

#endif//FIELD_HPP
