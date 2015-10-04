#ifndef FIELD_IMPL_HPP
#define FIELD_IMPL_HPP

#include "memory_mapping.hpp"

namespace MemoryMapping {

  template<typename RegType, typename Group, RegType MASK>
  inline constexpr Field<RegType, Group, MASK>::Field(const Register<RegType, Group> reg)
    : REGISTER(reg) {
  }

// Assignment
#define OP =
#include "field_impl_assign.hpp"
#undef OP

#define OP |=
#include "field_impl_assign.hpp"
#undef OP

#define OP &=
#include "field_impl_assign.hpp"
#undef OP

#define OP ^=
#include "field_impl_assign.hpp"
#undef OP

#define OP <<=
#include "field_impl_assign.hpp"
#undef OP

#define OP >>=
#include "field_impl_assign.hpp"
#undef OP

#define OP +=
#include "field_impl_assign.hpp"
#undef OP

#define OP -=
#include "field_impl_assign.hpp"
#undef OP

#define OP *=
#include "field_impl_assign.hpp"
#undef OP

#define OP /=
#include "field_impl_assign.hpp"
#undef OP

#define OP %=
#include "field_impl_assign.hpp"
#undef OP

// Arithmetic
#define OP |
#include "field_impl_arith.hpp"
#undef OP

#define OP &
#include "field_impl_arith.hpp"
#undef OP

#define OP ^
#include "field_impl_arith.hpp"
#undef OP

#define OP <<
#include "field_impl_arith.hpp"
#undef OP

#define OP >>
#include "field_impl_arith.hpp"
#undef OP

#define OP +
#include "field_impl_arith.hpp"
#undef OP

#define OP -
#include "field_impl_arith.hpp"
#undef OP

#define OP *
#include "field_impl_arith.hpp"
#undef OP

#define OP /
#include "field_impl_arith.hpp"
#undef OP

#define OP %
#include "field_impl_arith.hpp"
#undef OP

}

#endif//FIELD_IMPL_HPP
