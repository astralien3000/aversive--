#ifndef TYPE_HPP
#define TYPE_HPP

#include <stdint.h>

//! \brief boundaries infos on integers with specified size
//! \param SIZE : size of integer in bits
//! \param S : signed integer type
//! \param U : unsigned integer type
template<int SIZE, typename S, typename U>
struct IntegerInfo {
  enum {
    UNSIGNED_MAX = (U)(((long long)1 << SIZE) - 1)      ,
    SIGNED_MAX   = (S)(((long long)1 << (SIZE - 1)) - 1),
    SIGNED_MIN   = (S)(((long long)1 << (SIZE - 1)))
  };
};

//! \brief Integer type definitions with specified size
//! \param SIZE : size of integer in bits
template<int SIZE>
struct Integer : public Integer<((SIZE/8)+1) * 8> {};

#define MACRO_INTEGER(s, t) \
  template<> struct Integer<s> { typedef t Signed; typedef u##t Unsigned; typedef IntegerInfo<s, Signed, Unsigned> Info; };

MACRO_INTEGER( 8, int8_t)
MACRO_INTEGER(16, int16_t)
MACRO_INTEGER(32, int32_t)
MACRO_INTEGER(64, int64_t)

#undef MACRO_INTEGER

#define MACRO_SHORT_NAME(size)				\
  typedef typename Integer<size>::Signed  s##size;	\
  typedef typename Integer<size>::Unsigned u##size;

MACRO_SHORT_NAME(8)
MACRO_SHORT_NAME(16)
MACRO_SHORT_NAME(32)
MACRO_SHORT_NAME(64)

#undef MACRO_SHORT_NAME

#endif//TYPE_HPP
