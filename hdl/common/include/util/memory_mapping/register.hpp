#ifndef REGISTER_HPP
#define REGISTER_HPP

#include <base/integer.hpp>

namespace MemoryMapping {

  //! \brief Wrapper class for memory addressed registers
  //! \param RegType : the register integer type
  //! \param Group : the register group
  /*!
   * Each register is in a group and can be used only
   * with other objects that belong to the same group.
   */
  template<typename RegType, typename Group>
  struct Register {
  public:
    //! \brief The address of the register
    const usys ADDRESS;

  public:
    //! \brief Constructor in the case the address is a pointer
    constexpr Register(RegType* const address);
    
    //! \brief Constructor in the case the address is a pointer to volatile
    constexpr Register(volatile RegType* const address);
    
    //! \brief Constructor in the case the address is a standard typed address
    constexpr Register(const usys address);

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
