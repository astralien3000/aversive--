#include <base/array.hpp>
#include <iostream>

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Array<5, u8> a1(42);
  for(array_t i = 0; i < a1.SIZE; i++) {
    if(a1[i] != 42) {
      std::cout << "NOK" << std::endl;
      return 1;
    }
  }
  
  Array<5, u8> a2(1, 2, 42);
  if(a2[0] != 1 || a2[1] != 2) {
    std::cout << "NOK" << std::endl;
    return 1;
  }
  
  for(array_t i = 2; i < a2.SIZE; i++) {
    if(a2[i] != 42) {
      std::cout << "NOK" << std::endl;
      return 1;
    }
  }
  
  std::cout << "OK" << std::endl;
  return 0;
}
