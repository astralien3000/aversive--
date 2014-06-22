#include <math/random.hpp>
#include <time.h>
#include <iostream>

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Vect<2, u64> s;
  s[0] = time(0);
  s[1] = 0;
  Random::seed(s);
  
  for(int i = 0; i < 25; i++) {
    std::cout << (s32) Random::next() << std::endl;
  }
  
  return EXIT_SUCCESS;
}
