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

#ifndef SAFE_INTEGER_HPP
#define SAFE_INTEGER_HPP

#define MUL_OVERFLOW_CALLBACK(value, ret) //cout << "MUL ERR " << value << " " << ret << endl;
#define DIF_OVERFLOW_CALLBACK(value, ret) //cout << "DIF ERR " << value << " " << ret << endl;
#define ADD_OVERFLOW_CALLBACK(value, ret) //cout << "ADD ERR " << value << " " << ret << endl;
#define DIV_ON_ERROR_CALLBACK(value, ret) //cout << "DIV ERR " << value << " " << ret << endl;

#define CPY_ON_ERROR_CALLBACK(value, ret) //cout << "CPY ERR in = " << value << "  out = " << ret << endl;

//! Private Define TYPED_OPERATION
#define TYPED_OPERATION(type, op, v1, v2) (type)((type) v1 op (type) v2)

//! Private Define CHECK_OPERATION
#define CHECK_OPERATION(callback, big_t, tiny_t, op, v1, v2)		\
  if(TYPED_OPERATION(big_t, op, v1, v2) != TYPED_OPERATION(tiny_t, op, v1, v2)) { \
    callback(TYPED_OPERATION(big_t, op, v1, v2), TYPED_OPERATION(tiny_t, op, v1, v2)); \
  }

//! \brief An overload of basic integers to enable some safety checks during runtime
template<typename Type>
class SafeInteger {
private:
  Type _val;

public:
  //! \brief Default Constructor
  inline SafeInteger() : _val(0) {}
  //! \brief Copy Constructor
  inline SafeInteger(const SafeInteger& other) : _val(other._val) {}

  //! \brief Converter Constructor
  //!
  //! Enable to convert from types with smaller (or equal) size. 
  //! If size is bigger, check if the value is under target's type's max.
  //! If cannot convert because value, throw error.
  template<typename T>
  inline SafeInteger(T val) : _val(val) {
    if(val != _val) {
      CPY_ON_ERROR_CALLBACK(val, _val);
    }
  }

  //! \brief Converter Cast
  //!
  //! Enable to convert in type with bigger (or equal) size.
  //! If size is smaller, check if the value is under target's type's max.
  //! If cannot convert because value, throw error.
  template<typename T>
  inline operator T(void) {
    if((T)_val != _val) {
      CPY_ON_ERROR_CALLBACK((int)(T)_val, _val);
    }
    return (T)_val;
  }

  //! \brief Copy Operator
  inline SafeInteger& operator=(const SafeInteger& other) {
    _val = other._val;
    return *this;
  }

  // Math
  inline SafeInteger& operator+=(const SafeInteger& other) {
    return (*this) = (*this) + other;
  }

  inline SafeInteger& operator-=(const SafeInteger& other) {
    return (*this) = (*this) - other;
  }

  inline SafeInteger& operator*=(const SafeInteger& other) {
    return (*this) = (*this) * other;
  }

  inline SafeInteger& operator/=(const SafeInteger& other) {
    return (*this) = (*this) / other;
  }

  inline SafeInteger& operator%=(const SafeInteger& other) {
    return (*this) = (*this) % other;
  }

  inline SafeInteger& operator++() {
    return (*this) += 1;
  }

  inline SafeInteger operator++(int) {
    SafeInteger ret(*this);
    ++(*this);
    return ret;
  }

  inline SafeInteger& operator--() {
    return (*this) -= 1;
  }

  inline SafeInteger operator--(int) {
    SafeInteger ret(*this);
    --(*this);
    return ret;
  }

  inline SafeInteger operator+(const SafeInteger& other) const {
    CHECK_OPERATION(ADD_OVERFLOW_CALLBACK, s64, Type, +, _val, other._val);
    return SafeInteger(_val + other._val);
  }

  inline SafeInteger operator-(const SafeInteger& other) const {
    CHECK_OPERATION(DIF_OVERFLOW_CALLBACK, s64, Type, -, _val, other._val);
    return SafeInteger(_val - other._val);
  }

  inline SafeInteger operator*(const SafeInteger& other) const {
    CHECK_OPERATION(MUL_OVERFLOW_CALLBACK, s64, Type, *, _val, other._val);
    return SafeInteger(_val * other._val);
  }

  inline SafeInteger operator/(const SafeInteger& other) const {
    if(other._val == 0) {
      DIV_ON_ERROR_CALLBACK(0, 0);
    }
    return SafeInteger(_val / other._val);
  }

  inline SafeInteger operator%(const SafeInteger& other) const {
    if(other._val == 0) {
      DIV_ON_ERROR_CALLBACK(0, 0);
    }
    return SafeInteger(_val % other._val);
  }

  // Comparison
  inline bool operator==(const SafeInteger& other) const {
    return _val == other._val;
  }

  inline bool operator<(const SafeInteger& other) const {
    return _val < other._val;
  }

  inline bool operator<=(const SafeInteger& other) const {
    return _val <= other._val;
  }

  inline bool operator>(const SafeInteger& other) const {
    return _val > other._val;
  }

  inline bool operator>=(const SafeInteger& other) const {
    return _val >= other._val;
  }

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

#endif//SAFE_INTEGER_HPP
