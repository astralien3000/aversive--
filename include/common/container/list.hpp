#ifndef LIST_HPP
#define LIST_HPP

#include <base/array.hpp>

template<int SIZE, typename ElementType>
class List {
private:
  Array<SIZE, ElementType> _data;
  volatile int _size;
  volatile int _iterator;

  template<typename T1>
  inline void set(T1 a1) {
    _data[_size++] = a1;
  }

  template<typename T1, typename... Targs>
  inline void set(T1 a1, Targs... args) {
    _data[_size++] = a1;
    set<Targs...>(args...);
  }

public:
  //! \brief Default Constructor
  List(void) : _data {0}, _size(0) {}

  //! \brief Initialize Constructor
  template<typename... Targs>
  List(Targs... args) : List() {
    set(args...);
  }

  //! \brief Copy Constructor
  List(const List& other) {
    *this = other;
  }

  //! \brief Copy Operator
  List& operator=(const List& other) {
    _size = other._size;
    for(int i = 0 ; i < _size ; i++) {
      _data[i] = other._data[i];
    }
    return *this;
  }

  //! \brief Insert an element at index
  void insert(int index, const ElementType& elem) {
    if(_size < SIZE && 0 <= index && index < _size) {
      _size++;
      for(int i = _size-1 ; index < i ; i--) {
	_data[i] = _data[i-1];
      }
      _data[index] = elem;
      if(index < _iterator) {
	_iterator++;
      }
    }
  }

  //! \brief Remove the element at index
  void remove(int index) {
    if(0 < _size && 0 <= index && index < _size) {
      for(int i = index+1 ; i < _size ; i++) {
	_data[i-1] = _data[i];
      }
      _size--;
      if(index < _iterator) {
	_iterator--;
      }
    }
  }

  //! \brief Get the size of the list
  int size(void) const {
    return _size;
  }

  //! \brief Get the element at index
  ElementType& get(int index) {
    if(0 <= index && index < _size) {
      return _data[index];
    }
    return *(int*)0;
  }

  //! \brief Get the element at index (const version)
  const ElementType& get(int index) const {
    if(0 <= index && index < _size) {
      return _data[index];
    }
    return *(int*)0;
  }
  

  //! \brief Call a function on each element of the list
  template<typename Callable>
  void doForeach(Callable func) {
    for(_iterator = 0 ; _iterator < _size ; _iterator++) {
      func(_data[_iterator]);
    }
  }  

};

#endif//LIST_HPP
