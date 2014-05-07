#include "parent_node.hpp"

#include "child_node.hpp"

ParentNode::ParentNode(void) {
}

ParentNode::~ParentNode(void) {
  for(auto it = _children.begin() ; it != _children.end() ; ++it) {
    delete *it;
    _children.erase(it);
  }
}

void ParentNode::addChild(ChildNode* nod) {
  // if no parent
  if(! nod->parent()) {
    _children.insert(nod);
  }
  else {
    // ERROR !
  }
}

bool ParentNode::isChild(ChildNode* nod) {
  for(auto it = _children.begin() ; it != _children.end() ; ++it) {
    if(nod == *it) {
      return true;
    }
  }
  return false;
}
