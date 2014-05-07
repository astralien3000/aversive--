#include <iostream>

#include "uc_node.hpp"
#include "hardware_node.hpp"
#include "struct_node.hpp"
#include "register_node.hpp"

int main(int argc, char* argv[]) {
  ParentNode* n = new UcNode("test");
  StructNode* h1 = new HardwareNode(std::make_pair(std::string("hard"), 1));
  StructNode* h2 = new HardwareNode(std::make_pair(std::string("hard"), 2));
  StructNode* h3 = new HardwareNode("hardd");
  StructNode* s1 = new StructNode(std::make_pair(std::string("test"), 22));
  StructNode* s2 = new StructNode(std::make_pair(std::string("tt"), 22));
  StructNode* s4 = new StructNode(std::make_pair(std::string("tt"), 21));
  StructNode* s3 = new StructNode(std::string("list1"));

  RegisterNode* r1 = new RegisterNode("reg1", 8);
  {
    std::list<std::string> regs;
    regs.push_back("REG1");
    regs.push_back("REG2");
    r1->setRegs(regs);
  }

  RegisterNode* r2 = new RegisterNode("reg2", 16);
  {
    std::list<std::string> regs;
    regs.push_back("REG3");
    regs.push_back("REG4");
    r2->setRegs(regs);
  }

  RegisterNode* r3 = new RegisterNode("reg3", 16);
  {
    std::list<std::string> regs;
    regs.push_back("REG5");
    regs.push_back("REG6");
    r3->setRegs(regs);
  }

  h1->setParent(n);
  h2->setParent(n);
  h3->setParent(n);

  s1->setParent(h1);
  s2->setParent(s1);
  s4->setParent(s1);

  r1->setParent(s1);
  r2->setParent(s1);
  r3->setParent(s2);

  s3->setParent(r3);

  indented_stream out(std::cout);

  n->declare(out);
  n->define(out);
  n->defineValue(out);
  return 0;
}
