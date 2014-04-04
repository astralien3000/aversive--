#include <stdlib.h>

inline void* operator new(size_t s) {
  return malloc(s);
}

inline void operator delete(void* p) {
  free(p);
}
