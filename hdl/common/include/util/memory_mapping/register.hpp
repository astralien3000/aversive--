#ifndef REGISTER_HPP
#define REGISTER_HPP

namespace MemoryMapping {

  template<typename RegType, typename Group>
  struct Register {
  public:
    const uintptr_t ADDRESS;

  public:
    constexpr Register(RegType* const address);
    constexpr Register(volatile RegType* const address);
    constexpr Register(const uintptr_t address);

    // Assignment
    #define OP =
    #include "register_decl_assign.hpp"
    #undef OP

    #define OP |=
    #include "register_decl_assign.hpp"
    #undef OP

    #define OP &=
    #include "register_decl_assign.hpp"
    #undef OP

    #define OP ^=
    #include "register_decl_assign.hpp"
    #undef OP

    #define OP <<=
    #include "register_decl_assign.hpp"
    #undef OP

    #define OP >>=
    #include "register_decl_assign.hpp"
    #undef OP

    #define OP +=
    #include "register_decl_assign.hpp"
    #undef OP

    #define OP -=
    #include "register_decl_assign.hpp"
    #undef OP

    #define OP *=
    #include "register_decl_assign.hpp"
    #undef OP

    #define OP /=
    #include "register_decl_assign.hpp"
    #undef OP

    #define OP %=
    #include "register_decl_assign.hpp"
    #undef OP

    // Arithmetic
    #define OP |
    #include "register_decl_arith.hpp"
    #undef OP

    #define OP &
    #include "register_decl_arith.hpp"
    #undef OP

    #define OP ^
    #include "register_decl_arith.hpp"
    #undef OP

    #define OP <<
    #include "register_decl_arith.hpp"
    #undef OP

    #define OP >>
    #include "register_decl_arith.hpp"
    #undef OP

    #define OP +
    #include "register_decl_arith.hpp"
    #undef OP

    #define OP -
    #include "register_decl_arith.hpp"
    #undef OP

    #define OP *
    #include "register_decl_arith.hpp"
    #undef OP

    #define OP /
    #include "register_decl_arith.hpp"
    #undef OP

    #define OP %
    #include "register_decl_arith.hpp"
    #undef OP

  };

}

#endif//REGISTER_HPP
