#include <cstdlib>
#include <iostream>
#include <container/buffer.hpp>
#include <pthread.h>
#include <cstring>
#include <ctime>

bool debug = false;
bool ok = true;
Buffer<2048> buffer;

char *str;
int n;

int full_cpt = 0;
int empty_cpt = 0;

void* provider(void* arg) {
  (void) arg;
  for(int i = 0; i < n; i++) {
    bool full = false;
    while(buffer.isFull()) {
      full = true;
    }
    if(full) {
      full_cpt++;
    }
    
    buffer.enqueue(str[i]);
  }
  return NULL;
}

void* consumer(void* arg) {
  (void) arg;
  for(int i = 0; i < n; i++) {
    bool empty = false;
    while(buffer.isEmpty()) {
      empty = true;
    }
    if(empty) {
      empty_cpt++;
    }
    
    if(buffer.head() != str[i]) {
      std::cerr << "At index " << i << ", got '" << buffer.head() << "' instead of '" << str[i] << "'" << std::endl;
      ok = false;
    }
    buffer.dequeue();
  }
  return NULL;
}

int main(int argc, char** argv) {
  if(argc < 2) {
    printf("Usage: %s number [DEBUG]\n", argv[0]);
    return EXIT_FAILURE;
  }
  
  srand(time(NULL));
  
  n = strtol(argv[1], NULL, 10);
  debug = argc > 2;
  
  str = new char[n];
  for(int i = 0; i < n; i++) {
    str[i] = rand() % ('z' - 'a') + 'a';
  }
  
  pthread_t threads[2];
  
  pthread_create(threads, NULL, provider, NULL);
  pthread_create(threads + 1, NULL, consumer, NULL);
  
  pthread_join(threads[0], NULL);
  pthread_join(threads[1], NULL);
  
  delete[] str;
  
  if(debug) {
    std::cout << "Max buffer size is " << Buffer<>::MAX_SIZE << "." << std::endl;
    std::cout << "Buffer size is " << buffer.usedSpace() << "." << std::endl;
    std::cout << "Buffer has been full " << full_cpt << " times." << std::endl;
    std::cout << "Buffer has been empty " << empty_cpt << " times." << std::endl;
  }
  
  if(ok) {
    std::cout << "OK" << std::endl;
    return EXIT_SUCCESS;
  }
  else {
    std::cout << "NOK" << std::endl;
    return EXIT_FAILURE;
  }
}
