#include <base/array.hpp>
#include <iostream>
#include "../../../my_assert.hpp"

static const array_t SIZE = 5;

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Array<SIZE, u8> a1(42);
  for(array_t i = 0; i < a1.SIZE; i++) {
    myAssert(a1[i] == 42, "Line " S__LINE__ ": Variadic Array construction.");
  }
  
  Array<SIZE, u8> a2(1, 2, 42);
  myAssert(a2[0] == 1 && a2[1] == 2, "Line " S__LINE__ ": Variadic Array construction.");
  
  for(array_t i = 2; i < a2.SIZE; i++) {
    myAssert(a2[i] == 42, "Line " S__LINE__ ": Variadic Array construction.");
  }
  
  myAssert(!(sizeof(Array<SIZE, bool>) >= sizeof(Array<SIZE, u8>)),
           "Line " S__LINE__ ": A boolean Array is not lighter than a byte Array even though it should have a bool specialisation.");
  
  Array<SIZE, bool> a3(true, true, false, true, false);
  
  myAssert(!(a3[0] != true || a3[1] != true || a3[2] != false || a3[3] != true || a3[4] != false),
           "Line " S__LINE__ ": Boolean Array construction then element access.");
  
  a3 = false;
  for(u8 i = 0; i < SIZE; i++) {
    myAssert(a3[i] == false, "Line " S__LINE__ ": Boolean Array value assignment.");
  }
  
  a3 += true;
  for(u8 i = 0; i < SIZE; i++) {
    myAssert(a3[i] == (bool) (false + true), "Line " S__LINE__ ": Array<SIZE, bool>::operator+=(bool).");
  }
  
  a3 = true;
  a3 -= false;
  for(u8 i = 0; i < SIZE; i++) {
    myAssert(a3[i] == (bool) (true - false), "Line " S__LINE__ ": Array<SIZE, bool>::operator-=(bool).");
  }
  
  a3 = false;
  a3 /= true;
  for(u8 i = 0; i < SIZE; i++) {
    myAssert(a3[i] == (bool) (false / true), "Line " S__LINE__ ": Array<SIZE, bool>::operator/=(bool).");
  }

  a3 = true;
  a3 *= false;
  for(u8 i = 0; i < SIZE; i++) {
    myAssert(a3[i] == (bool) (true * false), "Line " S__LINE__ ": Array<SIZE, bool>::operator*=(bool).");
  }
  
  a3 = true;
  a3 %= true;
  for(u8 i = 0; i < SIZE; i++) {
    myAssert(a3[i] == (bool) (true % true), "Line " S__LINE__ ": Array<SIZE, bool>::operator%=(bool).");
  }
  
  Array<SIZE, bool> a4;
  a3 = true;
  a4 = false;
  a4 = a3 + a4;
  for(u8 i = 0; i < SIZE; i++) {
    myAssert(a4[i] == (bool) (true + false), "Line " S__LINE__ ": Array<SIZE, bool>::operator+(Array).");
  }
  
  a4 = a3 - false;
  for(u8 i = 0; i < SIZE; i++) {
    myAssert(a4[i] == (bool) (true - false), "Line " S__LINE__ ": Array<SIZE, bool>::operator-(Array).");
  }
  
  a4 = a3 * false;
  for(u8 i = 0; i < SIZE; i++) {
    myAssert(a4[i] == (bool) (true * false), "Line " S__LINE__ ": Array<SIZE, bool>::operator*(Array).");
  }
  
  a4 = a3 / true;
  for(u8 i = 0; i < SIZE; i++) {
    myAssert(a4[i] == (bool) (true / true), "Line " S__LINE__ ": Array<SIZE, bool>::operator/(Array).");
  }
  
  a4 = a3 % true;
  for(u8 i = 0; i < SIZE; i++) {
    myAssert(a4[i] == (bool) (true % true), "Line " S__LINE__ ": Array<SIZE, bool>::operator%(Array).");
  }
  
  std::cout << "OK" << std::endl;  
  return 0;
}
