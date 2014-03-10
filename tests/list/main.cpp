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
  
  l.flush();
  
  assert(l.usedSpace() == 0);
  for(list_t i = 0; i < 5; i++) {
    assert(l.append(10));
  }
  
  assert(l.usedSpace() == 5);
  for(list_t i = 0; i < 5; i++) {
    assert(l.get(i) == 10);
  }
  
  assert(l.contains(10));
  assert(l.prepend(13));
  assert(l.indexOf(13) == 0);
  assert(l.append(16));
  assert(l.indexOf(16) == 6);
  assert(l.remove(10));
  assert(l.usedSpace() == 2);
  assert(l.indexOf(13) == 0);
  assert(l.indexOf(16) == 1);
  assert(l.removeAt(0));
  assert(l.usedSpace() == 1);
  assert(l.indexOf(16) == 0);
  
  std::cout << "OK" << std::endl;
  return 0;
}
