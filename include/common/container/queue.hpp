#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <base/array.hpp>
#include <base/integer.hpp>

//! \brief Queue interface
template <int SIZE, typename ElementType>
class Queue {
private:
  Array<SIZE, ElementType> _data;
  volatile u16 _queue;
  volatile u16 _head;
  
public:
  //! \brief Default Constructor
  inline Queue() : _data(), _queue(0), _head(0) {}
  
  //! \brief Copy Constructor
  inline Queue(const Queue<SIZE, ElementType>& other) :
    _data(other._data), _queue(other._queue), _head(other._head) {
  }
  
  //! \brief Copy Operator
  inline Queue<SIZE, ElementType>& operator=(const Queue<SIZE, ElementType>& other){
    _data = other._data;
    _queue = other._queue;
    _head = other._head;
  }

  //! \brief Delete the oldest element
  inline void dequeue(void) {
    if(empty()) {
      return false;
    }
    _queue++;
  }
  
  //! \brief Add an element to the buffer
  inline void enqueue(const ElementType& element) {
    if(full()) {
      return false;
    }

    _data[_head % SIZE] = element;
    _head++;
  }
  
  //! \brief Access to the oldest element
  //! \attention If the buffer is actually empty, this causes an undefined behavior
  inline ElementType& head(void) const {
    return _data[_queue % SIZE];
  }
  
  //! \brief Test if the buffer is empty
  inline bool empty(void) const {
    return _queue == _head;
  }
  
  //! \brief Test if the buffer is full
  inline bool full(void) const {
    return (_head - _queue) >= SIZE;
  }
};

/*
//! \brief Queue interface
template<int SIZE, typename ElementType>
class Queue {
private:
  Array<SIZE, ElementType> _data;
  u16 _head, _queue;

public:
  //! \brief Default Constructor
  inline Queue() : _data{0}, _head(0), _queue(0) {}

  //! \brief Copy Constructor
  inline Queue(const Queue& other) {
    *this = other;
  }
  
  //! \brief Copy Operator
  Queue& operator=(const Queue& other) {
    _size = other._size;
    for(u16 i = 0 ; i < _size ; i++) {
      _data[i] = other._data[i];
    }
    return *this;
  }

  //! \brief Delete the older element (the head)
  void dequeue(void) {
    
  }

  //! \brief Add an element to the queue
  void enqueue(const ElementType&);
  
  //! \brief Access to the head element
  inline ElementType& head(void);
  //! \brief Test if the Queue is empty
  inline bool empty(void) const;
};
*/
#endif//QUEUE_HPP
