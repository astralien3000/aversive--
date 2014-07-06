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

#ifndef BOOL_REF_HPP
#define BOOL_REF_HPP

#include <base/integer.hpp>

//! \class BoolRef bool_ref.hpp <base/bool_ref.hpp>
//! \brief This class represents a reference to a boolean.
class BoolRef {
private:
  //! \brief The address where the boolean is stored.
  u8* _byte;
  
  //! \brief The index of the bit at which the boolean is stored.
  u8 _bit;
  
  //! \brief Default constructor.
  BoolRef(void);
  
public:
  //! \brief Constructor to reference a boolean within a byte.
  //! \param byte : the address where the boolean is stored.
  //! \param bit : the index of the bit at which the boolean is stored.
  inline BoolRef(u8* byte, u8 bit)
    : _byte(byte), _bit(bit) {
  }
  
  //! \brief Constructor to reference a regular boolean.
  //! \warning This assumes that the boolean is coded by the first bit at the address of the given boolean, however, how a boolean is represented in memory is platform-dependent.
  //! \todo Investigate how are boolean reprensented in memory on the supported platforms by Aversive++ and possibly specialise this method per platform (according to the first test, it works on x86-64).
  inline BoolRef(const bool& b)
    : _byte((u8*) &b), _bit(0) {
  }
  
  //! \brief Copy constructor, the new BoolRef references the same boolean.
  inline BoolRef(const BoolRef& other)
    : _byte(other._byte), _bit(other._bit) {
  }
  
  //! \brief Cast operator to get a regular C++ boolean.
  //! \return A regular C++ boolean.
  inline operator bool(void) const {
    return (bool) (*_byte & (1 << _bit));
  }
  
  //! \brief Assign a new value to the referenced boolean.
  //! \param b : the new boolean value.
  //! \return A reference to the BoolRef.
  inline BoolRef& operator=(bool b) {
    if(b) {
      *_byte |= (1 << _bit);
    }
    else {
      *_byte &= ~(1 << _bit);
    }
    
    return (*this);
  }
  
  //! \brief Copy the value of the supplied boolean by its reference to the referenced boolean.
  //! \param other : a reference to the boolean this boolean copying its value from.
  //! \return A reference to the BoolRef.
  //! \warning This does not make the BoolRef on which the method is applied reference the same boolean as the BoolRel supplied as argument.
  inline BoolRef& operator=(const BoolRef& other) {
    operator=((bool) other);
    return (*this);
  }
};

#endif//BOOL_REF_HPP
