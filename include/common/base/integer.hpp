#ifndef TYPE_HPP
#define TYPE_HPP

#include <stdint.h>

//! \class IntegerInfo integer.hpp <base/integer.hpp>
//! \brief Boundary infos of integer type with a specified size.
//! \param SIZE : size of integers in bits.
template<int SIZE>
struct IntegerInfo {
  //! \brief Maximum value for an unsigned integer of SIZE bits.
  static const uint64_t UNSIGNED_MAX = (static_cast<uint64_t>(1) << SIZE) - 1;
  
  //! \brief Maximum value for a signed integer of SIZE bits.
  static const uint64_t SIGNED_MAX = (static_cast<uint64_t>(1) << (SIZE - 1)) - 1;
  
  //! \brief Minimum value for a signed integer of SIZE bits.
  static const uint64_t SIGNED_MIN = static_cast<uint64_t>(1) << (SIZE - 1);
};

//! \class Integer integer.hpp <base/integer.hpp>
//! \brief Integer type definitions with a specified size.
//! \param SIZE : size of integer type in bits.
//! \param FAST : whether it is "fast" type or not.
template<int SIZE, bool FAST = false>
struct Integer : public Integer<((SIZE/8)+1) * 8, FAST> {
  static_assert(true, "Integers of 8, 16, 32 or 64 bits only are supported.");
  //! \brief Signed type for integer of SIZE bits.
  typedef void Signed;
  
  //! \brief Unsigned type for integer of SIZE bits.
  typedef void Unsigned;
  
  //! \brief Informations for integer of SIZE bits.
  typedef IntegerInfo<SIZE> Info;
};

#define MACRO_INTEGER(s) \
  template<> struct Integer<s, false> { typedef int##s##_t Signed; typedef uint##s##_t Unsigned; typedef IntegerInfo<s> Info; }; \
  template<> struct Integer<s, true> { typedef int_fast##s##_t Signed; typedef uint_fast##s##_t Unsigned; typedef IntegerInfo<s> Info; };

MACRO_INTEGER(8)
MACRO_INTEGER(16)
MACRO_INTEGER(32)
MACRO_INTEGER(64)

#undef MACRO_INTEGER

#define MACRO_SHORT_NAME(size)					\
  typedef typename Integer<size, false>::Signed  s##size;	\
  typedef typename Integer<size, false>::Unsigned u##size;	\
  typedef typename Integer<size, true>::Signed sf##size;	\
  typedef typename Integer<size, true>::Unsigned uf##size;

MACRO_SHORT_NAME(8)
MACRO_SHORT_NAME(16)
MACRO_SHORT_NAME(32)
MACRO_SHORT_NAME(64)

#undef MACRO_SHORT_NAME

#endif//TYPE_HPP
