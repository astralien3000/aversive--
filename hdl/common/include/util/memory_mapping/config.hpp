#ifndef CONFIG_HPP
#define CONFIG_HPP

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
    constexpr Config(const RegType value);

    //! \brief Copy Constructor
    constexpr Config(const Config& other);

    // Arithmetic

    //! \brief This macro helps to declare some bitwise operator methods
#define MACRO_DECLARE_BITWISE(op)						\
    template<typename OtherRegType, typename OtherGroup, OtherRegType OTHER_MASK> \
    constexpr Config<RegType, Group, MASK | OTHER_MASK> operator op(const Config<OtherRegType, OtherGroup, OTHER_MASK>& cfg) const; \
    template<RegType OTHER_MASK>					\
    constexpr Config<RegType, Group, MASK | OTHER_MASK> operator op(const Config<RegType, Group, OTHER_MASK>& cfg) const; \
    template<typename OtherRegType, typename OtherGroup>		\
    constexpr RegType operator op(const Register<OtherRegType, OtherGroup>& reg) const; \
    constexpr RegType operator op(const Register<RegType, Group>& reg) const; \
    constexpr RegType operator op(const RegType val) const;
    
    MACRO_DECLARE_BITWISE(|);
    MACRO_DECLARE_BITWISE(&);
    MACRO_DECLARE_BITWISE(^);
    
#undef MACRO_DECLARE_ARITH
    
    constexpr Config<RegType, Group, MASK> operator~(void) const;

    //! \brief This macro helps to declare some comparison operator methods
#define MACRO_DECLARE_COMPAR(op)						\
    inline constexpr bool operator op (const Config&);

    MACRO_DECLARE_COMPAR(==);
    MACRO_DECLARE_COMPAR(!=);
    
#undef MACRO_DECLARE_COMPAR
    
  };

  template<typename RegType, typename Group, typename ValType>
  constexpr Config<RegType, Group, IntegerInfo<sizeof(RegType)>::UNSIGNED_MAX> make_config(const Register<RegType, Group>& reg, const ValType value);

  template<typename RegType, typename Group, RegType MASK, typename ValType>
  constexpr Config<RegType, Group, MASK> make_config(const Field<RegType, Group, MASK>& field, const ValType value);

  template<typename RegType, typename Group, int BITNUM>
  constexpr Config<RegType, Group, (1<<BITNUM)> make_config(const BitField<RegType, Group, BITNUM>& bf, const bool value);

}

#endif//CONFIG_HPP
