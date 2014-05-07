#ifndef REGISTER_NODE_HPP
#define REGISTER_NODE_HPP

#include "sub_register_nod.hpp"

#include <list>

class RegisterNode : public SubRegisterNode {
public:
  RegisterNode(Identifier&, int);

  ~RegisterNode(void);

  std::list<std::string>& regs(void);

  int getRegSize(void);
  void defineValue(indented_stream&);
private:
  std::list<std::string> _regs;
};

#endif//REGISTER_NODE_HPP
