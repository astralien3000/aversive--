#ifndef HEAP_HPP
#define HEAP_HPP

//! \brief Heap interface
//! \param _Impl : The implementation chosen
/*!
  The heap enable to extract easily the maximum of a set of values.
  Once the element is inserted, it is compared to others to order it.
  The only element accessible and deletable is the maximum.
  The maximum is the element for which the comparison function returns true 
  foreach comparision with others element in the heap.
 */
template<typename _HeapImpl>
class Heap : protected _HeapImpl {
public:
  typedef _Impl::ElementType ElementType;

  //! \brief Default Constructor
  inline Heap();
  //! \brief Copy Constructor
  inline Heap(const Heap&);

  //! \brief Copy Operator
  inline Heap& operator=(const Heap&);

  //! \brief Delete the maximal element
  inline void pop(void);
  //! \brief Insert an element in the Heap
  inline void insert(const ElementType&);

  //! \brief Access to the maximal element
  inline ElementType& max(void);
  //! \brief Test if the Heap is empty
  inline bool empty(void) const;
};

#endif//HEAP_HPP
