#include "sub_register_nod.hpp"

SubRegisterNode::SubRegisterNode(Identifier id) : StructNode(id) {
}

int SubRegisterNode::getRegSize(void) {
  return ((SubRegisterNode*)parent())->getRegSize();
}
