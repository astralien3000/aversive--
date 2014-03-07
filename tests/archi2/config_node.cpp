#include "config_node.hpp"

static std::map<int, int> _conf_by_size;

ConfigNode::ConfigNode(Identifier& identifier)
  : SubRegisterNode(identifier)
{
}

void ConfigNode::setParent(ParentNode* p) {
  SubRegisterNode::setParent(p);
  _values["SIZE"] = getRegSize();
  _values["CONFIG"] = _conf_by_size[_values["SIZE"]]++;
}

ConfigNode::~ConfigNode(void) {
}

std::list<std::string>& ConfigNode::confs(void) {
  return _confs;
}

void ConfigNode::defineValue(indented_stream& out) {
  out << "template<> inline Config<" << _values["SIZE"] << ", " << _values["CONFIG"] << ">";
  out << "::Config(void) : ";
  out << "conf{";
  
  for(auto it = _confs.begin() ; it != _confs.end() ; ++it) {
    if(it != _confs.begin()) {
      out << ", ";
    }
    out << "(u" << _values["SIZE"] << "*)&" << *it;
  }
  
  out << "} ";
  out << "{}" << std::endl;

  StructNode::defineValue(out);
}
