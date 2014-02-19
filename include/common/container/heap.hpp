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
  friend class Node;

  Array<S, T> _data;
  int _size;

  //! \brief Private class representing a node in a binary tree
  /*
    Useful for percolation functions.
   */
  class Node {
  private:
    Heap& _heap;
    int _index;

  public:
    //! \brief Constructor
    inline Node(Heap& h, int index) : _heap(h), _index(index) {}
    
    //! \brief Copy operator
    inline Node& operator=(const Node& other) {
      _heap = other._heap;
      _index = other._index;
      return *this;
    }
    
    //! \brief Check if the node really represents an element is the heap
    inline bool exist(void) {
      return 0 < _index && _index < _heap._size;
    }
    
    //! \brief Exchange elements of two nodes
    //! \warning Does not change the node's position.
    inline void switchElements(Node other) {
      T aux = element();
      element() = other.element();
      other.element() = aux;
    }
    
    //! \brief Returns a reference to the node's parent
    inline Node parent(void) {
      return Node(_heap, (_index-1)/2);
    }

    //! \brief Returns a reference to the node's first child
    inline Node firstChild(void) {
      return Node(_heap, (_index*2)+1);
    }

    //! \brief Returns a reference to the node's second child
    inline Node secondChild(void) {
      return Node(_heap, (_index*2)+2);
    }

    //! \brief Check if the node is not the root
    //! (faster than parent.exist)
    inline bool parentExist(void) {
      return 0 < parent()._index;
    }

    //! \brief Check if the node has a first child 
    //! (faster than firstChild.exist)
    inline bool firstChildExist(void) {
      return firstChild()._index < _heap._size;
    }

    //! \brief Check if the node has a second child 
    //! (faster than secondChild.exist)
    inline bool secondChildExist(void) {
      return secondChild()._index < _heap._size;
    }

    //! \brief Returns a reference to the element of the node
    inline T& element(void) {
      return _heap._data[_index];
    }
  };

  //! \brief Place correctly an element which have to move upward
  void percolateUp(int index) {
    Node cur(*this, index);
    if(cur.exist()) {
      while(cur.parentExist() && cur.parent().element() < cur.element()) {
	cur.switchElements(cur.parent());
	cur = cur.parent();
      }
    }
  }

  //! \brief Place correctly an element which have to move downward
  void percolateDown(int index) {
    Node cur(*this, index);
    if(cur.exist()) {
      // While there is one child greater than current
      while((cur.firstChildExist() && 
	     cur.element() < cur.firstChild().element()) ||
	    (cur.secondChildExist() && 
	     cur.element() < cur.secondChild().element())) {
	// If there is only one child
	// The first child must be filled first !
	if(!cur.firstChildExist()) {
	  cur.switchElements(cur.secondChild());
	  cur = cur.secondChild();
	}
	else if(!cur.secondChildExist()) {
	  cur.switchElements(cur.firstChild());
	  cur = cur.firstChild();
	}
	// If there is two children
	else {
	  // Switch with the max
	  if(cur.firstChild().element() < cur.secondChild().element()) {
	    cur.switchElements(cur.secondChild());
	    cur = cur.secondChild();
	  }
	  else {
	    cur.switchElements(cur.firstChild());
	    cur = cur.firstChild();
	  }
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
    percolateUp(_size++);
  }

  //! \brief Delete the maximal element
  void pop(void) {
    _data[0] = _data[_size - 1];
    _size--;
    percolateDown(0);
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
  
  // //! \brief Return the amount of free space
  // int freeSpace(void) const {
  //   return S - _size;
  // }
  
  // //! \brief Return the amount of used space
  // int usedSpace(void) const {
  //   return _size;
  // }
  
  //! \brief To execute an operation on all elements contained
  void doForeach(void (*func)(T&)) {
    for(int i = 0 ; i < S ; i++) {
      func(_data[i]);
    }
  }
};

#endif//HEAP_HPP
