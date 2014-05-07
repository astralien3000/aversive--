#ifndef UC_NODE_HPP
#define UC_NODE_HPP

#include "parent_node.hpp"

#include <string>

class UcNode : public ParentNode {
public:
  UcNode(std::string);
  ~UcNode(void);

  std::string name(void);
  std::string fullName(void);

  void declare(indented_stream&);
  void define(indented_stream&);
  void defineValue(indented_stream&);

private:
  std::string _name;
};

#endif//UC_NODE_HPP
