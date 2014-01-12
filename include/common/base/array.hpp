#ifndef ARRAY_HPP
#define ARRAY_HPP

//! \brief Array object, as native array with copy action
//! \param SIZE the number of element in the array
//! \param ElementType type of elements contained
template<int SIZE, typename ElementType>
class Array {
private:
  ElementType element[SIZE];

public:
  enum Info { size = SIZE };

  //! \brief Default Constructor
  inline Array(void) {}

  //! \brief Constructor with initialisation
  inline Array(const ElementType& e) {
    for(int i = 0 ; i < SIZE ; i++) {
      this->element[i] = e;
    }
  }

  //! \brief Copy Constructor
  inline Array(const Array& other) {
    (*this) = other;
  }

  //! \brief Copy Operator
  Array& operator=(const Array& other) {
    for(int i = 0 ; i < SIZE ; i++) {
      this->element[i] = other.element[i];
    }
    return (*this);
  }

  //! \brief Access to element's reference with index
  //! \param index : The index of element to access
  //! \return The element contained at the specified index
  inline ElementType& operator[](int i) {
    return this->element[i];
  }

  //! \brief Access to element with index (const version)
  //! \param index : The index of element to access
  //! \return The element contained at the specified index
  inline const ElementType& operator[](int i) const {
    return this->element[i];
  }

  //! \brief Access to a constant element with index
  //! \param index : The index of element to access
  //! \return The element contained at the specified index
  inline const ElementType& operator[](IndexType i) const {
    return this->element[i];
  }
};


////////////////////////////////////////////////
// Augmented Array
// TODO : move

//! \brief Add to the array's elements the elements of an other array with the same size
template<int SIZE, typename T>
Array<SIZE, T>& operator+=(Array<SIZE, T>& array, const Array<SIZE, T>& other) {
  for(int i = 0 ; i < SIZE ; i++) {
    array[i] += other[i];
  }
  return array;
}


//! \brief Substract to the array's elements the elements of an other array with the same size
template<int SIZE, typename T>
Array<SIZE, T>& operator-=(Array<SIZE, T>& array, const Array<SIZE, T>& other) {
  for(int i = 0 ; i < SIZE ; i++) {
    array[i] -= other[i];
  }
  return array;
}

  
//! \brief Multiply the array's elements with the elements of an other array with the same size
template<int SIZE, typename T>
Array<SIZE, T>& operator*=(Array<SIZE, T>& array, const Array<SIZE, T>& other) {
  for(int i = 0 ; i < SIZE ; i++) {
    array[i] *= other[i];
  }
  return array;
}

  
//! \brief Divide the array's elements by the elements of an other array with the same size
template<int SIZE, typename T>
Array<SIZE, T>& operator/=(Array<SIZE, T>& array, const Array<SIZE, T>& other) {
  for(int i = 0 ; i < SIZE ; i++) {
    array[i] /= other[i];
  }
  return array;
}

  
//! \brief Get the modulo of the array's elements divided by the elements of an other array with the same size
template<int SIZE, typename T>
Array<SIZE, T>& operator%=(Array<SIZE, T>& array, const Array<SIZE, T>& other) {
  for(int i = 0 ; i < SIZE ; i++) {
    array[i] %= other[i];
  }
  return array;
}

template<int SIZE, typename T>
Array<SIZE, T> operator+(const Array<SIZE, T>& a1, const Array<SIZE, T>& a2) {
  Array<SIZE, T> ret(a1);
  return ret += a2;
}

template<int SIZE, typename T>
Array<SIZE, T> operator-(const Array<SIZE, T>& a1, const Array<SIZE, T>& a2) {
  Array<SIZE, T> ret(a1);
  return ret -= a2;
}

template<int SIZE, typename T>
Array<SIZE, T> operator*(const Array<SIZE, T>& a1, const Array<SIZE, T>& a2) {
  Array<SIZE, T> ret(a1);
  return ret *= a2;
}

template<int SIZE, typename T>
Array<SIZE, T> operator/(const Array<SIZE, T>& a1, const Array<SIZE, T>& a2) {
  Array<SIZE, T> ret(a1);
  return ret /= a2;
}

template<int SIZE, typename T>
Array<SIZE, T> operator%(const Array<SIZE, T>& a1, const Array<SIZE, T>& a2) {
  Array<SIZE, T> ret(a1);
  return ret %= a2;
}

#endif//ARRAY_HPP
