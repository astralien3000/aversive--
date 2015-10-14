#ifndef FIELD_HPP
#define FIELD_HPP

namespace MemoryMapping {

  //! \brief This class represents a part of a Register
  //! \param RegType : the register integer type
  //! \param Group : the register group
  //! \param MASK : the mask that determines the bits of the Field
  /*!
   * A Field is a part of a Register, that can be manipulated as a variable (with less possibilities, however).
   */
  template<typename RegType, typename Group, RegType MASK>
  struct Field {
  public:
    //! \brief The Register which this Field belongs to
    const Register<RegType, Group> REGISTER;

  public:
    //! \brief Constructor
    //! \param reg : The Register which this Field belongs to
    constexpr Field(const Register<RegType, Group> reg);
    
    //! \brief Assignment operator for an incompatible Config.
    template<typename OtherRegType, typename OtherGroup, OtherRegType OTHER_MASK>
    const Field& operator=(const Config<OtherRegType, OtherGroup, OTHER_MASK>& cfg) const;

    //! \brief Assignment operator for a Config object.
    const Field& operator=(const Config<RegType, Group, MASK>& cfg) const;

    //! \brief Assignment operator for an incompatible Field.
    template<typename OtherRegType, typename OtherGroup, OtherRegType OTHER_MASK>
    const Field& operator=(const Field<OtherRegType, OtherGroup, OTHER_MASK>& field) const;

    //! \brief Assignment operator for an other Field.
    const Field& operator=(const Field<RegType, Group, MASK>& field) const;

    //! \brief Assignment operator for an integer value.
    //! \param val : An integer value (with some restrictions, see below)
    //! \warning The value is a value for the Field, not the Register.
    /*!
     * For example :
     *         
     *         If the Field's MASK is 0b01011000 (the Register is on 1 Byte).
     *         It means that the Field can have values on 3 Bits
     *         So, a correct value of this field is between 0 and 0b111 (which is equal to 7).
     *         
     *         Then, if the Field is assigned 0b101, the Register's value will be : 0bx1x01xxx
     *         (where "x" stands for the previous value of the Register's corresponding Bit)
     */
    const Field& operator=(const RegType val) const;

  };

}

#endif//FIELD_HPP
