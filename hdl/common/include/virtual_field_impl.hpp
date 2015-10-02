#ifndef VIRTUAL_FIELD_IMPL_HPP
#define VIRTUAL_FIELD_IMPL_HPP

#include "memory_mapping.hpp"

namespace MemoryMapping {

  template<typename Field, typename ... Next>
  inline constexpr VirtualField<Field,Next...>::VirtualField(Field field, Next... next)
    : FIELDS(field, next...) {
  }
  
  /*
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
  */

  template<typename Field, typename ... Next>
  constexpr VirtualField<Field, Next...> make_virtual_field(Field field, Next... next) {
    return VirtualField<Field, Next...>(field, next...);
  }
    
}

#endif//VIRTUAL_FIELD_IMPL_HPP
