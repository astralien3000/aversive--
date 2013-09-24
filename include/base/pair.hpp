#ifndef PAIR_HPP
#define PAIR_HPP

#include "tuple.hpp"

//! \brief Specialisation of Tuple with two members
//! \param _LeftType : first member (aka left member) type
//! \param _RightType : second member (aka right member) type
template<typename _LeftType, typename _RightType>
class Pair : Tuple<_LeftType, _RightType> {
public:
  typedef _LeftType LeftType;
  typedef _RightType RightType;

  //! \brief Default Constructor
  inline Pair();

  //! \brief Constructor
  //! \param left : a reference to object to copy in the first (=left) member
  //! \param right : a reference to object to copy in the second (=right) member
  inline Pair(const LeftType&, const RightType&);

  //! \brief Copy Constructor
  inline Pair(const Pair&);

  //! \brief Copy Operator
  inline Pair& operator=(const Pair&);

  //! \brief Access to the first (=left) member
  inline LeftType& left(void);
  //! \brief Access to the second (=right) member
  inline RightType& right(void);
};

#endif//PAIR_HPP
