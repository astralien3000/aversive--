#ifndef REGISTER_HPP
#define REGISTER_HPP

#include "memory_mapping.hpp"

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
    constexpr Register(RegType* const address)
      : ADDRESS((usys)address) {
    }
    
    //! \brief Constructor in the case the address is a pointer to volatile
    constexpr Register(volatile RegType* const address)
      : ADDRESS((usys)address) {
    }
    
    //! \brief Constructor in the case the address is a standard typed address
    constexpr Register(const usys address)
      : ADDRESS(address) {
    }

    // Assignment
#define MACRO_DECLARE_ASSIGN(op)					\
    template<typename OtherRegType, typename OtherGroup, RegType MASK>  \
    const Register& operator op(const Config<OtherRegType, OtherGroup, MASK>& cfg) const { \
      static_assert(!sizeof(RegType) && sizeof(RegType),		\
		    "Incompatibles Register and Config");		\
      return *this;							\
    }									\
    template<RegType MASK>						\
    const Register& operator op(const Config<RegType, Group, MASK>& cfg) const { \
      *(volatile RegType*)ADDRESS op cfg.VALUE;				\
      return *this;							\
    }									\
    template<typename OtherRegType, typename OtherGroup>		\
    const Register& operator op(const Register<OtherRegType, OtherGroup>& reg) const { \
      static_assert(!sizeof(RegType) && sizeof(RegType),		\
		    "Incompatibles Registers");				\
      return *this;							\
    }									\
    const Register& operator op(const Register<RegType, Group>& reg) const { \
      *(volatile RegType*)ADDRESS op *(RegType*)reg.ADDRESS;		\
      return *this;							\
    }									\
    const Register& operator op(const RegType val) const {		\
      *(volatile RegType*)ADDRESS op val;				\
      return *this;							\
    }									\

    MACRO_DECLARE_ASSIGN(=);
    MACRO_DECLARE_ASSIGN(|=);
    MACRO_DECLARE_ASSIGN(&=);
    MACRO_DECLARE_ASSIGN(^=);

#undef MACRO_DECLARE_ASSIGN
    
    // Arithmetic
#define MACRO_DECLARE_ARITH(op)			\
    template<typename OtherRegType, typename OtherGroup, RegType MASK>	\
    const RegType operator op(const Config<OtherRegType, OtherGroup, MASK>& cfg) const { \
      static_assert(!sizeof(RegType) && sizeof(RegType),		\
		    "Incompatibles Register and Config");		\
      return 0;								\
    }									\
    template<RegType MASK>						\
    const RegType operator op(const Config<RegType, Group, MASK>& cfg) const { \
      return *(volatile RegType*)ADDRESS op cfg.VALUE;			\
    }									\
    template<typename OtherRegType, typename OtherGroup>		\
    const RegType operator op(const Register<OtherRegType, OtherGroup>& reg) const { \
      static_assert(!sizeof(RegType) && sizeof(RegType),		\
		    "Incompatibles Registers");				\
      return 0;								\
    }									\
    const RegType operator op(const Register<RegType, Group>& reg) const { \
      return								\
	*(volatile RegType*)ADDRESS op *(volatile RegType*)reg.ADDRESS; \
    }									\
    const RegType operator op(const RegType val) const {		\
      return *(volatile RegType*)ADDRESS op val;			\
    }

    MACRO_DECLARE_ARITH(|);
    MACRO_DECLARE_ARITH(&);
    MACRO_DECLARE_ARITH(^);

#undef MACRO_DECLARE_ARITH

    const RegType operator>>(const RegType val) const {
      return *(volatile RegType*)ADDRESS >> val;
    }
    
    const RegType operator<<(const RegType val) const {
      return *(volatile RegType*)ADDRESS << val;
    }

    const RegType operator~(void) const {
      return ~(*(volatile RegType*)ADDRESS);
    }

#define MACRO_DECLARE_COMPAR(op)					\
    bool operator op(const Register& reg) const {			\
      return VAL(*this) op VAL(reg);					\
    }									\
    template<RegType MASK>						\
    bool operator op(const Config<RegType, Group, MASK>& cfg) const {	\
      static_assert(MASK == Integer<sizeof(RegType)*8>::MAX_UNSIGNED,	\
		    "Can't compare a partial config to this register");	\
      return VAL(*this) op VAL(cfg);					\
    }									\
    bool operator op(const RegType val) const {				\
      return VAL(*this) op val;						\
    }
    
    MACRO_DECLARE_COMPAR(==);
    MACRO_DECLARE_COMPAR(!=);
    
#undef MACRO_DECLARE_COMPAR
    
  };

  //! \brief Return the Register's value
  template<typename RegType, typename Group>
  inline const RegType VAL(const Register<RegType, Group>& reg) {
    return *(volatile RegType*)reg.ADDRESS;
  }
}

#endif//REGISTER_HPP
