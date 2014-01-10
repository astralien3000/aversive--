#ifndef ARRAY_HPP
#define ARRAY_HPP

//! \brief Array object, as native array with copy action
//! \param SIZE the number of element in the array
//! \param _ElementType type of elements contained
//! \param _IndexType type used as index, enable to use safer types than "int"
template<int SIZE, typename _ElementType, typename _IndexType = int>
class Array {
private:
  _ElementType element[(_IndexType)SIZE];

public:
  typedef _ElementType ElementType;
  typedef _IndexType IndexType;
  enum Info { size = SIZE };

  //! \brief Default Constructor
  inline Array() {
  }

  //! \brief Constructor with initialisation
  inline Array(const ElementType& e) {
    for(_IndexType i = 0 ; i < SIZE ; i++) {
      this->element[i] = e;
    }
  }

  //! \brief Copy Constructor
  inline Array(const Array& other) {
    (*this) = other;
  }

  //! \brief Copy Operator
  inline Array& operator=(const Array& other) {
    for(_IndexType i = 0 ; i < SIZE ; i++) {
      this->element[i] = other.element[i];
    }
    return (*this);
  }
  
  //! \brief Access to element with index
  //! \param index : The index of element to access
  //! \return The element contained at the specified index
  inline ElementType& operator[](IndexType i) {
    return this->element[i];
  }

  //! \brief Access to a constant element with index
  //! \param index : The index of element to access
  //! \return The element contained at the specified index
  inline const ElementType& operator[](IndexType i) const {
    return this->element[i];
  }
};

#endif//ARRAY_HPP
