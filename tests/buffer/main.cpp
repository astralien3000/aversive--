#include <container/buffer.hpp>
#include <iostream>
#include <cassert>
#include <pthread.h>
#include <sched.h>
#include <ctime>
#include <cstdlib>

static const buffer_t SIZE = 8;
Buffer<SIZE, u8>* buffer;
const u8* str;
static const int n = 1024;

void* provider(void* arg) {
  (void) arg;
  for(int i = 0; i < n; i++) {
    while(buffer->isFull()) {
      sched_yield();
    }    
    assert(buffer->enqueue(str[i]));
  }
  return NULL;
}

void* consumer(void* arg) {
  (void) arg;
  for(int i = 0; i < n; i++) {
    while(buffer->isEmpty()) {
      sched_yield();
    }
    assert(buffer->head() == str[i]);
    assert(buffer->dequeue());
  }
  return NULL;
}

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Buffer<SIZE, u8> b(10,5,8,20);
  
  assert(b.head() == 10);
  assert(b.usedSpace() == 4);
  assert(b.freeSpace() == (SIZE) - b.usedSpace());
  assert(b.enqueue(12));
  assert(b.usedSpace() == 5);
  assert(b.enqueue(2));
  assert(b.head() == 10);
  assert(b.dequeue());
  assert(b.head() == 5);
  assert(!b.isFull());
  assert(!b.isEmpty());
  
  b.flush();
  
  assert(b.usedSpace() == 0);
  for(buffer_t i = 0; i < 5; i++) {
    assert(b.enqueue(10+i));
  }
  
  assert(b.usedSpace() == 5);
  for(buffer_t i = 0; i < 5; i++) {
    assert(b.head() == (10+i));
    assert(b.dequeue());
    assert(b.usedSpace() == (4-i));
  }
  
  pthread_t threads[2];
  buffer = &b;
  u8* data = (u8*) malloc(sizeof(u8) * n);
  str = data;
  srand(time(NULL));
  for(int i = 0; i < n; i++) {
    data[i] = (u8) (rand() % 256);
  }
  
  pthread_create(threads, NULL, provider, NULL);
  pthread_create(threads + 1, NULL, consumer, NULL);
  
  pthread_join(threads[0], NULL);
  pthread_join(threads[1], NULL);
  
  assert(b.isEmpty());
  assert(b.usedSpace() == 0);
  assert(b.freeSpace() == SIZE);
  std::cout << "OK" << std::endl;
  return 0;
}
