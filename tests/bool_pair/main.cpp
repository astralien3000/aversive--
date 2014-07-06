#include <base/pair.hpp>
#include <iostream>

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  if(sizeof(Pair<bool, bool>) >= sizeof(Pair<u8, u8>)) {
    std::cout << "NOK" << std::endl;
    return 1;
  }
  
  Pair<bool, bool>
    p1(false, false),
    p2(false, true),
    p3(true, false),
    p4(true, true);
  
  if(p1.left() != false || p1.right() != false) {
    std::cout << "NOK" << std::endl;
    return 1;
  }
  
  if(p2.left() != false || p2.right() != true) {
    std::cout << "NOK" << std::endl;
    return 1;
  }
  
  if(p3.left() != true || p3.right() != false) {
    std::cout << "NOK" << std::endl;
    return 1;
  }
  
  if(p4.left() != true || p4.right() != true) {
    std::cout << "NOK" << std::endl;
    return 1;
  }
  
  p1.left() = true;
  
  if(p1.left() != true || p1.right() != false) {
    std::cout << "NOK" << std::endl;
    return 1;
  }
  
  p1.right() = true;
  
  if(p1.left() != true || p1.right() != true) {
    std::cout << "NOK" << std::endl;
    return 1;
  }
  
  p1.left() = false;
  
  if(p1.left() != false || p1.right() != true) {
    std::cout << "NOK" << std::endl;
    return 1;
  }
  
  p1.right() = false;
  
  if(p1.left() != false || p1.right() != false) {
    std::cout << "NOK" << std::endl;
    return 1;
  }
  
  std::cout << "OK" << std::endl;  
  return 0;
}
