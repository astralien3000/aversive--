#include <math/random.hpp>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "../../../my_assert.hpp"

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Vect<2, u64> s;
  
  srand(time(NULL));
  for(int i = 0; i < 4; i++) {
    s[i/2] = (s[i/2] << 32) + rand();
  }
  
  Random::seed(s);
  
  for(int i = 0; i < 25; i++) {
    Random::next();
  }
  
  std::cout << "OK" << std::endl;
  return EXIT_SUCCESS;
}
