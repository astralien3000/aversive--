#include <aversive.hpp>
#include <device/eirbot2014/gp2.hpp>

#include <iostream>

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Aversive::init();
  GP2<0> in("in");
  
  std::cout << "in value " << in.getValue() << std::endl;
  Aversive::sync();
  std::cout << "in value " << in.getValue() << std::endl;
  
  Aversive::setReturnCode(0);
  return Aversive::exit();
}
