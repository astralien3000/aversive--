#ifndef CHILD_NODE_HPP
#define CHILD_NODE_HPP

#include "node.hpp"

class ParentNode;

class ChildNode : virtual public Node {
public:
  ChildNode(void);

  virtual ~ChildNode(void);

  virtual void setParent(ParentNode*);
  ParentNode* parent(void);

private:
  ParentNode* _parent;
};

#endif//PARENT_NODE_HPP
