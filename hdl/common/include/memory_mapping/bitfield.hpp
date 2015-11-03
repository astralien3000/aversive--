#ifndef BITFIELD_HPP
#define BITFIELD_HPP

#include "memory_mapping.hpp"

namespace MemoryMapping {

  namespace Private {

    template<int OFFSET, typename T, bool POSITIVE = false>
    struct RelativeOffsetHelper {
      static inline constexpr T run(T val) {
	return val >> -OFFSET;
      }
    };
      
    template<int OFFSET, typename T>
    struct RelativeOffsetHelper<OFFSET, T, true> {
      static inline constexpr T run(T val) {
	return val << OFFSET;
      }
    };

    template<int OFFSET, typename T>
    static inline constexpr T relative_offset(T val) {
      return RelativeOffsetHelper<OFFSET, T, (OFFSET >= 0)>::run(val);
    }

  }
  
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
    constexpr BitField(const Register<RegType, Group>& reg)
      : REGISTER(reg) {
    }

    //! \brief Cast operator
    operator bool(void) const {
      return REGISTER & (1 << BITNUM);
    }

    // Assignment

    //! \brief Assignment operator for a Config object.
    const BitField& operator=(const Config<RegType, Group, (1<<BITNUM)>& cfg) const {
      REGISTER = (REGISTER & ~(1 << BITNUM)) | cfg.VALUE;
      return *this;
    }

    //! \brief Assignment operator for an other BitField.
    /*!
     * This is a simplified version for the case where the bitfields have the same BITNUM.
     */
    const BitField& operator=(const BitField<RegType, Group, BITNUM>& bf) const {
      REGISTER = (REGISTER & ~(1 << BITNUM)) | (bf.REGISTER & (1 << BITNUM));
      return *this;
    }

    //! \brief Assignment operator for an other BitField.
    /*!
     * Unlike the other classes, BitFields can be used with any other BitField,
     * because a boolean is a boolean !
     */
    template<typename OtherRegType, typename OtherGroup, int OTHER_BITNUM> const BitField& operator=(const BitField<OtherRegType, OtherGroup, OTHER_BITNUM>& bf) const {
      REGISTER = (REGISTER & ~(1 << BITNUM)) | Private::relative_offset<(BITNUM - OTHER_BITNUM)>(bf.REGISTER & (1 << OTHER_BITNUM));
      return *this;
    }
    
    //! \brief Assignment operator for a bool value.
    const BitField& operator=(const bool val) const {
      if(val) {
	REGISTER |= (1 << BITNUM);
      }
      else {
	REGISTER &= (RegType)(~(1 << BITNUM));
      }
      return *this;
    }

    // Logic
#define MACRO_DEFINE_LOGIC(op)						\
    inline bool operator op(const Config<RegType, Group, (1<<BITNUM)>& cfg) const { \
      return ((bool)*this) op cfg;					\
    }									\
    template<typename OtherRegType, typename OtherGroup, int OTHER_BITNUM> \
    inline bool operator op(const BitField<OtherRegType, OtherGroup, OTHER_BITNUM>& bf) const { \
      return ((bool)*this) op ((bool)bf);				\
    }									\
    inline bool operator op(const bool val) const {			\
      return ((bool)*this) op val;					\
    }

    MACRO_DEFINE_LOGIC(&&);
    MACRO_DEFINE_LOGIC(||);

#undef MACRO_DEFINE_LOGIC

#define MACRO_DEFINE_COMPAR(op)						\
    template<RegType MASK>						\
    bool operator op(const Config<RegType, Group, MASK>& cfg) const {	\
      static_assert(MASK==1<<BITNUM,					\
		    "Invalid Config and BitField comparison");		\
      return (VAL(REGISTER) & MASK) op (VAL(cfg) & MASK);		\
    }									\
    bool operator op(const bool val) const {				\
      return val op *this;						\
    }									\

    MACRO_DEFINE_COMPAR(==);
    MACRO_DEFINE_COMPAR(!=);
    
#undef MACRO_DEFINE_COMPAR

  };

}

#endif//BITFIELD_HPP
