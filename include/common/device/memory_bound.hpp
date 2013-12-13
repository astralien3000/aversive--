#ifndef MEMORY_BOUND_HPP
#define MEMORY_BOUND_HPP

#include "../base/integer.hpp"

#include "input.hpp"
#include "output.hpp"

enum Access {
  READ = 1,
  WRITE = 2
};

//! \brief Represents an object which can write and/or write on a memory space
template<typename T, T* ADDR, int ACCESS = READ | WRITE>
class MemoryBound : public Input<T>, public Output<T> {
public:
  inline MemoryBound(void);

  inline T& getValue(void);
  inline void setValue(T&);
};

#endif//MEMORY_BOUND_HPP
