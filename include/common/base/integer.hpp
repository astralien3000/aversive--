#ifndef TYPE_HPP
#define TYPE_HPP

#include <stdint.h>

//! \brief boundaries infos on integers with specified size
//! \param SIZE : size of integer in bits
//! \param S : signed integer type
//! \param U : unsigned integer type
template<int SIZE>
struct IntegerInfo {
  enum {
    UNSIGNED_MAX = (((long long)1 << SIZE) - 1)      ,
    SIGNED_MAX   = (((long long)1 << (SIZE - 1)) - 1),
    SIGNED_MIN   = (((long long)1 << (SIZE - 1)))
  };
};

//! \brief Integer type definitions with specified size
//! \param SIZE : size of integer in bits
template<int SIZE, bool FAST = false>
struct Integer : public Integer<((SIZE/8)+1) * 8, FAST> {};

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
