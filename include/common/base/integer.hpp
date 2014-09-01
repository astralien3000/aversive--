/*
    Aversive++                                                           
    Copyright (C) 2014 Eirbot                                            
                                                                         
    This program is free software: you can redistribute it and/or modify 
    it under the terms of the GNU General Public License as published by 
    the Free Software Foundation, either version 3 of the License, or    
    (at your option) any later version.                                  
                                                                         
    This program is distributed in the hope that it will be useful,      
    but WITHOUT ANY WARRANTY; without even the implied warranty of       
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        
    GNU General Public License for more details.                         
                                                                         
    You should have received a copy of the GNU General Public License    
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef TYPE_HPP
#define TYPE_HPP

#include <stdint.h>

//! \class IntegerInfo integer.hpp <base/integer.hpp>
//! \brief Boundary infos of integer type with a specified size.
//! \param _SIZE : size of integers in bits.
template<uint8_t _SIZE>
struct IntegerInfo {
  //! \brief The size in bits of the integers the infos in this class refer to.
  static const uint8_t SIZE = _SIZE;
  
  //! \brief Maximum value for an unsigned integer of SIZE bits.
  static const uint64_t UNSIGNED_MAX = (static_cast<uint64_t>(1) << SIZE) - 1;
  
  //! \brief Maximum value for a signed integer of SIZE bits.
  static const uint64_t SIGNED_MAX = (static_cast<uint64_t>(1) << (SIZE - 1)) - 1;
  
  //! \brief Minimum value for a signed integer of SIZE bits.
  static const uint64_t SIGNED_MIN = static_cast<uint64_t>(1) << (SIZE - 1);
};

//! \class Integer integer.hpp <base/integer.hpp>
//! \brief Integer type definitions with a specified size.
//! \param _SIZE : size of integer type in bits.
//! \param _FAST : whether it is "fast" type or not.
/*!
  This templated-class is specialised for 8, 16, 32 and 64 bits integer, wheter fast type or not.
  This class will cause an assertion at compile-time if you use it with a size different than 8, 16, 32 or 64 bits.
  You can easily use this class to do metaprogramming.
  Short type names are also provided for classic usages: u8 (unsigned 8 bits), s8 (signed 8 bits), uf8 (fast unsigned 8 bits), sf8 (fast signed 8 bits) and so on for 16, 32 and 64 bits integers.
  Short type names for pointer-sized unsigned and signed integers are also provided: usys (unsigned pointer-sized) and ssys (signed pointer-sized). You can retrieve these types' information easily with IntegerInfo<sizeof(usys) * 8>.
*/
template<uint8_t _SIZE, bool _FAST = false>
struct Integer {
  static_assert(true, "Integers of 8, 16, 32 or 64 bits only are supported.");
  
  //! \brief The size in bits of the integers represented by this class.
  static const uint8_t SIZE = _SIZE;
  
  //! \brief Whether the integers represented by this class are "fast" or not.
  static const bool FAST = _FAST;
  
  //! \brief Signed type for integer of SIZE bits.
  typedef void Signed;
  
  //! \brief Unsigned type for integer of SIZE bits.
  typedef void Unsigned;
  
  //! \brief Informations for integer of SIZE bits.
  typedef IntegerInfo<SIZE> Info;
};

#define MACRO_INTEGER(s) \
  template<> struct Integer<s, false> { static const uint8_t SIZE = s; static const bool FAST = false; typedef int##s##_t Signed; typedef uint##s##_t Unsigned; typedef IntegerInfo<s> Info; }; \
  template<> struct Integer<s, true> { static const uint8_t SIZE = s; static const bool FAST = true; typedef int_fast##s##_t Signed; typedef uint_fast##s##_t Unsigned; typedef IntegerInfo<s> Info; };

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

typedef uintptr_t usys;
typedef intptr_t ssys;

#endif//TYPE_HPP
