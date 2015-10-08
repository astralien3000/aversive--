#ifndef BITFIELD_HPP
#define BITFIELD_HPP

namespace MemoryMapping {

  //! \brief This class is a part of a Register limited to one Bit
  //! \param RegType : the register integer type
  //! \param Group : the register group
  //! \param BITNUM : the bit number in the register
  /*!
   * A BitField is a part of a register, that can be manipulated as a boolean variable (with less possibilities, however).
   */
  template<typename RegType, typename Group, int BITNUM>
  struct BitField {
  public:
    //! \brief The Register which this BitField belongs to
    const Register<RegType, Group>& REGISTER;

  public:
    //! \brief Constructor
    //! \param reg : The Register which this Field belongs to
    constexpr BitField(const Register<RegType, Group>& reg);

    //! \brief Cast operator
    operator bool(void) const;

    // Assignment

    //! \brief Assignment operator for a Config object.
    const BitField& operator=(const Config<RegType, Group, (1<<BITNUM)>& cfg) const;

    //! \brief Assignment operator for an other BitField.
    /*!
     * This is a simplified version for the case where the bitfields have the same BITNUM.
     */
    const BitField& operator=(const BitField<RegType, Group, BITNUM>& bf) const;

    //! \brief Assignment operator for an other BitField.
    /*!
     * Unlike the other classes, BitFields can be used with any other BitField,
     * because a boolean is a boolean !
     */
    template<typename OtherRegType, typename OtherGroup, int OTHER_BITNUM> const BitField& operator=(const BitField<OtherRegType, OtherGroup, OTHER_BITNUM>& bf) const;
    
    //! \brief Assignment operator for a bool value.
    const BitField& operator=(const bool val) const;

    // Logic
    #define OP &&
    #include "bitfield_decl_logic.hpp"
    #undef OP

    #define OP ||
    #include "bitfield_decl_logic.hpp"
    #undef OP

  };

}

#endif//BITFIELD_HPP
