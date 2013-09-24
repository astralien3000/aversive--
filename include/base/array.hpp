#ifndef ARRAY_HPP
#define ARRAY_HPP

//! \brief Array object, as native array with copy action
//! \param SIZE the number of element in the array
//! \param _ElementType type of elements contained
//! \param _IndexType type used as index, enable to use safer types than "int"
template<int SIZE, typename _ElementType, typename _IndexType = int>
class Array {
public:
  typedef _ElementType ElementType;
  typedef _IndexType IndexType;
  enum Info { size = SIZE };

  //! \brief Default Constructor
  inline Array();
  //! \brief Copy Constructor
  inline Array(const Array&);

  //! \brief Copy Operator
  inline Array& operator=(const Array&);
  
  //! \brief Access to element with index
  //! \param index : The index of element to access
  //! \return The element contained at the specified index
  inline ElementType& operator[](IndexType);
};

#endif//ARRAY_HPP
