#ifndef SUB_REGISTER_NODE_HPP
#define SUB_REGISTER_NODE_HPP

#include "struct_node.hpp"

class SubRegisterNode : public StructNode {
public:
  SubRegisterNode(Identifier);

  virtual int getRegSize(void);
};

#endif//SUB_REGISTER_NODE_HPP
