#ifndef HARDWARE_NODE_HPP
#define HARDWARE_NODE_HPP

#include "struct_node.hpp"

class HardwareNode : public StructNode {
public:
  HardwareNode(Identifier);
  HardwareNode(std::string);
  HardwareNode(std::pair<std::string, int>);

  ~HardwareNode(void);
};

#endif//HARDWARE_NODE_HPP
