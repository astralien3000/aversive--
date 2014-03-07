#ifndef CONFIG_NODE_HPP
#define CONFIG_NODE_HPP

#include "sub_register_nod.hpp"

#include <list>

class ConfigNode : public SubRegisterNode {
public:
  ConfigNode(Identifier&);

  ~ConfigNode(void);

  void setParent(ParentNode*);

  std::list<std::string>& confs(void);

  void defineValue(indented_stream&);
private:
  std::list<std::string> _confs;
};

#endif//CONFIG_NODE_HPP
