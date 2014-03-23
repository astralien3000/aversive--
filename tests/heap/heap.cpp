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
  
  Heap<HEAP_SIZE, s8> h(0, 1, 2, 3, 4, 5, 6, 7);
  
  assert(h.isFull());
  assert(!h.isEmpty());
  assert(h.usedSpace() == HEAP_SIZE);
  assert(h.freeSpace() == 0);
  
  for(s16 i = 7; i >= 0; i--) {
    assert(h.max() == i);
    assert(h.pop());
    assert(h.freeSpace() == (HEAP_SIZE - (heap_t) i));
    assert(h.usedSpace() == (heap_t) i);
  }
  
  h.flush();
  
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
  assert(h.freeSpace() == (HEAP_SIZE - DATA_SIZE + 1));
  
  assert(h.max() == 13);
  h.pop();
  
  assert(h.max() == 12);
  h.pop();
  
  assert(h.max() == 10);
  h.pop();
  
  assert(h.isEmpty());
  assert(h.freeSpace() == HEAP_SIZE);
  assert(h.usedSpace() == 0);
  
  for(heap_t i = 0; i < HEAP_SIZE; i++) {
    assert(h.insert(i));
    assert(h.usedSpace() == (i+1));
    assert(h.freeSpace() == (HEAP_SIZE - i - 1));
  }
  
  assert(h.isFull());
  assert(!h.isEmpty());
  
  assert(!h.insert(8));
  
  for(s16 i = 7; i >= 0; i--) {
    assert(h.max() == i);
    assert(h.pop());
    assert(h.freeSpace() == (HEAP_SIZE - (heap_t) i));
    assert(h.usedSpace() == (heap_t) i);
  }
  
  assert(!h.pop());
  
  std::cout << "OK" << std::endl;
  return 0;
}
