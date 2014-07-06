#include <base/bool_ref.hpp>
#include <iostream>

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  bool b1 = true;
  BoolRef r1(b1);
  
  if(!r1) {
    std::cout << "NOK" << std::endl;
    return 1;
  }
  
  r1 = false;
  
  if(r1 || b1) {
    std::cout << "NOK" << std::endl;
    return 1;
  }
  
  BoolRef r2(r1);
  
  if(r2 || r1 || b1) {
    std::cout << "NOK" << std::endl;
    return 1;
  }
  
  r2 = true;
  
  if(!(r2 && r1 && b1)) {
    std::cout << "NOK" << std::endl;
    return 1;
  }
  
  u8 b2 = 0xF0;
  
  for(int i = 0; i < 4; i++) {
    BoolRef r(&b2, i);
    if(r) {
      std::cout << "NOK" << std::endl;
      return 1;
    }
    r = !r;
  }
  
  for(int i = 4; i < 8; i++) {
    BoolRef r(&b2, i);
    if(!r) {
      std::cout << "NOK" << std::endl;
      return 1;
    }
    r = !r;
  }
  
  if(b2 != 0x0F) {
    std::cout << "NOK" << std::endl;
    return 1;
  }
  
  std::cout << "OK" << std::endl;  
  return 0;
}
