#ifndef STRUCT_NODE_HPP
#define STRUCT_NODE_HPP

#include "parent_node.hpp"
#include "child_node.hpp"

#include "identifier.hpp"

#include <map>

class StructNode : public ParentNode, public ChildNode {
public:
  StructNode(Identifier);
  StructNode(std::string);
  StructNode(int);
  StructNode(std::pair<std::string, int>);
  ~StructNode(void);

  virtual std::string name(void);
  virtual std::string fullName(void);

  virtual void declare(indented_stream&);
  virtual void define(indented_stream&);
  virtual void defineValue(indented_stream&);

private:
  Identifier _id;

protected:
  std::map<std::string, int> _values;
};

#endif//STRUCT_NODE_HPP
