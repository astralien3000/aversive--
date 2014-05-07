#include <stdlib.h>

//! \brief New operator. Allocate a memory area.
//! \param s : the size of the memory area to allocate.
//! \return A pointer to the newly allocated memory area.
inline void* operator new(size_t s) {
  return malloc(s);
}

//! \brief Delete operator.
//! \param p : the memory area address to free.
inline void operator delete(void* p) {
  free(p);
}
