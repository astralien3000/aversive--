#include <container/queue.hpp>
#include <iostream>
#include <cassert>

static const queue_t SIZE = 10;

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Queue<SIZE, u8> q(10,5,8,20);
  
  assert(q.head() == 10);
  assert(q.usedSpace() == 4);
  assert(q.freeSpace() == (SIZE) - q.usedSpace());
  assert(q.enqueue(12));
  assert(q.usedSpace() == 5);
  assert(q.enqueue(2));
  assert(q.head() == 10);
  assert(q.dequeue());
  assert(q.head() == 5);
  assert(!q.isFull());
  assert(!q.isEmpty());
  
  q.flush();
  
  assert(q.usedSpace() == 0);
  for(queue_t i = 0; i < 5; i++) {
    assert(q.enqueue(10+i));
  }
  
  assert(q.usedSpace() == 5);
  for(queue_t i = 0; i < 5; i++) {
    assert(q.head() == (10+i));
    assert(q.dequeue());
    assert(q.usedSpace() == (4-i));
  }
  
  std::cout << "OK" << std::endl;
  return 0;
}
