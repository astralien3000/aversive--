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

#ifndef FIXED_POINT_HPP
#define FIXED_POINT_HPP

#include "../base/types.hpp"

template<int SIZE, int UNIT_BIT>
class FixedPoint {
private:
  //Types
  typedef typename Integer<SIZE - UNIT_BIT>::Signed IntegerType;
  typedef typename Integer<UNIT_BIT>::Unsigned      DecimalType;
  typedef typename Integer<SIZE>::Signed            DataType;

public:
  // Constructor
  inline FixedPoint();
  inline FixedPoint(const FixedPoint&);
  inline FixedPoint(IntegerType);
  template<typename T> inline FixedPoint(T);

  // Assignment
  inline FixedPoint& operator=(const FixedPoint&);
  inline FixedPoint& operator=(IntegerType);
  template<typename T> inline FixedPoint& operator=(T);

  // Convertion
  template<typename T> inline operator T() const;

  // Getters
  inline IntegerType integer() const;
  inline DecimalType decimal() const;

  // Operations
  inline FixedPoint& operator+=(const FixedPoint&);
  inline FixedPoint& operator-=(const FixedPoint&);
  inline FixedPoint& operator*=(const FixedPoint&);
  inline FixedPoint& operator/=(const FixedPoint&);

  inline const FixedPoint operator+(const FixedPoint&) const;
  inline const FixedPoint operator-(const FixedPoint&) const;
  inline const FixedPoint operator*(const FixedPoint&) const;
  inline const FixedPoint operator/(const FixedPoint&) const;

private:
  DataType data;
};

// Constructors
template<int SIZE, int UNIT_BIT>
inline FixedPoint<SIZE, UNIT_BIT>::FixedPoint() { this->data = 0; }

template<int SIZE, int UNIT_BIT>
inline FixedPoint<SIZE, UNIT_BIT>::FixedPoint(const FixedPoint& other) { (*this) = other; }

template<int SIZE, int UNIT_BIT>
inline FixedPoint<SIZE, UNIT_BIT>::FixedPoint(IntegerType val) { (*this) = val; }

template<int SIZE, int UNIT_BIT> template<typename T>
inline FixedPoint<SIZE, UNIT_BIT>::FixedPoint(T val) { (*this) = val; }

// Assignment
template<int SIZE, int UNIT_BIT>
inline FixedPoint<SIZE, UNIT_BIT>& FixedPoint<SIZE, UNIT_BIT>::operator=(const FixedPoint& other) {
  this->data = other.data;
  return (*this);
}

template<int SIZE, int UNIT_BIT>
inline FixedPoint<SIZE, UNIT_BIT>& FixedPoint<SIZE, UNIT_BIT>::operator=(IntegerType val) {
  this->data = val << UNIT_BIT;
  return (*this);
}

template<int SIZE, int UNIT_BIT> template<typename T>
inline FixedPoint<SIZE, UNIT_BIT>& FixedPoint<SIZE, UNIT_BIT>::operator=(T val) {
  this->data = val * (1 << UNIT_BIT);
  return (*this);
}

// Conversion
template<int SIZE, int UNIT_BIT> template<typename T> 
inline FixedPoint<SIZE, UNIT_BIT>::operator T() const {
  return (T)(this->integer()) + (T)(this->decimal() / (T)(1 << UNIT_BIT));
}

// Getters
template<int SIZE, int UNIT_BIT>
inline typename FixedPoint<SIZE, UNIT_BIT>::IntegerType FixedPoint<SIZE, UNIT_BIT>::integer() const {
  return this->data >> UNIT_BIT;
}

template<int SIZE, int UNIT_BIT>
inline typename FixedPoint<SIZE, UNIT_BIT>::DecimalType FixedPoint<SIZE, UNIT_BIT>::decimal() const {
  return this->data & ((1 << UNIT_BIT)-1);
}

// Operations
template<int SIZE, int UNIT_BIT>
inline FixedPoint<SIZE, UNIT_BIT>& FixedPoint<SIZE, UNIT_BIT>::operator+=(const FixedPoint<SIZE, UNIT_BIT>& other) {
  this->data += other.data;
  return (*this);
}

template<int SIZE, int UNIT_BIT>
inline FixedPoint<SIZE, UNIT_BIT>& FixedPoint<SIZE, UNIT_BIT>::operator-=(const FixedPoint<SIZE, UNIT_BIT>& other) {
  this->data -= other.data;
  return (*this);
}

template<int SIZE, int UNIT_BIT>
inline FixedPoint<SIZE, UNIT_BIT>& FixedPoint<SIZE, UNIT_BIT>::operator*=(const FixedPoint<SIZE, UNIT_BIT>& other) {
  typename Integer<SIZE*2>::Signed tmp = this->data * other.data; // to avoid overflow !
  this->data = tmp >> UNIT_BIT;
  return (*this);
}

template<int SIZE, int UNIT_BIT>
FixedPoint<SIZE, UNIT_BIT>& FixedPoint<SIZE, UNIT_BIT>::operator/=(const FixedPoint<SIZE, UNIT_BIT>& other) {
  double tmp = (double)(*this) / (double)other; // no idea...
  (*this) = tmp;
  return (*this);
}

template<int SIZE, int UNIT_BIT>
inline const FixedPoint<SIZE, UNIT_BIT> FixedPoint<SIZE, UNIT_BIT>::operator+(const FixedPoint<SIZE, UNIT_BIT>& other) const {
  return FixedPoint<SIZE, UNIT_BIT>(*this) += other;
}

template<int SIZE, int UNIT_BIT>
inline const FixedPoint<SIZE, UNIT_BIT> FixedPoint<SIZE, UNIT_BIT>::operator-(const FixedPoint<SIZE, UNIT_BIT>& other) const {
  return FixedPoint<SIZE, UNIT_BIT>(*this) -= other;
}

template<int SIZE, int UNIT_BIT>
inline const FixedPoint<SIZE, UNIT_BIT> FixedPoint<SIZE, UNIT_BIT>::operator*(const FixedPoint<SIZE, UNIT_BIT>& other) const {
  return FixedPoint<SIZE, UNIT_BIT>(*this) *= other;
}

template<int SIZE, int UNIT_BIT>
inline const FixedPoint<SIZE, UNIT_BIT> FixedPoint<SIZE, UNIT_BIT>::operator/(const FixedPoint<SIZE, UNIT_BIT>& other) const {
  return FixedPoint<SIZE, UNIT_BIT>(*this) /= other;
}

#endif//FIXED_POINT_HPP
