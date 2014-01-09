#ifndef SAFE_INTEGER_HPP
#define SAFE_INTEGER_HPP

//! \brief An overload of basic integers to enable some safety checks during runtime
template<typename Integer>
class SafeInteger {  
public:
  //! \brief Default Constructor
  inline SafeInteger();
  //! \brief Copy Constructor
  inline SafeInteger(const SafeInteger&);

  //! \brief Converter Constructor
  //!
  //! Enable to convert from types with smaller (or equal) size. 
  //! If size is bigger, check if the value is under target's type's max.
  //! If cannot convert because value, throw error.
  template<typename T>
  inline SafeInteger(T);

  //! \brief Converter Cast
  //!
  //! Enable to convert in type with bigger (or equal) size.
  //! If size is smaller, check if the value is under target's type's max.
  //! If cannot convert because value, throw error.
  template<typename T>
  inline operator T(void);

  //! \brief Copy Operator
  inline SafeInteger& operator=(const SafeInteger&);

  // Math
  inline SafeInteger& operator+=(const SafeInteger&);
  inline SafeInteger& operator-=(const SafeInteger&);
  inline SafeInteger& operator*=(const SafeInteger&);
  inline SafeInteger& operator/=(const SafeInteger&);
  inline SafeInteger& operator%=(const SafeInteger&);

  inline SafeInteger& operator++();
  inline SafeInteger& operator++(int);
  inline SafeInteger& operator--();
  inline SafeInteger& operator--(int);

  inline SafeInteger& operator+(const SafeInteger&) const;
  inline SafeInteger& operator-(const SafeInteger&) const;
  inline SafeInteger& operator*(const SafeInteger&) const;
  inline SafeInteger& operator/(const SafeInteger&) const;
  inline SafeInteger& operator%(const SafeInteger&) const;

  // Logical
  //inline SafeInteger& operator&&=(const SafeInteger&);
  //inline SafeInteger& operator||=(const SafeInteger&);

  inline SafeInteger& operator&&(const SafeInteger&) const;
  inline SafeInteger& operator||(const SafeInteger&) const;
  inline SafeInteger& operator! (void) const;

  // Bitwise
  inline SafeInteger& operator&=(const SafeInteger&);
  inline SafeInteger& operator|=(const SafeInteger&);
  inline SafeInteger& operator^=(const SafeInteger&);

  inline SafeInteger& operator<<=(const SafeInteger&);
  inline SafeInteger& operator>>=(const SafeInteger&);

  inline SafeInteger& operator&(const SafeInteger&) const;
  inline SafeInteger& operator|(const SafeInteger&) const;
  inline SafeInteger& operator^(const SafeInteger&) const;
  inline SafeInteger& operator~(void) const;

  inline SafeInteger& operator<<(const SafeInteger&) const;
  inline SafeInteger& operator>>(const SafeInteger&) const;
};

#include "integer.hpp"

#define MACRO_SAFE_SHORT_NAME(size)					\
  typedef SafeInteger<typename Integer<size>::Signed>   s##size##_safe;	\
  typedef SafeInteger<typename Integer<size>::Unsigned> u##size##_safe;

MACRO_SAFE_SHORT_NAME(8)
MACRO_SAFE_SHORT_NAME(16)
MACRO_SAFE_SHORT_NAME(32)
MACRO_SAFE_SHORT_NAME(64)

#undef MACRO_SAFE_SHORT_NAME

#endif//SAFE_INTEGER_HPP
