#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

template<int SIZE, typename _ElementType, typename _IndexType = int>
class BinarySearchTree {
public:
  typename _ElementType ElementType;
  typename _IndexType IndexType;

  // Constructors
  BinarySearchTree();
  BinarySearchTree(const BinarySearchTree&);

  // Assignment
  BinarySearchTree& operator=(const BinrarySearchTree&);

  // Operations
  inline void remove(IndexType);
  inline void insert(IndexType, const ElementType&);

  inline ElementType& operator[](IndexType);
  inline bool empty(void) const;
};

#endif//BINARY_SEARCH_TREE_HPP
