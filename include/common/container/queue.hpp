#ifndef QUEUE_HPP
#define QUEUE_HPP

//! \brief Queue interface
class Queue {
public:
  //! \brief Default Constructor
  inline Queue();
  //! \brief Copy Constructor
  inline Queue(const Queue&);
  
  //! \brief Copy Operator
  Queue& operator=(const Queue&);

  //! \brief Delete the older element (the head)
  void dequeue(void);
  //! \brief Add an element to the queue
  void enqueue(const ElementType&);
  
  //! \brief Access to the head element
  inline ElementType& head(void);
  //! \brief Test if the Queue is empty
  inline bool empty(void) const;
};

#endif//QUEUE_HPP
