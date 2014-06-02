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

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <base/integer.hpp>

typedef uf16 array_t;

//! \class Array array.hpp <base/array.hpp>
//! \brief Class representing a native array with operator overloading.
//! \param _SIZE : the amount of elements in the array.
//! \param _ElementType : the type of the elements contained within the array.
template<array_t _SIZE = 0, typename _ElementType = u8>
class Array {
public:
  //! \brief The size of the array.
  static const array_t SIZE = _SIZE;
  
  //! \brief The length in bits for the array's field indexes.
  static const array_t ARRAY_INDEX_LENGTH = 16;
  
  //! \brief The maximum size of an array.
  static const array_t MAX_SIZE = IntegerInfo<ARRAY_INDEX_LENGTH>::UNSIGNED_MAX;
  
  //! \brief Element's type.
  typedef _ElementType ElementType;
  
private:
  //! \brief The native C-like array containing the datas.
  ElementType _elements[SIZE];
  
public:
  //! \brief Default constructor.
  //! \attention The elements within the array are not set to any value.
  inline Array(void) {
  }
  
  //! \brief Constructor with initialisation.
  //! \param e : the element to copy in every field of the new array.
  inline Array(const ElementType& e) {
    for(array_t i = 0; i < SIZE; i++) {
      _elements[i] = e;
    }
  }
  
  //! \brief Copy constructor.
  //! \param other : the array to copy.
  inline Array(const Array& other) {
    (*this) = other;
  }
  
  //! \brief Copy operator.
  //! \param other : the array to copy.
  //! \return A reference to the array that has been written.
  inline Array& operator=(const Array& other) {
    for(array_t i = 0; i < SIZE; i++) {
      _elements[i] = other._elements[i];
    }
    return (*this);
  }
  
  //! \brief Access to an element's reference via its field's index.
  //! \param i : the index of the element to access.
  //! \return The reference to the element contained at the specified index.
  inline ElementType& operator[](array_t i) {
    return _elements[i];
  }
  
  //! \brief Access to an element's constant reference via its field's index.
  //! \param i : the index of the element to access.
  //! \return The constant reference to the element contained at the specified index.
  inline const ElementType& operator[](array_t i) const {
    return _elements[i];
  }
  
  //! \brief Add to each element of the array the corresponding element from another array.
  //! \param other : the array to get the values to add from.
  //! \return A reference to the array the assignment has been done to.
  inline Array& operator+=(const Array& other) {
    for(array_t i = 0; i < SIZE; i++) {
      _elements[i] += other._elements[i];
    }
    return (*this);
  }
  
  //! \brief Substract to each element of the array the corresponding element from another array.
  //! \param other : the array to get the values to substract from.
  //! \return A reference to the array the assignment has been done to.
  inline Array& operator-=(const Array& other) {
    for(array_t i = 0; i < SIZE; i++) {
      _elements[i] -= other._elements[i];
    }
    return (*this);
  }
  
  //! \brief Multiply each element of the array by the corresponding element from another array.
  //! \param other : the array to get the values to multiply with.
  //! \return A reference to the array the assignment has been done to.
  inline Array& operator*=(const Array& other) {
    for(array_t i = 0; i < SIZE; i++) {
      _elements[i] *= other._elements[i];
    }
    return (*this);
  }
  
  //! \brief Divide each element of the array by the corresponding element from another array.
  //! \param other : the array to get the divisors from.
  //! \return A reference to the array the assignment has been done to.
  inline Array& operator/=(const Array& other) {
    for(array_t i = 0; i < SIZE; i++) {
      _elements[i] /= other._elements[i];
    }
    return (*this);
  }
  
  //! \brief Get the modulo of each element of the array by the corresponding element from another array.
  //! \param other : the array to get the divisors from.
  //! \return A reference to the array the assignment has been done to.
  inline Array& operator%=(const Array& other) {
    for(array_t i = 0; i < SIZE; i++) {
      _elements[i] %= other._elements[i];
    }
    return (*this);
  }
  
  //! \brief Add each element of two arraies together two-by-two.
  //! \param other : the array to get the values to add from.
  //! \return The result array after the additions.
  inline Array operator+(const Array& other) {
    Array ret;
    for(array_t i = 0; i < SIZE; i++) {
      ret._elements[i] = _elements[i] + other._elements[i];
    }
    return ret;
  }
  
  //! \brief Substract each element of two arraies together two-by-two.
  //! \param other : the array to get the values to substract from.
  //! \return The result array after the substractions.
  inline Array operator-(const Array& other) {
    Array ret;
    for(array_t i = 0; i < SIZE; i++) {
      ret._elements[i] = _elements[i] - other._elements[i];
    }
    return ret;
  }
  
  //! \brief Multiply each element of two arraies together two-by-two.
  //! \param other : the array to get the multipliers from.
  //! \return The result array after the multiplications.
  inline Array operator*(const Array& other) {
    Array ret;
    for(array_t i = 0; i < SIZE; i++) {
      ret._elements[i] = _elements[i] * other._elements[i];
    }
    return ret;
  }
  
  //! \brief Divide each element of two arraies together two-by-two.
  //! \param other : the array to get the divisors from.
  //! \return The result array after the divisions.
  inline Array operator/(const Array& other) {
    Array ret;
    for(array_t i = 0; i < SIZE; i++) {
      ret._elements[i] = _elements[i] / other._elements[i];
    }
    return ret;
  }
  
  //! \brief Apply a modulo on each element of two arraies together two-by-two.
  //! \param other : the array to get the divisors from.
  //! \return The result array after the modulo operations.
  inline Array operator%(const Array& other) {
    Array ret;
    for(array_t i = 0; i < SIZE; i++) {
      ret._elements[i] = _elements[i] % other._elements[i];
    }
    return ret;
  }
  
  //! \brief Add to each element of the array another object.
  //! \param o : the object to add.
  //! \return A reference to the array the assignment has been done to.
  inline Array& operator+=(const ElementType& o) {
    for(array_t i = 0; i < SIZE; i++) {
      _elements[i] += o;
    }
    return (*this);
  }
  
  //! \brief Substract to each element of the array another object.
  //! \param o : the object to substract.
  //! \return A reference to the array the assignment has been done to.
  inline Array& operator-=(const ElementType& o) {
    for(array_t i = 0; i < SIZE; i++) {
      _elements[i] -= o;
    }
    return (*this);
  }
  
  //! \brief Multiply each element of the array with another object.
  //! \param o : the multiplier.
  //! \return A reference to the array the assignment has been done to.
  inline Array& operator*=(const ElementType& o) {
    for(array_t i = 0; i < SIZE; i++) {
      _elements[i] *= o;
    }
    return (*this);
  }
  
  //! \brief Divide each element of the array by another object.
  //! \param o : the divisor.
  //! \return A reference to the array the assignment has been done to.
  inline Array& operator/=(const ElementType& o) {
    for(array_t i = 0; i < SIZE; i++) {
      _elements[i] /= o;
    }
    return (*this);
  }
  
  //! \brief Get the modulo of each element of the array by another object.
  //! \param o : the divisor.
  //! \return A reference to the array the assignment has been done to.
  inline Array& operator%=(const ElementType& o) {
    for(array_t i = 0; i < SIZE; i++) {
      _elements[i] %= o;
    }
    return (*this);
  }
  
  //! \brief Add an oject to each element of the array.
  //! \param o : the object to add.
  //! \return The result array after the additions.
  inline Array operator+(const ElementType& o) {
    Array ret;
    for(array_t i = 0; i < SIZE; i++) {
      ret._elements[i] = _elements[i] + o;
    }
    return ret;
  }
  
  //! \brief Substract an object to each element of the array.
  //! \param o : the object to substract.
  //! \return The result array after the substractions.
  inline Array operator-(const ElementType& o) {
    Array ret;
    for(array_t i = 0; i < SIZE; i++) {
      ret._elements[i] = _elements[i] - o;
    }
    return ret;
  }
  
  //! \brief Multiply each element of the array by another object.
  //! \param o : the multiplier.
  //! \return The result array after the multiplications.
  inline Array operator*(const ElementType& o) {
    Array ret;
    for(array_t i = 0; i < SIZE; i++) {
      ret._elements[i] = _elements[i] * o;
    }
    return ret;
  }
  
  //! \brief Divide each element of the array by another object.
  //! \param o : the divisor.
  //! \return The result array after the divisions.
  inline Array operator/(const ElementType& o) {
    Array ret;
    for(array_t i = 0; i < SIZE; i++) {
      ret._elements[i] = _elements[i] / o;
    }
    return ret;
  }
  
  //! \brief Apply a modulo on each element of the array by another object.
  //! \param o : the divisor.
  //! \return The result array after the modulo operations.
  inline Array operator%(const ElementType& o) {
    Array ret;
    for(array_t i = 0; i < SIZE; i++) {
      ret._elements[i] = _elements[i] % o;
    }
    return ret;
  }
};

#endif//ARRAY_HPP
