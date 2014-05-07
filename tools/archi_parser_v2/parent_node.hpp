#ifndef PARENT_NODE_HPP
#define PARENT_NODE_HPP

#include "node.hpp"

#include <set>

class ChildNode;

class ParentNode : virtual public Node {
public:
  ParentNode(void);

  ~ParentNode(void);

  void addChild(ChildNode*);

  bool isChild(ChildNode*);

protected:
  std::set<ChildNode*> _children;
};

#endif//PARENT_NODE_HPP
