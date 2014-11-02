#include <aversive.hpp>
#include <base/alloc.hpp>
#include <base/integer.hpp>
#include <device/stream/uart_stream.hpp>

static constexpr u8 VALUE = 15;

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Aversive::init();
  
  UartStream<0> io("io");
  while(io.getValue() != 'S') {
    // We first wait for the tester to tell the board to start
  }
  
  u8* ptr;
  
  ptr = (u8*) Alloc::malloc(sizeof(u8));
  // We need to implement an assert like function on AVR which the prototype would be like:
  // myAssert(Stream& io, bool test, const char* msg);
  //myAssert(ptr != 0, "Line " S__LINE__ ": Alloc::malloc");
  
  Alloc::free(ptr);
  
  ptr = (u8*) Alloc::calloc(1, sizeof(u8));
  //myAssert(ptr != 0 && *ptr == 0, "Line " S__LINE__ ": Alloc::calloc");
  
  *ptr = VALUE;
  ptr = (u8*) Alloc::realloc(ptr, 2 * sizeof(u8));
  //myAssert(ptr != 0 && *ptr == VALUE, "Line " S__LINE__ ": Alloc::realloc");
  
  Alloc::free(ptr);
  
  ptr = new u8(VALUE);
  //myAssert(ptr != 0 && *ptr == VALUE, "Line " S__LINE__ ": Alloc new operator");
  
  delete ptr;
  
  ptr = new u8[VALUE];
  //myAssert(ptr != 0, "Line " S__LINE__ ": Alloc new[] operator");
  
  delete[] ptr;
  
  io << "OK\n";
  
  while(Aversive::sync()) {
  }
  
  return Aversive::exit();
}
