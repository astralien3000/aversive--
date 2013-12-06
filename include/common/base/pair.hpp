#ifndef PAIR_HPP
#define PAIR_HPP

//! \brief Specialisation of Tuple with two members
//! \param _LeftType : first member (aka left member) type
//! \param _RightType : second member (aka right member) type
template<typename _LeftType, typename _RightType>
class Pair {
private:
  _LeftType _left;
  _RightType _right;

public:
  typedef _LeftType LeftType;
  typedef _RightType RightType;

  //! \brief Default Constructor
  inline Pair(void) {
  }

  //! \brief Constructor
  //! \param left : a reference to object to copy in the first (=left) member
  //! \param right : a reference to object to copy in the second (=right) member
  inline Pair(const LeftType& l, const RightType& r) : 
    _left(l), _right(r) {
  }

  //! \brief Copy Constructor
  inline Pair(const Pair& other) {
    (*this) = other;
  }

  //! \brief Copy Operator
  inline Pair& operator=(const Pair& other) {
    this->_left = other._left;
    this->_right = other._right;
    return (*this);
  }

  //! \brief Access to the first (=left) member
  inline LeftType& left(void) {
    return this->_left;
  }

  //! \brief Access to the second (=right) member
  inline RightType& right(void) {
    return this->_right;
  }
};

#endif//PAIR_HPP
