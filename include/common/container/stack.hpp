#ifndef STACK_HPP
#define STACK_HPP

//! \brief Stack Interface
//! \param _Impl : The implementation chosen
/*!

  It is the interface for a "last in first out" container, wich mean
  that the last added element ("pushed"), is also the first that is
  deleted from the container ("poped").  You can only access to the
  first element (the "head").

 */
class Stack {
public:
  //! \brief Default Constructor
  inline Stack();
  //! \brief Copy Constructor
  inline Stack(const Stack&);
  
  //! \brief Copy Operator
  Stack& operator=(const Stack&);

  //! \brief Delete the head element
  void pop(void);
  //! \brief Add an element, wich will be at head
  void push(const ElementType&);
  
  //! \brief Access to the head element
  inline ElementType& head(void);
  //! \brief Test if the Stack is empty
  inline bool empty(void) const;
};

#endif//STACK_HPP
