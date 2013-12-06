#ifndef TUPLE_HPP
#define TUPLE_HPP

#include "type_list.hpp"

//! \brief Container of several objects (called members) with different types
//! \param T{N} type of the N-th member
template<typename ...TArgs>
class Tuple : public Tuple<TArgs...> {
public:
  typedef TypeList<T1, TArgs...> ElementTypeList;

  //! \brief Default Constructor
  inline Tuple();
  //! \brief Constructor
  //! \param arg{N} a reference to object to copy in N-th member
  inline Tuple(T1 a1, TArgs... args);
  //! \brief Copy Constructor
  inline Tuple(const Tuple&);

  //! \brief Copy Operator
  inline Tuple& operator=(const Tuple&);

private:
  class PrivateData;
  PrivateData data;
};


//! \brief Access to the N-th member
template<int ID = 0, class ...TArgs> TypeListIterator<TArgs..., ID>& get(Tuple<TArgs...>&);

#include <base/tuple_private_data.hpp>

#endif//TUPLE_HPP
