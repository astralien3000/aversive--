#include <config.hpp>
#include <iostream>
#include "../../my_assert.hpp"

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  myAssert(Aversive::Config::dummy() == 42, "Line " S__LINE__ ": The dummy parameter does not hold the right value.");
  
  std::cout << "OK" << std::endl;
  return 0;
}
