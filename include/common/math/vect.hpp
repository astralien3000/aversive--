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

#ifndef VECT_HPP
#define VECT_HPP

#include <math/sqrt.hpp>

//! \brief Represents a vector in N dimentional space
//! \param DIM : the dimension of the space
//! \param ElementType : type of coordinates
template<int DIM, typename ElementType>
class Vect {
private:
  ElementType _coord[DIM];

  template<int NUM = 0, typename T1, typename... TArgs>
  void set(T1 a1, TArgs... args) {
    _coord[NUM] = a1;
    set<NUM+1, TArgs...>(args...);
  }

  template<int NUM, typename T1>
  void set(T1 a1) {
    _coord[NUM] = a1;
    static_assert(NUM < DIM, "ERROR : Too many elements in Vect constructor");
  }

public:
  //! \brief Default Constructor
  inline Vect(void) : _coord{0} {}

  //! \brief Initializer Constructor
  template<typename... TArgs>
  inline Vect(TArgs... args) {
    set<0, TArgs...>(args...);
  }

  //! \brief Copy Constructor
  inline Vect(const Vect& other) : Vect() {
    (*this) = other;
  }

  //! \brief Copy Operator
  inline Vect& operator=(const Vect& other) {
    for(int i = 0 ; i < DIM ; i++) {
      _coord[i] = other._coord[i];
    }
    return *this;
  }

  inline bool operator==(const Vect& other) const {
    for(int i = 0; i < DIM ; i++) {
      if(_coord[i] != other._coord[i]) {
	return false;
      }
    }
    return true;
  }

  //! \brief Access to the N-th element
  inline ElementType& coord(int index) {
    return _coord[index];
  }

  //! \brief Access to the N-th element (const version)
  inline const ElementType& coord(int index) const {
    return _coord[index];
  }

  inline ElementType& operator[](int index) {
    return _coord[index];
  }

  inline const ElementType& operator[](int index) const {
    return _coord[index];
  }

  //! \brief Operate the addition with an other vector
  inline Vect& operator+=(const Vect& other) {
    for(int i = 0 ; i < DIM ; i++) {
      _coord[i] += other._coord[i];
    }
    return *this;    
  }

  //! \brief Operate the substraction with an other vector
  inline Vect& operator-=(const Vect& other) {
    for(int i = 0 ; i < DIM ; i++) {
      _coord[i] -= other._coord[i];
    }
    return *this;    
  }

  //! \brief Operate the multiplication with a scalar
  template<typename T> inline Vect& operator*=(const T val) {
    for(int i = 0 ; i < DIM ; i++) {
      _coord[i] *= val;
    }
    return *this;    
  }

  //! \brief Operate the multiplication with the inverse of a scalar
  template<typename T> inline Vect& operator/=(const T val) {
    for(int i = 0 ; i < DIM ; i++) {
      _coord[i] /= val;
    }
    return *this;    
  }

  //! \brief Returns the addition of two vertex
  inline Vect operator+(const Vect& other) const {
    return Vect(*this) += other;
  }

  //! \brief Returns the substraction of the vector with another
  inline Vect operator-(const Vect& other) const {
    return Vect(*this) -= other;
  }

  //! \brief Returns the multiplication of the vector with a scalar
  template<typename T> inline Vect operator*(const T val) const {
    return Vect(*this) *= val;
  }

  //! \brief Returns the multiplication of the vector with the inverse of a scalar
  template<typename T> inline Vect operator/(const T val) const {
    return Vect(*this) /= val;
  }

  //! \brief Norm of the vector
  ElementType norm(void) const {
    return Math::sqrt(scal(*this, *this));
  }
};

//! \brief Enables the user to multiply a vector with a number (at its left)
template<int DIM, typename ET, typename T>
inline Vect<DIM, ET> operator*(const T val, const Vect<DIM, ET>& vect) {
  return vect * val;
}

//! \brief Scalar Product
template<int DIM, typename ET>
ET scal(const Vect<DIM, ET>& v1, const Vect<DIM, ET>& v2) {
  ET ret = 0;
  for(int i = 0 ; i < DIM ; i++) {
    ret += v1.coord(i) * v2.coord(i);
  }
  return ret;
}

//! \brief Cross Product
//! \warning Only for DIM = 3
template<typename ET>
Vect<3, ET> cross(const Vect<3, ET>& v1, const Vect<3, ET>& v2) {
  return Vect<3, ET>(
		     v1.coord(1) * v2.coord(2) - v1.coord(2) * v2.coord(1),
		     -(v1.coord(0) * v2.coord(2) - v1.coord(2) * v2.coord(0)),
		     v1.coord(0) * v2.coord(1) - v1.coord(1) * v2.coord(0)
		     );
}

//! \brief Return the direct normal of a 2 DIM vector
template<typename ET>
Vect<2, ET> normal(const Vect<2, ET>& v) {
  Vect<3, ET> v3(v.coord(0), v.coord(1), 0);
  Vect<3, ET> z(0,0,1);
  Vect<3, ET> ret = cross(z, v3);
  return Vect<2, ET>(ret.coord(0), ret.coord(1));
}

#endif//VECT_HPP
