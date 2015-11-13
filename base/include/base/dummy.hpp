#ifndef HDL_UTIL_DUMMY_HPP
#define HDL_UTIL_DUMMY_HPP

#include <base/integer.hpp>

//! \brief This is a utility type for templates
/*! 
 * Due to C++ current (october 2015) specifications,
 * templates cannot be specialised in the class where 
 * it has been declared.
 * But partial specialisations are allowed.
 * So this type is used when the developper  
 * wants to specialise a template in the same class
 * as it has been declared.
 */ 
using DummyType = u8;

//! \brief This value should be used with DummyType
/*!
 * It should even be the only acceptable value of DummyType.
 */
constexpr u8 DUMMY_VALUE = 0;

#endif//HDL_UTIL_DUMMY_HPP
