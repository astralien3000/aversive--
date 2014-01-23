#ifndef BUFFER_HPP
#define BUFFER_HPP

//! \file buffer.hpp

#include <base/array.hpp>

typedef array_t buffer_t;

//! \brief Maximum number of elements the buffer can handle
static const buffer_t MAX_BUFFER_SIZE = 1 << (ARRAY_INDEX_LENGTH - 1);

//! \bried Default buffer size
static const buffer_t DEFAULT_BUFFER_SIZE = 64;

//! \class Buffer buffer.hpp container/buffer.hpp
//! \brief Buffer implementation which is thread-safe if there are only one provider and one consumer
//! \attention SIZE must be a power of 2, it is verified with an assert
//! \param SIZE the number of elements the buffer can handle at any given time
//! \param _ElementType type of the buffered elements
template <buffer_t SIZE = DEFAULT_BUFFER_SIZE, typename ElementType = uint8_t>
class Buffer {
public:
  static const buffer_t size = SIZE;
  
private:
  Array<SIZE, ElementType> _list;
  volatile buffer_t _reads;
  volatile buffer_t _writes;
  
public:
  //! \brief Default Constructor
  inline Buffer() :
    _list(), _reads(0), _writes(0) {
    static_assert((SIZE != 0 && (SIZE & (SIZE - 1)) == 0), "Buffer size must be a power of 2.");
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
  inline bool dequeue(void) {
    if(isEmpty()) {
      return false;
    }
    _reads++;
    return true;
  }
  
  //! \brief Add an element to the buffer
  inline bool enqueue(const ElementType& element) {
    if(isFull()) {
      return false;
    }
    _list[_writes % SIZE] = element;
    _writes++;
    return true;
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
    return usedSpace() >= SIZE;
  }
  
  //! \brief Give the space currently in use in the buffer
  inline buffer_t usedSpace(void) const {
    return (_writes - _reads);
  }
  
  //! \brief Give the space currently free to use in the buffer
  inline buffer_t freeSpace(void) const {
    return usedSpace() <= SIZE;
  }
};

#endif//BUFFER_HPP
