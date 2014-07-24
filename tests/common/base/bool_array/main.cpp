#include <base/array.hpp>
#include <iostream>

static const array_t SIZE = 5;

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  if(sizeof(Array<SIZE, bool>) >= sizeof(Array<SIZE, u8>)) {
    std::cout << "NOK" << std::endl;
    return 1;
  }
  
  Array<SIZE, bool> a1(true, true, false, true, false);
  
  if(a1[0] != true || a1[1] != true || a1[2] != false || a1[3] != true || a1[4] != false) {
    std::cout << "NOK" << std::endl;
    return 1;
  }
  
  a1 = false;
  for(u8 i = 0; i < SIZE; i++) {
    if(a1[i] != false) {
      std::cout << "NOK" << std::endl;
      return 1;
    }
  }
  
  a1 += true;
  for(u8 i = 0; i < SIZE; i++) {
    if(a1[i] != (bool) (false + true)) {
      std::cout << "NOK" << std::endl;
      return 1;
    }
  }
  
  a1 = true;
  a1 -= false;
  for(u8 i = 0; i < SIZE; i++) {
    if(a1[i] != (bool) (true - false)) {
      std::cout << "NOK" << std::endl;
      return 1;
    }
  }
  
  a1 = false;
  a1 /= true;
  for(u8 i = 0; i < SIZE; i++) {
    if(a1[i] != (bool) (false / true)) {
      std::cout << "NOK" << std::endl;
      return 1;
    }
  }

  a1 = true;
  a1 *= false;
  for(u8 i = 0; i < SIZE; i++) {
    if(a1[i] != (bool) (true * false)) {
      std::cout << "NOK" << std::endl;
      return 1;
    }
  }
  
  a1 = true;
  a1 %= true;
  for(u8 i = 0; i < SIZE; i++) {
    if(a1[i] != (bool) (true % true)) {
      std::cout << "NOK" << std::endl;
      return 1;
    }
  }
  
  Array<SIZE, bool> a2;
  a1 = true;
  a2 = false;
  a2 = a1 + a2;
  for(u8 i = 0; i < SIZE; i++) {
    if(a2[i] != (bool) (true + false)) {
      std::cout << "NOK" << std::endl;
      return 1;
    }
  }
  
  a2 = a1 - false;
  for(u8 i = 0; i < SIZE; i++) {
    if(a2[i] != (bool) (true - false)) {
      std::cout << "NOK" << std::endl;
      return 1;
    }
  }
  
  a2 = a1 * false;
  for(u8 i = 0; i < SIZE; i++) {
    if(a2[i] != (bool) (true * false)) {
      std::cout << "NOK" << std::endl;
      return 1;
    }
  }
  
  a2 = a1 / true;
  for(u8 i = 0; i < SIZE; i++) {
    if(a2[i] != (bool) (true / true)) {
      std::cout << "NOK" << std::endl;
      return 1;
    }
  }
  
  a2 = a1 % true;
  for(u8 i = 0; i < SIZE; i++) {
    if(a2[i] != (bool) (true % true)) {
      std::cout << "NOK" << std::endl;
      return 1;
    }
  }
  
  std::cout << "OK" << std::endl;  
  return 0;
}
