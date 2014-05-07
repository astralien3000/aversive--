#include "register_node.hpp"

static std::map<int, int> _reg_by_size;

RegisterNode::RegisterNode(Identifier& identifier, int size)
  : SubRegisterNode(identifier)
{
  _values["SIZE"] = size;
  _values["REG"] = _reg_by_size[_values["SIZE"]]++;
}

RegisterNode::~RegisterNode(void) {
}

std::list<std::string>& RegisterNode::regs(void) {
  return _regs;
}

int RegisterNode::getRegSize(void) {
  return _values["SIZE"];
}

void RegisterNode::defineValue(indented_stream& out) {
  out << "template<> inline Register<" << _values["SIZE"] << ", " << _values["REG"] << ">";
  out << "::Register(void) : reg_size(" << _regs.size() << "), ";
  out << "reg{";
  
  for(auto it = _regs.begin() ; it != _regs.end() ; ++it) {
    if(it != _regs.begin()) {
      out << ", ";
    }
    out << "(u" << _values["SIZE"] << "*)&" << *it;
  }
  
  out << "} ";
  out << "{}" << std::endl;

  StructNode::defineValue(out);
}
