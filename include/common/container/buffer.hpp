#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <base/array.hpp>
#include <base/integer.hpp>

typedef array_t buffer_t;

//! \class Buffer buffer.hpp <container/buffer.hpp>
//! \brief Buffer implementation which is thread-safe if there are only one provider and one consumer.
//! \warning SIZE must be a power of 2, it is verified with an assert.
//! \param SIZE : the number of elements the buffer can handle at any given time.
//! \param _ElementType : type of the buffered elements.
template <buffer_t _SIZE = 64, typename _ElementType = uint8_t>
class Buffer {
public:
  //! \brief Maximum number of elements a buffer can handle.
  static const buffer_t MAX_SIZE = IntegerInfo<Array<>::ARRAY_INDEX_LENGTH>::UNSIGNED_MAX;
  
  //! \brief Number of elements the buffer can handle.
  static const buffer_t SIZE = _SIZE;
  
private:
  //! \brief The array containing the datas.
  Array<SIZE, _ElementType> _list;
  
  //! \brief Read counter.
  volatile buffer_t _reads;
  
  //! \brief Write counter.
  volatile buffer_t _writes;
  
public:
  //! \brief Default Constructor.
  inline Buffer()
    : _list(), _reads(0), _writes(0) {
    static_assert((SIZE != 0 && (SIZE & (SIZE - 1)) == 0), "Buffer size must be a power of 2.");
  }
  
  //! \brief Copy Constructor.
  //! \param buff : the buffer to copy.
  inline Buffer(const Buffer<SIZE, _ElementType>& buff)
    : _list(buff._list), _reads(buff._reads), _writes(buff._writes) {
  }
  
  //! \brief Copy Operator.
  //! \param buff : the buffer to copy.
  //! \return A reference to the buffer that has been written.
  inline Buffer<SIZE, _ElementType>& operator=(const Buffer<SIZE, _ElementType>& buff){
    _list = buff._list;
    _reads = buff._reads;
    _writes = buff._writes;
  }

  //! \brief Delete the oldest element.
  //! \return A boolean telling whether an element has been successfully dequeued or not.
  inline bool dequeue(void) {
    if(isEmpty()) {
      return false;
    }
    _reads++;
    return true;
  }
  
  //! \brief Enqueue an element to the buffer.
  //! \param element : the element to enqueue in the buffer.
  //! \return A boolean telling whether the element has been successfully enqueued or not.
  inline bool enqueue(const _ElementType& element) {
    if(isFull()) {
      return false;
    }
    _list[_writes % SIZE] = element;
    _writes++;
    return true;
  }
  
  //! \brief Access to the oldest element.
  //! \return A reference to the element at the head of the buffer.
  //! \warning If the buffer is actually empty, this causes an undefined behavior.
  inline const _ElementType& head(void) const {
    return _list[_reads % SIZE];
  }
  
  //! \brief Test if the buffer is empty.
  //! \return A boolean telling whether the buffer is empty or not.
  inline bool isEmpty(void) const {
    return _reads == _writes;
  }
  
  //! \brief Test if the buffer is full.
  //! \return A boolean telling whether the buffer is full or not.
  inline bool isFull(void) const {
    return usedSpace() >= SIZE;
  }
  
  //! \brief Give the space currently in use in the buffer.
  //! \return The amount of elements currently buffered.
  inline buffer_t usedSpace(void) const {
    return (_writes - _reads);
  }
  
  //! \brief Give the space currently free to use in the buffer.
  //! \return The amount of elements that can currently be buffered.
  inline buffer_t freeSpace(void) const {
    return SIZE - usedSpace();
  }
};

#endif//BUFFER_HPP
