#ifndef SATURATE_HPP
#define SATURATE_HPP

namespace Math {

  //! \brief Ensures that an integer is contained into an interval (template version)
  template<int min, int max, typename T>
  inline const T saturate(T val) {
    if(val > (T)max) return max;
    else if(val < (T)min) return min;
    return val;
  }

  //! \brief Ensures that an integer is contained into an interval
  template<typename T>
  inline const T saturate(T val, T min, T max) {
    if(val > (T)max) return max;
    else if(val < (T)min) return min;
    return val;
  }

  //! \brief Useful for circula buffers
  template<int min, int max, typename T>
  inline const T mod(T val) {
    return min + ((val - min) % (max - min));
  }

  //! \brief Test if value is contained into an interval
  template<int min, int max, typename T>
  inline bool belong(T val) {
    return !(val < (T)min || (T)max < val);
  }

  //! \brief The absolute value
  template<typename T>
  inline const T abs(T val) {
    return ((val < (T)0) ? -val : val);
  }

  //! \brief The maximum of two values
  template<typename T>
  inline T& max(T& v1, T& v2) {
    return ((v1 > v2) ? v1 : v2);
  }

  //! \brief The minimum of two values
  template<typename T>
  inline T& min(T& v1, T& v2) {
    return ((v1 < v2) ? v1 : v2);
  }

}

#endif//SATURATE_HPP
