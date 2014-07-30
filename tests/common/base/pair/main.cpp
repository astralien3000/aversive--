#include <base/pair.hpp>
#include <iostream>
#include "../../../my_assert.hpp"

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  myAssert(!(sizeof(Pair<bool, bool>) >= sizeof(Pair<u8, u8>)),
           "Line " S__LINE__ ": A boolean Pair is not lighter than a byte Pair even though it should have a bool specialisation.");
  
  Pair<bool, bool>
    p1(false, false),
    p2(false, true),
    p3(true, false),
    p4(true, true);
  
  myAssert(p1.left() == false && p1.right() == false, "Line " S__LINE__ ": Pair<bool, bool> construction.");
  myAssert(p2.left() == false && p2.right() == true,  "Line " S__LINE__ ": Pair<bool, bool> construction.");
  myAssert(p3.left() == true  && p3.right() == false, "Line " S__LINE__ ": Pair<bool, bool> construction.");
  myAssert(p4.left() == true  && p4.right() == true,  "Line " S__LINE__ ": Pair<bool, bool> construction.");
  
  p1.left() = true;
  myAssert(p1.left() == true && p1.right() == false, "Line " S__LINE__ ": Pair<bool, bool> left reference.");
  
  p1.right() = true;
  myAssert(p1.left() == true && p1.right() == true, "Line " S__LINE__ ": Pair<bool, bool> right reference.");
  
  p1.left() = false;
  myAssert(p1.left() == false && p1.right() == true, "Line " S__LINE__ ": Pair<bool, bool> left reference.");
  
  p1.right() = false;
  myAssert(p1.left() == false && p1.right() == false, "Line " S__LINE__ ": Pair<bool, bool> right reference.");
  
  std::cout << "OK" << std::endl;  
  return 0;
}
