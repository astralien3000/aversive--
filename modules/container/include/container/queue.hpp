/*
    Aversive++                                                           
    Copyright (C) 2014 Eirbot                                            
                                                                         
    This program is free software: you can redistribute it and/or modify 
    it under the terms of the GNU General Public License as published by 
    the Free Software Foundation, either version 3 of the License, or    
    (at your option) any later version.                                  
                                                                         
    This program is distributed in the hope that it will be useful,      
    but WITHOUT ANY WARRANTY; without even the implied warranty of       
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        
    GNU General Public License for more details.                         
                                                                         
    You should have received a copy of the GNU General Public License    
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <base/array.hpp>
#include <base/integer.hpp>

typedef array_t queue_t;

//! \class Queue queue.hpp <container/queue.hpp>
//! \brief Class representing a queue (fifo).
//! \param _SIZE : the maximum number of elements the queue can handle at any given time.
//! \param _ElementType : the type of the elements within the queue.
template <queue_t _SIZE = 0, typename _ElementType = u8>
class Queue {
public:
  //! \brief Maximum number of elements a queue can handle.
  static const queue_t MAX_SIZE = Array<>::MAX_SIZE;
  
  //! \brief Number of elements the queue can handle.
  static const queue_t SIZE = _SIZE;
  
  //! \brief Element's type.
  typedef _ElementType ElementType;
  
  //! \brief Element's reference type.
  typedef typename Array<SIZE, ElementType>::ElementRef ElementRef;
  
  //! \brief Element's constant reference type.
  typedef typename Array<SIZE, ElementType>::ElementConstRef ElementConstRef;
  
private:
  //! \brief The array containing the queued elements.
  Array<SIZE, ElementType> _data;
  
  //! \brief The index in the data array where the head of the queue is.
  queue_t _head;
  
  //! \brief The current size of the queue.
  queue_t _size;
  
  //! \brief Variadic templated method to insert multiple elements at the construction of the queue.
  //! \param e : the next element to add to the queue.
  //! \param args : the remaining arguments.
  template<typename... Targs>
  inline void set(ElementConstRef e, const Targs&... args) {
    enqueue(e);
    set(args...);
  }
  
  //! \brief Termination method to insert multiple elements at the construction of the queue.
  inline void set(void) {
  }
  
public:
  //! \brief Default constructor.
  inline Queue(void)
    : _data(), _head(0), _size(0) {
  }
  
  //! \brief Copy constructor.
  //! \param other : the queue to copy.
  inline Queue(const Queue& other)
    : _data(other._data), _head(other._head), _size(other._size) {
  }
  
  //! \brief Variadic constructor to insert multiple elements.
  //! \param args : the value list to insert in the queue.
  template<typename... Targs>
  inline Queue(const Targs&... args)
    : Queue() {
    set(args...);
  }
  
  //! \brief Copy operator.
  //! \param other : the queue to copy.
  //! \return A reference to the list that has been written.
  inline Queue& operator=(const Queue& other) {
    _data = other._data;
    _head = other._head;
    _size = other._size;
    return (*this);
  }
  
  //! \brief Delete the oldest element from the queue.
  //! \return A boolean telling whether an element has been dequeued from the queue or not.
  inline bool dequeue(void) {
    if(isEmpty()) {
      return false;
    }
    _head++;
    _size--;
    return true;
  }
  
  //! \brief Add an element to the buffer
  //! \param element : the element to insert at the end of queue.
  //! \return A boolean telling whether the element has been successfully enqueued or not.
  bool enqueue(ElementConstRef element) {
    if(isFull()) {
      return false;
    }
    queue_t index = _head + _size;
    if(index >= SIZE) {
      index -= SIZE;
    }
    _data[index] = element;
    _size++;
    return true;
  }
  
  //! \brief Completely empty the list.
  inline void flush(void) {
    _size = 0;
  }
  
  //! \brief Access to the oldest element of the queue.
  //! \return A constant reference to the element at the head of the queue.
  //! \warning If the queue is actually empty, this causes an undefined behavior.
  inline ElementConstRef head(void) const {
    return _data[_head];
  }
  
  //! \brief Test if the queue is empty.
  //! \return A boolean telling whether the queue is empty or not.
  inline bool isEmpty(void) const {
    return _size == 0;
  }
  
  //! \brief Test if the queue is full.
  //! \return A boolean telling whether the queue is full or not.
  inline bool isFull(void) const {
    return _size == SIZE;
  }
  
  //! \brief Give the space currently in use in the queue.
  //! \return The amount of elements currently queued.
  inline queue_t usedSpace(void) const {
    return _size;
  }
  
  //! \brief Give the space currently free to use in the queue.
  //! \return The amount of elements that can currently be queued.
  inline queue_t freeSpace(void) const {
    return SIZE - usedSpace();
  }
};

#endif//QUEUE_HPP
