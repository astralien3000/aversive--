#include <iostream>
#include <cassert>
#include <container/heap.hpp>
#include <base/integer.hpp>

static const heap_t DATA_SIZE = 4;
static const heap_t HEAP_SIZE = 8;
char t[] = { 13, 15, 12, 10 };

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Heap<HEAP_SIZE, s8> h;
  
  assert(h.usedSpace() == 0);
  assert(h.freeSpace() == HEAP_SIZE);
  
  for(heap_t i = 0; i < DATA_SIZE; i++) {
    h.insert(t[i]);
  }
  
  assert(h.usedSpace() == DATA_SIZE);
  assert(h.freeSpace() == (HEAP_SIZE - DATA_SIZE));
  
  assert(h.max() == 15);
  h.pop();
  
  assert(h.usedSpace() == (DATA_SIZE - 1));
  assert(h.freeSpace() == (HEAP_SIZE - DATA_SIZE - 1));
  
  assert(h.max() == 13);
  h.pop();
  
  assert(h.max() == 12);
  h.pop();
  
  assert(h.max() == 10);
  h.pop();
  
  assert(h.isEmpty());
  assert(h.freeSpace() == HEAP_SIZE);
  assert(h.usedSpace() == 0);
  
  std::cout << "OK" << std::endl;
  return 0;
}