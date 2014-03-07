#include "uc_node.hpp"

#include "child_node.hpp"

UcNode::UcNode(std::string name) : _name(name) {
}

UcNode::~UcNode(void) {
}

std::string UcNode::name(void) {
  return _name;
}

std::string UcNode::fullName(void) {
  return std::string("");
}

void UcNode::declare(indented_stream& out) {
  out << "// Architecture : " << _name << std::endl;
}

void UcNode::define(indented_stream& out) {
  for(auto it = _children.begin() ; it != _children.end() ; it++) {
    (*it)->declare(out);
  }

  for(auto it = _children.begin() ; it != _children.end() ; it++) {
    (*it)->define(out);
  }
}

void UcNode::defineValue(indented_stream& out) {
  for(auto it = _children.begin() ; it != _children.end() ; it++) {
    (*it)->defineValue(out);
  }
}
