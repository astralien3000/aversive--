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
#define MACRO_DECLARE_ASSIGN(op)					\
    template<typename OtherRegType, typename OtherGroup, RegType MASK> const Register& operator op(const Config<OtherRegType, OtherGroup, MASK>& cfg) const; \
    template<RegType MASK> const Register& operator op(const Config<RegType, Group, MASK>& cfg) const; \
    template<typename OtherRegType, typename OtherGroup> const Register& operator op(const Register<OtherRegType, OtherGroup>& reg) const; \
    const Register& operator op(const Register<RegType, Group>& reg) const; \
    const Register& operator op(const RegType val) const;		\

    MACRO_DECLARE_ASSIGN(=);
    MACRO_DECLARE_ASSIGN(|=);
    MACRO_DECLARE_ASSIGN(&=);
    MACRO_DECLARE_ASSIGN(^=);

#undef MACRO_DECLARE_ASSIGN
    
    // Arithmetic
#define MACRO_DECLARE_ARITH(op)			\
    template<typename OtherRegType, typename OtherGroup, RegType MASK> const RegType operator op(const Config<OtherRegType, OtherGroup, MASK>& cfg) const; \
    template<RegType MASK> const RegType operator op(const Config<RegType, Group, MASK>& cfg) const; \
    template<typename OtherRegType, typename OtherGroup> const RegType operator op(const Register<OtherRegType, OtherGroup>& reg) const; \
    const RegType operator op(const Register<RegType, Group>& reg) const; \
    const RegType operator op(const RegType val) const;

    MACRO_DECLARE_ARITH(|);
    MACRO_DECLARE_ARITH(&);
    MACRO_DECLARE_ARITH(^);

    const RegType operator>>(const RegType val) const;
    const RegType operator<<(const RegType val) const;

#undef MACRO_DECLARE_ARITH

    
  };

  //! \brief Return the Register's value
  template<typename RegType, typename Group>
  inline const RegType VAL(const Register<RegType, Group>& reg);
}

#endif//REGISTER_HPP
