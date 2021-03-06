#ifndef CONFIG_HPP
#define CONFIG_HPP

#include "memory_mapping.hpp"

namespace MemoryMapping {

  //! \brief This class represents a value that a Register can take
  /*!
   * The value is associated to a mask, so that the configuration can be used with a Field, a BitField or a Register.
   * The mask will be used to check if the configuration is compatible with a Field or a BitField.
   */
  template<typename RegType, typename Group, RegType MASK>
  struct Config {
  public:
    //! \brief The value that the Register would take if the configuration was assigned to this Register.
    const RegType VALUE;

  public:
    //! \brief Constructor
    //! \param value : The value that the Register would take if the configuration was assigned to this Register.
    //! \warning AVOID TO USE
    /*!
     * This constructor will create a configuration without checking the compatibility of the value with the MASK.
     * Please, use MemoryMapping::make_config function instead.
     */
    constexpr Config(const RegType value)
      : VALUE(value) {
    }

    //! \brief Copy Constructor
    constexpr Config(const Config& other)
      : VALUE(other.VALUE) {
    }

    // Arithmetic

    //! \brief This macro helps to declare some bitwise operator methods
#define MACRO_DECLARE_BITWISE(op)					\
    template<typename OtherRegType, typename OtherGroup, OtherRegType OTHER_MASK> \
    constexpr Config<RegType, Group, MASK | OTHER_MASK> operator op(const Config<OtherRegType, OtherGroup, OTHER_MASK>& cfg) const { \
      static_assert(!sizeof(RegType) && sizeof(RegType),		\
		    "Incompatibles Configs");				\
    }									\
    template<RegType OTHER_MASK>					\
    constexpr Config<RegType, Group, MASK | OTHER_MASK> operator op(const Config<RegType, Group, OTHER_MASK>& cfg) const { \
      return								\
	Config<RegType, Group, MASK | OTHER_MASK>(VALUE op cfg.VALUE);	\
    }									\
    template<typename OtherRegType, typename OtherGroup>		\
    constexpr RegType operator op(const Register<OtherRegType, OtherGroup>& reg) const { \
      static_assert(!sizeof(RegType) && sizeof(RegType),		\
		    "Incompatibles Register and Config");		\
    }									\
    constexpr RegType operator op(const Register<RegType, Group>& reg) const { \
      return VALUE op *reg.ADDRESS;					\
    }									\
    constexpr RegType operator op(const RegType val) const {		\
      return VALUE op val;						\
    }
    
    MACRO_DECLARE_BITWISE(|);
    MACRO_DECLARE_BITWISE(&);
    MACRO_DECLARE_BITWISE(^);
    
#undef MACRO_DECLARE_ARITH
    
    constexpr Config<RegType, Group, MASK> operator~(void) const {
      return Config<RegType, Group, MASK>(MASK & ~VALUE);
    }

    //! \brief This macro helps to declare some comparison operator methods
#define MACRO_DECLARE_COMPAR(op)					\
    inline constexpr bool operator op (const Config& cfg) const {	\
      return VALUE op cfg.VALUE;					\
    }									\
    inline constexpr bool operator op (const Field<RegType, Group, MASK>& field) const { \
      return field op (*this);						\
    }									\
    template<int BITNUM>						\
    inline constexpr bool operator op (const BitField<RegType, Group, BITNUM>& bf) const { \
      return bf op (*this);						\
    }									\
    inline constexpr bool operator op (const Register<RegType, Group>& reg) const { \
      return reg op (*this);						\
    }									\
    
    MACRO_DECLARE_COMPAR(==);
    MACRO_DECLARE_COMPAR(!=);
    
#undef MACRO_DECLARE_COMPAR
    
  };

  template<typename RegType, typename Group, RegType MASK>
  constexpr inline RegType VAL(const Config<RegType, Group, MASK>& cfg) {
    return cfg.VALUE;
  }

  template<typename RegType, typename Group, typename ValType>
  constexpr Config<RegType, Group, IntegerInfo<sizeof(RegType)>::UNSIGNED_MAX> make_config(const Register<RegType, Group>&, const ValType value) {
    return Config<RegType, Group, IntegerInfo<sizeof(RegType)>::UNSIGNED_MAX>((RegType)value);
  }

  template<typename RegType, typename Group, RegType MASK, typename ValType>
  constexpr Config<RegType, Group, MASK> make_config(const Field<RegType, Group, MASK>&, const ValType value) {
    return Config<RegType, Group, MASK>(Private::field_value(MASK, (RegType)value));
  }

  template<typename RegType, typename Group, int BITNUM>
  constexpr Config<RegType, Group, (1<<BITNUM)> make_config(const BitField<RegType, Group, BITNUM>&, const bool value) {
    return Config<RegType, Group, (1<<BITNUM)>(value?(1<<BITNUM):0);
  }

}

#endif//CONFIG_HPP
