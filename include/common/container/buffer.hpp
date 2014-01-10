#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <assert.h>
#include "../base/array.hpp"

static inline bool is_power_of_two(int x) {
  return x != 0 && (x & (x - 1)) == 0;
}

//! \brief Buffer implementation which is thread-safe if there are only one provider and one consumer
//! \attention SIZE must be a power of 2, it is verified with an assert
//! \param SIZE the number of elements the buffer can handle at any given time
//! \param _ElementType type of the buffered elements
template <int SIZE, typename _ElementType>
class Buffer {
public:
  typedef _ElementType ElementType;
  static const int size = SIZE;
  
private:
  Array<SIZE, ElementType, int> _list;
  int _reads;
  int _writes;
  
public:
  //! \brief Default Constructor
  inline Buffer() :
    _list(), _reads(0), _writes(0) {
    assert(is_power_of_two(SIZE));
  }
  
  //! \brief Copy Constructor
  inline Buffer(const Buffer<SIZE, ElementType>& buff) :
    _list(buff._list), _reads(buff._reads), _writes(buff._writes) {
  }
  
  //! \brief Copy Operator
  inline Buffer<SIZE, ElementType>& operator=(const Buffer<SIZE, ElementType>& buff){
    _list = buff._list;
    _reads = buff._reads;
    _writes = buff._writes;
  }

  //! \brief Delete the oldest element
  inline void dequeue(void) {
    if(isEmpty()) {
      return;
    }
    _reads++;
  }
  
  //! \brief Add an element to the buffer
  inline void enqueue(const ElementType& element) {
    if(isFull()) {
      return;
    }
    _list[_writes % SIZE] = element;
    _writes++;
  }
  
  //! \brief Access to the oldest element
  //! \attention If the buffer is actually empty, this causes an undefined behavior
  inline const ElementType& head(void) const {
    return _list[_reads % SIZE];
  }
  
  //! \brief Test if the buffer is empty
  inline bool isEmpty(void) const {
    return _reads == _writes;
  }
  
  //! \brief Test if the buffer is full
  inline bool isFull(void) const {
    return usedSpace() == SIZE;
  }
  
  //! \brief Give the space currently in use in the buffer
  inline int usedSpace(void) const {
    return _writes - _reads;
  }
  
  //! \brief Give the space currently free to use in the buffer
  inline int freeSpace(void) const {
    return SIZE - usedSpace();
  }
};

#endif//BUFFER_HPP
