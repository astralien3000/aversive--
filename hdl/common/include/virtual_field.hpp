#ifndef VIRTUAL_FIELD_HPP
#define VIRTUAL_FIELD_HPP

#include "memory_mapping.hpp"
#include "static_list.hpp"

namespace MemoryMapping {

  template<typename Field, typename ... Next>
  struct VirtualField {
  public:
    StaticList<Field, Next...> FIELDS;
    
  public:
    constexpr VirtualField(Field field, Next... next);
    /*
    // Assignment
    #define OP =
    #include "virtual_field_decl_assign.hpp"
    #undef OP

    #define OP |=
    #include "virtual_field_decl_assign.hpp"
    #undef OP

    #define OP &=
    #include "virtual_field_decl_assign.hpp"
    #undef OP

    #define OP ^=
    #include "virtual_field_decl_assign.hpp"
    #undef OP

    #define OP <<=
    #include "virtual_field_decl_assign.hpp"
    #undef OP

    #define OP >>=
    #include "virtual_field_decl_assign.hpp"
    #undef OP

    #define OP +=
    #include "virtual_field_decl_assign.hpp"
    #undef OP

    #define OP -=
    #include "virtual_field_decl_assign.hpp"
    #undef OP

    #define OP *=
    #include "virtual_field_decl_assign.hpp"
    #undef OP

    #define OP /=
    #include "virtual_field_decl_assign.hpp"
    #undef OP

    #define OP %=
    #include "virtual_field_decl_assign.hpp"
    #undef OP

    // Arithmetic
    #define OP |
    #include "virtual_field_decl_arith.hpp"
    #undef OP

    #define OP &
    #include "virtual_field_decl_arith.hpp"
    #undef OP

    #define OP ^
    #include "virtual_field_decl_arith.hpp"
    #undef OP

    #define OP <<
    #include "virtual_field_decl_arith.hpp"
    #undef OP

    #define OP >>
    #include "virtual_field_decl_arith.hpp"
    #undef OP

    #define OP +
    #include "virtual_field_decl_arith.hpp"
    #undef OP

    #define OP -
    #include "virtual_field_decl_arith.hpp"
    #undef OP

    #define OP *
    #include "virtual_field_decl_arith.hpp"
    #undef OP

    #define OP /
    #include "virtual_field_decl_arith.hpp"
    #undef OP

    #define OP %
    #include "virtual_field_decl_arith.hpp"
    #undef OP
    */
  };
  
  template<typename Field, typename ... Next>
  constexpr VirtualField<Field, Next...> make_virtual_field(Field field, Next... next);
  
}

#endif//VIRTUAL_FIELD_HPP
