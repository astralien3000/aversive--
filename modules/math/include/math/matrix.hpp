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

#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "../base/integer.hpp"
#include "../base/array.hpp"
#include "vect.hpp"

template<int WIDTH, int HEIGHT, typename ElementType>
class Matrix {
private:
  ElementType _data[WIDTH * HEIGHT];

public:
  //! \brief Default Constructor
  inline Matrix(void) : _data{0} {}

  //! \brief Copy Constructor
  inline Matrix(const Matrix& other) {
    for(int i = 0 ; i < WIDTH * HEIGHT ; i++) {
      _data[i] = other._data[i];
    }
  }
  
  //! \brief Copy Operator
  inline Matrix& operator=(const Matrix& other) {
    for(int i = 0 ; i < WIDTH * HEIGHT ; i++) {
      _data[i] = other._data[i];
    }
    return *this;
  }

  //! \brief Access to the Element (i,j)
  inline ElementType& coord(int i, int j) {
    return _data[i + j * HEIGHT];
  }

  //! \brief Operate the addition with an other matrix
  Matrix& operator+=(const Matrix& other) {
    for(int i = 0 ; i < WIDTH * HEIGHT ; i++) {
      _data[i] += other._data[i];
    }
    return *this;
  }

  //! \brief Operate the substraction with an other matrix
  Matrix& operator-=(const Matrix& other) {
    for(int i = 0 ; i < WIDTH * HEIGHT ; i++) {
      _data[i] -= other._data[i];
    }
    return *this;
  }

  //! \brief Operate the multiplication with a scalar
  template<typename T> inline Matrix& operator*=(const T val) {
    for(int i = 0 ; i < WIDTH * HEIGHT ; i++) {
      _data[i] *= val;
    }
    return *this;    
  }

  //! \brief Returns the addition of two matrix
  inline Matrix operator+(const Matrix& other) const {
    return Matrix(*this) += other;
  }

  //! \brief Returns the substraction of the matrix with another
  inline Matrix operator-(const Matrix& other) const {
    return Matrix(*this) -= other;
  }

  //! \brief Returns the multiplication of the matrix with a scalar
  template<typename T> inline Matrix operator*(const T val) const {
    return Matrix(*this) *= val;
  }

  //! \brief Apply the matrix to a vector
  template<typename T>
  Vect<HEIGHT, T> operator*(Vect<WIDTH, T>& v) {
    Vect<HEIGHT, T> ret;
    for(int j = 0 ; j < HEIGHT ; j++) {
      for(int i = 0 ; i < WIDTH ; i++) {
	ret.coord(j) += coord(i, j) * v.coord(i);
      }
    }
    return ret;
  }

  //! \brief Multiplication of two matrices
  //! \todo
  template<int O_WIDTH, typename T>
  Matrix<HEIGHT, O_WIDTH, T> operator*(const Matrix<O_WIDTH, WIDTH, T>& v) {
    Matrix<HEIGHT, O_WIDTH, T> ret;
    for(int j = 0 ; j < HEIGHT ; j++) {
      for(int i = 0 ; i < WIDTH ; i++) {
	//ret.coord(j) += coord(i, j) * v.coord(i);
      }
    }
    return ret;
  }

  //! \todo
  Matrix<HEIGHT, WIDTH, ElementType> transpose(void) { return Matrix<HEIGHT, WIDTH, ElementType>(); }
  
  //! \todo
  Matrix<WIDTH, WIDTH, ElementType> inv(void) { return Matrix<WIDTH, WIDTH, ElementType>(); }
  
};

#endif//MATRIX_HPP
