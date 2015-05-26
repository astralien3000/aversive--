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

#ifndef STACK_HPP
#define STACK_HPP

#include <base/array.hpp>
#include <base/integer.hpp>

typedef array_t stack_t;

//! \class Stack stack.hpp <container/stack.hpp>
//! \brief Class representing a stack (lifo)
//! \param _SIZE : the maximum number of elements the stack can handle at any given time.
//! \param _ElementType : the type of the elements within the stack.
template <stack_t _SIZE = 0, typename _ElementType = u8>
class Stack {
public:
  //! \brief Maximum number of elements a stack can handle.
  static const stack_t MAX_SIZE = Array<>::MAX_SIZE;
  
  //! \brief Number of elements the stack can handle.
  static const stack_t SIZE = _SIZE;
  
  //! \brief Element's type.
  typedef _ElementType ElementType;
  
  //! \brief Element's reference type.
  typedef typename Array<SIZE, ElementType>::ElementRef ElementRef;
  
  //! \brief Element's constant reference type.
  typedef typename Array<SIZE, ElementType>::ElementConstRef ElementConstRef;
  
private:
  //! \brief The array containing the stacked elements.
  Array<SIZE, ElementType> _data;
  
  //! \brief The current size of the stack.
  stack_t _size;
  
  //! \brief Variadic templated method to insert multiple elements at the construction of the stack.
  //! \param e : the next element to add to the stack.
  //! \param args : the remaining arguments.
  template<typename... Targs>
  inline void set(ElementConstRef e, const Targs&... args) {
    push(e);
    set(args...);
  }
  
  //! \brief Termination method to insert multiple elements at the construction of the stack.
  inline void set(void) {
  }
  
public:
  //! \brief Default constructor.
  inline Stack(void)
    : _data(), _size(0) {
  }
  
  //! \brief Copy constructor.
  //! \param other : the stack to copy.
  inline Stack(const Stack& other)
    : _data(other._data), _size(other._size) {
  }
  
  //! \brief Variadic constructor to insert multiple elements.
  //! \param args : the value list to insert in the stack.
  template<typename... Targs>
  inline Stack(const Targs&... args)
    : Stack() {
    set(args...);
  }
  
  //! \brief Copy operator.
  //! \param other : the stack to copy.
  //! \return A reference to the stack that has been written.
  inline Stack& operator=(const Stack& other) {
    _data = other._data;
    _size = other._size;
    return (*this);
  }
  
  //! \brief Remove the head of the stack.
  //! \return A boolean telling whether the removal was successful or not.
  inline bool pop(void) {
    if(_size == 0) {
      return false;
    }
    _size--;
    return true;
  }
  
  //! \brief Pile up an element on top of the stack.
  //! \param element : the element to add to the stack.
  //! \return A boolean telling whether the addition was successful or not.
  inline bool push(ElementConstRef element) {
    if(_size == SIZE) {
      return false;
    }
    _data[_size++] = element;
    return true;
  }
  
  //! \brief Completely empty the stack.
  inline void flush(void) {
    _size = 0;
  }
  
  //! \brief Access to the most recently added element of the stack.
  //! \return A constant reference to the element at the top of the stack.
  //! \warning If the stack is actually empty, this causes an undefined behavior.
  inline ElementConstRef head(void) const {
    return _data[_size - 1];
  }
  
  //! \brief Test if the stack is empty.
  //! \return A boolean telling whether the stack is empty or not.
  inline bool isEmpty(void) const {
    return _size == 0;
  }
  
  //! \brief Test if the stack is full.
  //! \return A boolean telling whether the stack is full or not.
  inline bool isFull(void) const {
    return _size == SIZE;
  }
  
  //! \brief Give the space currently in use in the stack.
  //! \return The amount of elements currently stacked.
  inline stack_t usedSpace(void) const {
    return _size;
  }
  
  //! \brief Give the space currently free to use in the stack.
  //! \return The amount of elements that can currently be stacked.
  inline stack_t freeSpace(void) const {
    return SIZE - usedSpace();
  }
};

#endif//STACK_HPP
