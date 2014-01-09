#ifndef VECT_HPP
#define VECT_HPP

//! \brief Represents a vector in N dimentional space
//! \param DIM : the dimension of the space
//! \param ElementType : type of coordinates
template<int DIM, typename ElementType>
class Vect {
private:
  ElementType _coord[DIM];

public:
  //! \brief Default Constructor
  inline Vect(void) : _coord{0} {}

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

  //! \brief Access to the N-th element
  inline ElementType& coord(int index) {
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
      _coord[i] += other._coord[i];
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
};

//! \brief Enables the user to multiply a vector with a number (at its left)
template<int DIM, typename ET, typename T>
inline Vect<DIM, ET> operator*(const T val, const Vect<DIM, ET>& vect) {
  return vect * val;
}

#endif//VECT_HPP
