#ifndef CONFIG_IMPL_HPP
#define CONFIG_IMPL_HPP

namespace MemoryMapping {

  template<typename RegType, typename Group, RegType MASK>
  constexpr inline RegType VAL(const Config<RegType, Group, MASK>& cfg) {
    return cfg.VALUE;
  }
  
  template<typename RegType, typename Group, RegType MASK>
  inline constexpr Config<RegType, Group, MASK>::Config(const RegType value)
    : VALUE(value) {
  }

  template<typename RegType, typename Group, RegType MASK>
  inline constexpr Config<RegType, Group, MASK>::Config(const Config& other)
    : VALUE(other.VALUE) {
  }

  template<typename RegType, typename Group, typename ValType>
  inline constexpr Config<RegType, Group, IntegerInfo<sizeof(RegType)>::UNSIGNED_MAX> make_config(const Register<RegType, Group>& , const ValType value) {
    return Config<RegType, Group, IntegerInfo<sizeof(RegType)>::UNSIGNED_MAX>((RegType)value);
  }

  template<typename RegType, typename Group, RegType MASK, typename ValType>
  inline constexpr Config<RegType, Group, MASK> make_config(const Field<RegType, Group, MASK>& , const ValType value) {
    return Config<RegType, Group, MASK>(Private::field_value(MASK, (RegType)value));
  }

  template<typename RegType, typename Group, int BITNUM>
  inline constexpr Config<RegType, Group, (1<<BITNUM)> make_config(const BitField<RegType, Group, BITNUM>& , const bool value) {
    return Config<RegType, Group, (1<<BITNUM)>(value?(1<<BITNUM):0);
  }
    

#define MACRO_DEFINE_BITWISE(op)					\
    template<typename RegType, typename Group, RegType MASK>		\
    template<typename OtherRegType, typename OtherGroup, OtherRegType OTHER_MASK> \
    inline constexpr Config<RegType, Group, MASK | OTHER_MASK> Config<RegType, Group, MASK>::operator op(const Config<OtherRegType, OtherGroup, OTHER_MASK>& ) const { \
      static_assert(!sizeof(RegType) && sizeof(RegType), "Incompatibles Configs"); \
    }									\
    template<typename RegType, typename Group, RegType MASK> template<RegType OTHER_MASK> \
    inline constexpr Config<RegType, Group, MASK | OTHER_MASK> Config<RegType, Group, MASK>::operator op(const Config<RegType, Group, OTHER_MASK>& cfg) const { \
      return Config<RegType, Group, MASK | OTHER_MASK>(VALUE op cfg.VALUE); \
    }									\
    template<typename RegType, typename Group, RegType MASK> template<typename OtherRegType, typename OtherGroup> \
    inline constexpr RegType Config<RegType, Group, MASK>::operator op(const Register<OtherRegType, OtherGroup>& ) const { \
      static_assert(!sizeof(RegType) && sizeof(RegType), "Incompatibles Register and Config"); \
    }									\
    template<typename RegType, typename Group, RegType MASK>		\
    inline constexpr RegType Config<RegType, Group, MASK>::operator op(const Register<RegType, Group>& reg) const { \
      return VALUE op *reg.ADDRESS;					\
    }									\
    template<typename RegType, typename Group, RegType MASK>		\
    inline constexpr RegType Config<RegType, Group, MASK>::operator op(const RegType val) const { \
      return VALUE op val;						\
    }
    
    MACRO_DEFINE_BITWISE(|)
    MACRO_DEFINE_BITWISE(&)
    MACRO_DEFINE_BITWISE(^)
      
#undef MECRO_DEFINE_BITWISE

    template<typename RegType, typename Group, RegType MASK>
    inline constexpr Config<RegType, Group, MASK> Config<RegType, Group, MASK>::operator ~(void) const {
      return Config<RegType, Group, MASK>(MASK & ~VALUE);
    }

      
#define MACRO_DEFINE_COMPAR(op)						\
    template<typename RegType, typename Group, RegType MASK>		\
    inline constexpr bool Config<RegType, Group, MASK>::operator op (const Config<RegType, Group, MASK>& cfg) const { \
      return VALUE op cfg.VALUE;					\
    }

    
    MACRO_DEFINE_COMPAR(==)
    MACRO_DEFINE_COMPAR(!=)

#undef MACRO_DEFINE_COMPAR
}

#endif//CONFIG_IMPL_HPP
