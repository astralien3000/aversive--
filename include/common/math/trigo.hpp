#ifndef TRIGO_HPP
#define TRIGO_HPP

#include <math.h>

namespace Math {
  
  enum AngleUnit {
    RADIAN,
    DEGREE
  };

  static const double PI = 3.14159265358979323846264338327;

  ////////////////////////////////////////
  // atan2

  template<typename T, AngleUnit U = RADIAN>
    struct Atan2Operator {
      static inline T op(T, T);
    };
    
  template<typename T>
    struct Atan2Operator<T, RADIAN> {
      static inline T op(T val1, T val2) {
	return (T)::atan2((double)val1, (double)val2);
      }
    };

  template<typename T>
    struct Atan2Operator<T, DEGREE> {
      static inline T op(T val1, T val2) {
	return (T)(::atan2((double)val1, (double)val2) / PI * 180.);
      }
    };

  template<AngleUnit U = RADIAN, typename T>
  T atan2(T val1, T val2) {
    return Atan2Operator<T, U>::op(val1, val2);
  }
  
  ////////////////////////////////////////
  // cos

  template<typename T, AngleUnit U = RADIAN>
    struct CosOperator {
      static inline T op(T);
    };
    
  template<typename T>
    struct CosOperator<T, RADIAN> {
      static inline T op(T val) {
	return (T)::cos((double)val);
      }
    };

  template<typename T>
    struct CosOperator<T, DEGREE> {
      static inline T op(T val) {
	return (T)(::cos((double)val / 180. * PI));
      }
    };

  template<AngleUnit U = RADIAN, typename T>
  T cos(T val) {
    return CosOperator<T, U>::op(val);
  }

  ////////////////////////////////////////
  // sin

  template<typename T, AngleUnit U = RADIAN>
    struct SinOperator {
      static inline T op(T);
    };
    
  template<typename T>
    struct SinOperator<T, RADIAN> {
      static inline T op(T val) {
	return (T)::sin((double)val);
      }
    };

  template<typename T>
    struct SinOperator<T, DEGREE> {
      static inline T op(T val) {
	return (T)(::sin((double)val / 180. * PI));
      }
    };

  template<AngleUnit U = RADIAN, typename T>
  T sin(T val) {
    return SinOperator<T, U>::op(val);
  }


}

#endif//TRIGO_HPP
