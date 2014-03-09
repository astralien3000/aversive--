#include <container/list.hpp>
#include <iostream>
#include <cassert>

static const list_t SIZE = 10;

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  List<SIZE, u8> l(10,5,8,20);
  
  assert(l.get(0) == 10);
  assert(l.get(1) == 5);
  assert(l.get(3) == 20);
  assert(l.usedSpace() == 4);
  assert(l.freeSpace() == (SIZE) - l.usedSpace());
  assert(l.append(12));
  assert(l.get(4) == 12);
  assert(l.usedSpace() == 5);
  assert(l.prepend(2));
  assert(l.get(0) == 2);
  assert(l.get(5) == 12);
  assert(!l.isFull());
  assert(!l.isEmpty());
  assert(l.usedSpace() == 6);
  assert(l.indexOf(10) == 1);
  assert(l.contains(20));
  assert(!l.contains(100));
  
  std::cout << "OK" << std::endl;
  return 0;
}
