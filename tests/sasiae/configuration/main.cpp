#include <config.hpp>
#include <iostream>

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;

  if(Aversive::Config::dummy() == 42) {
    std::cout << "OK" << std::endl;
    return 0;
  }
  else {
    std::cout << "NOK" << std::endl;
    return 1;
  }
}
