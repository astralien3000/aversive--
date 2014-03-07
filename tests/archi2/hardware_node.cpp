#include "hardware_node.hpp"

HardwareNode::HardwareNode(Identifier identifier)
  : StructNode(identifier)
{
}

HardwareNode::HardwareNode(std::string identifier)
  : StructNode(identifier)
{
}

HardwareNode::HardwareNode(std::pair<std::string, int> identifier)
  : StructNode(identifier)
{
}

HardwareNode::~HardwareNode(void) {
}
