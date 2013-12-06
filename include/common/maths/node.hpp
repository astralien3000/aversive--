#ifndef NODE_HPP
#define NODE_HPP

// TODO : Redefine with lists !!!

//! \brief Node object, with references to other nodes
//! \param _ElementType : The type of the label
//! \param CHILDREN : max number of children nodes references available
//! \param PARENTS : max number of parent nodes references available
template<typename _ElementType, int CHILDREN, int PARENTS>
class Node {
public:
  typedef _ElementType ElementType;

  //! \brief Contain max infos
  enum Info {
    children = CHILDREN,
    parents = PARENTS
  };

  //! \brief Default Constructor
  inline Node();
  //! \brief Copy Constructor
  inline Node(const Node&);

  //! \brief Copy Operator
  inline Node& operator=(const Node&);

  //! \brief Returns a reference to a child node
  //! \param ID (template) : the id of the child
  template<int ID = 0> inline Node& next();
  //! \brief Returns a reference to a parent node
  //! \param ID (template) : the id of the parent
  template<int ID = 0> inline Node& prev();

  //! \brief Returns true if node has at least one child reference
  inline bool hasNext();

  //! \brief Returns true if node has at least one parent reference
  inline bool hasPrev();

  inline int numNext();
  inline int numPrev();

  inline ElementType& data();
};

#endif//NODE_HPP
