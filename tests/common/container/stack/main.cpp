#include <container/stack.hpp>
#include <iostream>
#include <cassert>

static const stack_t SIZE = 10;

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Stack<SIZE, u8> s(10,5,8,20);
  
  assert(s.head() == 20);
  assert(s.usedSpace() == 4);
  assert(s.freeSpace() == (SIZE) - s.usedSpace());
  assert(s.push(12));
  assert(s.usedSpace() == 5);
  assert(s.push(2));
  assert(s.head() == 2);
  assert(s.pop());
  assert(s.head() == 12);
  assert(!s.isFull());
  assert(!s.isEmpty());
  
  s.flush();
  
  assert(s.usedSpace() == 0);
  for(stack_t i = 0; i < 5; i++) {
    assert(s.push(10+i));
  }
  
  assert(s.usedSpace() == 5);
  for(int i = 4; i >= 0; i--) {
    assert(s.head() == (10+i));
    assert(s.pop());
    assert(s.usedSpace() == (stack_t) i);
  }
  
  std::cout << "OK" << std::endl;
  return 0;
}
