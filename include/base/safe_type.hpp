#ifndef SAFE_TYPE_HPP
#define SAFE_TYPE_HPP

//! \brief An overload of basic integers to enable some safety checks during runtime
template<typename Type>
class SafeType {
public:
  //! \brief Default Constructor
  inline SafeType();
  //! \brief Copy Constructor
  inline SafeType(const SafeType&);

  //! \brief Converter Constructor
  //!
  //! Enable to convert from types with smaller (or equal) size. 
  //! If size is bigger, check if the value is under target's type's max.
  //! If cannot convert because value, throw error.
  template<typename T>
  inline SafeType(T);

  //! \brief Converter Cast
  //!
  //! Enable to convert in type with bigger (or equal) size.
  //! If size is smaller, check if the value is under target's type's max.
  //! If cannot convert because value, throw error.
  template<typename T>
  inline operator T(void);

  //! \brief Copy Operator
  inline SafeType& operator=(const SafeType&);

  // Math
  inline SafeType& operator+=(const SafeType&);
  inline SafeType& operator-=(const SafeType&);
  inline SafeType& operator*=(const SafeType&);
  inline SafeType& operator/=(const SafeType&);
  inline SafeType& operator%=(const SafeType&);

  inline SafeType& operator++();
  inline SafeType& operator++(int);
  inline SafeType& operator--();
  inline SafeType& operator--(int);

  inline SafeType& operator+(const SafeType&) const;
  inline SafeType& operator-(const SafeType&) const;
  inline SafeType& operator*(const SafeType&) const;
  inline SafeType& operator/(const SafeType&) const;
  inline SafeType& operator%(const SafeType&) const;

  // Logical
  //inline SafeType& operator&&=(const SafeType&);
  //inline SafeType& operator||=(const SafeType&);

  inline SafeType& operator&&(const SafeType&) const;
  inline SafeType& operator||(const SafeType&) const;
  inline SafeType& operator! (void) const;

  // Bitwise
  inline SafeType& operator&=(const SafeType&);
  inline SafeType& operator|=(const SafeType&);
  inline SafeType& operator^=(const SafeType&);

  inline SafeType& operator<<=(const SafeType&);
  inline SafeType& operator>>=(const SafeType&);

  inline SafeType& operator&(const SafeType&) const;
  inline SafeType& operator|(const SafeType&) const;
  inline SafeType& operator^(const SafeType&) const;
  inline SafeType& operator~(void) const;

  inline SafeType& operator<<(const SafeType&) const;
  inline SafeType& operator>>(const SafeType&) const;
};

#undef MACRO_SAFE_TYPE_OPERATOR

#include "types.hpp"

#define MACRO_SAFE_SHORT_NAME(size)					\
  typedef SafeType<typename Integer<size>::Signed>   s##size##_safe;	\
  typedef SafeType<typename Integer<size>::Unsigned> u##size##_safe;

MACRO_SAFE_SHORT_NAME(8)
MACRO_SAFE_SHORT_NAME(16)
MACRO_SAFE_SHORT_NAME(32)
MACRO_SAFE_SHORT_NAME(64)

#undef MACRO_SAFE_SHORT_NAME

#include "debug.hpp"

#endif//SAFE_TYPE_HPP
