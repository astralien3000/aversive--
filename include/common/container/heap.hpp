#ifndef HEAP_HPP
#define HEAP_HPP

#include <base/array.hpp>
#include <math/saturate.hpp>

//! \brief Heap interface
/*!

  The heap enable to extract easily the maximum of a set of values.
  Once the element is inserted, it is compared to others to order it.
  The only element accessible and deletable is the maximum.  The
  maximum is the element for which the comparison function returns
  true foreach comparision with others element in the heap.

 */
template<int S, typename T>
class Heap {
private:
  Array<S, T> _data;
  int _size;

  void percolateUp(void) {
    int i = _size - 1;
    while(0 < i && _data[(i-1)/2] < _data[i]) {
      T aux = _data[i];
      _data[i] = _data[(i-1)/2];
      _data[(i-1)/2] = aux;
      i = (i-1) / 2;
    }
  }

  void percolateDown(void) {
    int i = 0;
    while((i * 2 + 1 < _size && _data[i] < _data[i * 2 + 1]) || 
	  (i * 2 + 2 < _size && _data[i] < _data[i * 2 + 2])) {
      T aux = _data[i];
      if(i * 2 + 1 >= _size) {
	_data[i] = _data[i * 2 + 2];
	_data[i * 2 + 2] = aux;
	i = i * 2 + 2;
      }
      else if(i * 2 + 2 >= _size) {
	_data[i] = _data[i * 2 + 1];
	_data[i * 2 + 1] = aux;
	i = i * 2 + 1;
      }
      else {
	_data[i] = Math::max(_data[i * 2 + 2], _data[i * 2 + 1]);
	Math::max(_data[i * 2 + 2], _data[i * 2 + 1]) = aux;
	if(_data[i * 2 + 2] == aux) {
	  i = i * 2 + 2;
	}
	else {
	  i = i * 2 + 1;
	}
      }
    }
  }

public:
  //! \brief Default Constructor
  Heap(void) : _size(0) {
  }

  //! \brief Copy Constructor
  inline Heap(const Heap& other) {
    (*this) = other;
  }

  //! \brief Copy Operator
  inline Heap& operator=(const Heap& other) {
    _size = other._size;
    for(int i = 0 ; i < S ; i++) {
      _data[i] = other._data[i];
    }
    return *this;
  }

  //! \brief Insert an element in the Heap
  void insert(const T& e) {
    _data[_size] = e;
    _size++;
    percolateUp();
  }

  //! \brief Delete the maximal element
  void pop(void) {
    _data[0] = _data[_size - 1];
    _size--;
    percolateDown();
  }

  //! \brief Access to the maximal element
  T& max(void) {
    if(!empty()) {
      return _data[0];
    }
    return *(T*)0;
  }

  //! \brief Access to the maximal element (const version)
  const T& max(void) const {
    if(!empty()) {
      return _data[0];
    }
    return *(T*)0;
  }

  //! \brief Test if the Heap is empty
  bool empty(void) const {
    return _size == 0;
  }
  
  //! \brief Test if the Heap is full
  bool full(void) const {
    return _size == S;
  }
  
  //! \brief Return the amount of free space
  int freeSpace(void) const {
    return S - _size;
  }
  
  //! \brief Return the amount of used space
  int usedSpace(void) const {
    return _size;
  }
  
  //! \brief To execute an operation on all elements contained
  void doForeach(void (*func)(T&)) {
    for(int i = 0 ; i < S ; i++) {
      func(_data[i]);
    }
  }
};

#endif//HEAP_HPP
