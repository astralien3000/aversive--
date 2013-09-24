#ifndef VECT_HPP
#define VECT_HPP

//! \brief Represents a vector in N dimentional space
//! \param DIM : the dimension of the space
//! \param ElementType : type of coordinates
template<int DIM, typename ElementType>
class Vect {
public:
  //! \brief Default Constructor
  Vect();
  //! \brief Copy Constructor
  Vect(const Vect&);

  //! \brief Copy Operator
  Vect& operator=(const Vect&);

  //! \brief Access to the N-th element
  template<int COORD> ElementType& coord();

  //! \brief Operate the addition with an other vector
  Vect& operator+=(const Vect&);
  //! \brief Operate the substraction with an other vector
  Vect& operator-=(const Vect&);

  //! \brief Operate the multiplication with a scalar
  template<typename T> Vect& operator*=(T);

  //! \brief Returns the addition of two vertex
  Vect operator+(const Vect&);
  //! \brief Returns the substraction of the vector with another
  Vect operator-(const Vect&);

  //! \brief Returns the multiplication of the vector with a scalar
  template<typename T> Vect operator*(T);
  
private:
  ElementType data[DIM];
};

#include "loop.hpp"

// Constructor
template<int DIM, typename ElementType>
Vect<DIM, ElementType>::Vect() {
  auto init = [&](int i){ this->data[i] = 0; };
  StaticLoop<0,DIM-1>::exec(init);
}

template<int DIM, typename ElementType>
Vect<DIM, ElementType>::Vect(const Vect<DIM, ElementType>& other) {
  (*this) = other;
}

// Assignment
template<int DIM, typename ElementType>
Vect<DIM, ElementType>& Vect<DIM, ElementType>::operator=(const Vect<DIM, ElementType>& other) {
  auto init = [&](int i){ this->data[i] = other.data[i]; };
  StaticLoop<0,DIM-1>::exec(init);
  return (*this);
}

// Getter

//// VECTOR EXTRACTOR //////////////////////////////
template<typename T, int INDEX, bool OUT = true>
struct VectorExtractor {
  inline static T& get(T* tab) {
    return tab[INDEX];
  }
};

template<typename T, int INDEX>
struct VectorExtractor<T, INDEX, false> {
  inline static T& get(T* tab) {
    throw "ERROR";
    return *tab;
  }
};
///////////////////////////////////////////////////

template<int DIM, typename ElementType> template<int COORD> 
ElementType& Vect<DIM, ElementType>::coord() {
  return VectorExtractor<ElementType, COORD, (COORD < DIM)>::get(this->data);
}

// Operations
template<int DIM, typename ElementType>
Vect<DIM, ElementType>& Vect<DIM, ElementType>::operator+=(const Vect<DIM, ElementType>& other) {
  auto init = [&](int i){ this->data[i] += other.data[i]; };
  StaticLoop<0,DIM-1>::exec(init);
  return (*this);
}

template<int DIM, typename ElementType>
Vect<DIM, ElementType>& Vect<DIM, ElementType>::operator-=(const Vect<DIM, ElementType>& other) {
  auto init = [&](int i){ this->data[i] -= other.data[i]; };
  StaticLoop<0,DIM-1>::exec(init);
  return (*this);
}

template<int DIM, typename ElementType> template<typename T>
Vect<DIM, ElementType>& Vect<DIM, ElementType>::operator*=(T val) {
  auto init = [&](int i){ this->data[i] *= val; };
  StaticLoop<0,DIM-1>::exec(init);
  return (*this);
}

template<int DIM, typename ElementType>
Vect<DIM, ElementType> Vect<DIM, ElementType>::operator+(const Vect<DIM, ElementType>& other) {
  return Vect<DIM, ElementType>(*this) += other;
}

template<int DIM, typename ElementType>
Vect<DIM, ElementType> Vect<DIM, ElementType>::operator-(const Vect<DIM, ElementType>& other) {
  return Vect<DIM, ElementType>(*this) -= other;
}

template<int DIM, typename ElementType> template<typename T>
Vect<DIM, ElementType> Vect<DIM, ElementType>::operator*(T val) {
  return Vect<DIM, ElementType>(*this) *= val;
}

#endif//VECT_HPP
