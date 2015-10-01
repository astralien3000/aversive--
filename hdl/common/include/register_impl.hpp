#ifndef REGISTER_IMPL_HPP
#define REGISTER_IMPL_HPP

#include "memory_mapping.hpp"

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
  inline constexpr Register<RegType, Group>::Register(const uintptr_t address)
    : ADDRESS(address) {
  }

// Assignment
#define OP =
#include "register_impl_assign.hpp"
#undef OP

#define OP |=
#include "register_impl_assign.hpp"
#undef OP

#define OP &=
#include "register_impl_assign.hpp"
#undef OP

#define OP ^=
#include "register_impl_assign.hpp"
#undef OP

#define OP <<=
#include "register_impl_assign.hpp"
#undef OP

#define OP >>=
#include "register_impl_assign.hpp"
#undef OP

#define OP +=
#include "register_impl_assign.hpp"
#undef OP

#define OP -=
#include "register_impl_assign.hpp"
#undef OP

#define OP *=
#include "register_impl_assign.hpp"
#undef OP

#define OP /=
#include "register_impl_assign.hpp"
#undef OP

#define OP %=
#include "register_impl_assign.hpp"
#undef OP

// Arithmetic
#define OP |
#include "register_impl_arith.hpp"
#undef OP

#define OP &
#include "register_impl_arith.hpp"
#undef OP

#define OP ^
#include "register_impl_arith.hpp"
#undef OP

#define OP <<
#include "register_impl_arith.hpp"
#undef OP

#define OP >>
#include "register_impl_arith.hpp"
#undef OP

#define OP +
#include "register_impl_arith.hpp"
#undef OP

#define OP -
#include "register_impl_arith.hpp"
#undef OP

#define OP *
#include "register_impl_arith.hpp"
#undef OP

#define OP /
#include "register_impl_arith.hpp"
#undef OP

#define OP %
#include "register_impl_arith.hpp"
#undef OP

}

#endif//REGISTER_IMPL_HPP
