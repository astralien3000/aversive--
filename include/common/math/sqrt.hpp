#ifndef SQRT_HPP
#define SQRT_HPP

#include <math.h>

namespace Math {

  //! \brief Square root
  template<typename T>
  T sqrt(T val) {
    return (T)::sqrt((double)val);
  }

}

#endif//SQRT_HPP
