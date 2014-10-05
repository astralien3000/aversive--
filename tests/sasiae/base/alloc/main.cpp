#include <base/alloc.hpp>
#include <base/integer.hpp>
#include <iostream>
#include "../../../my_assert.hpp"

static constexpr u8 VALUE = 15;

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  u8* ptr;
  
  ptr = (u8*) Alloc::malloc(sizeof(u8));
  myAssert(ptr != 0, "Line " S__LINE__ ": Alloc::malloc");
  
  Alloc::free(ptr);
  
  ptr = (u8*) Alloc::calloc(1, sizeof(u8));
  myAssert(ptr != 0 && *ptr == 0, "Line " S__LINE__ ": Alloc::calloc");
  
  *ptr = VALUE;
  ptr = (u8*) Alloc::realloc(ptr, 2 * sizeof(u8));
  myAssert(ptr != 0 && *ptr == VALUE, "Line " S__LINE__ ": Alloc::realloc");
  
  Alloc::free(ptr);
  
  ptr = new u8(VALUE);
  myAssert(ptr != 0 && *ptr == VALUE, "Line " S__LINE__ ": Alloc new operator");
  
  delete ptr;
  
  ptr = new u8[VALUE];
  myAssert(ptr != 0, "Line " S__LINE__ ": Alloc new[] operator");
  
  delete[] ptr;
  
  std::cout << "OK" << std::endl;
  return 0;
}
