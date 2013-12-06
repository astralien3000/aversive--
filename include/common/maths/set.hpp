#ifndef SET_HPP
#define SET_HPP

#include "../base/pair.hpp"

//! \brief Mathematical definition of set
//! \param _SetImpl : Implementation of the set
//! \param _ElementType : Contained elements' type
template<typename _SetImpl>
class Set : protected _SetImpl {
public:
  typedef _Impl::ElementType ElementType;

  //! \brief Default Constructor
  inline Set();
  //! \brief Singleton Constructor
  inline Set(const ElementType&);
  //! \brief Set Constructor
  template<typename T1, typename ...Args> inline Set(T1&, Args& ...);
  //! \brief Copy Constructor
  inline Set(const Set&);

  //! \brief Copy Operator
  inline Set& operator=(const Set&);
  
  //! \brief Operate union on the set with an other
  inline Set& operator|=(const Set&);
  //! \brief Operate intersection on the set with an other
  inline Set& operator&=(const Set&);

  //! \brief Operate union of two set
  inline Set& operator|(const Set&) const;
  //! \brief Operate intersection of two set
  inline Set& operator&(const Set&) const;

  //! \brief Test equality between two sets
  inline bool operator==(const Set&) const;
  //! \brief Test inequality between two sets
  inline bool operator!=(const Set&) const;
  //! \brief Test if the set is contained in the other
  inline bool operator<=(const Set&) const;
  //! \brief Test if the set is strictly contained in the other
  inline bool operator< (const Set&) const;
  //! \brief Test if the set contains the other
  inline bool operator>=(const Set&) const;
  //! \brief Test is the set contains strictly the other
  inline bool operator> (const Set&) const;

  //! \brief Operate the multiplication between two sets
  //! \todo Not use Pair, since it makes the operation not associative
  template<typename OtherElementType> 
  inline Set<_Impl, Pair<ElementType, OtherElementType>> operator*(const Set<_Impl, OtherElementType>&) const;

  //! \brief Execute a function on each element of the set
  //! \param func : A function taking an element's reference of the set as parameter
  template<class Callable> inline void foreach(const Callable&);
};

#endif//SET_HPP
