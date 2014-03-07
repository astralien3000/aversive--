#include "child_node.hpp"

#include "parent_node.hpp"

ChildNode::ChildNode(void) : _parent(0) {
}

ChildNode::~ChildNode(void) {
}

void ChildNode::setParent(ParentNode* parent) {
  if(! parent->isChild(this)) {
    parent->addChild(this);
  }

  _parent = parent;
}

ParentNode* ChildNode::parent(void) {
  return _parent;
}
