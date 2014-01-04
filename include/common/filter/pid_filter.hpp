#ifndef PID_FILTER_HPP
#define PID_FILTER_HPP

#include "../base/integer.hpp"

//! \brief PID Filter
/*!
  \todo
 */
template<typename IT = s32, typename OT = s32, typename CT = s32>
class PidFilter {
public:
  typedef IT InputType;
  typedef OT OutputType;
  typedef CT CoeffType;

private:
  InputType _last_in;
  InputType _sum_in;

  CoeffType _gain_p;
  CoeffType _gain_i;
  CoeffType _gain_d;

  OutputType _max_i;

public:
  //! \brief Constructor with initialisation of all gains
  PidFilter(CoeffType p = 0, CoeffType i = 0, CoeffType d = 0) {
    _last_in = 0;
    _sum_in = 0;
    
    _gain_p = p;
    _gain_i = i;
    _gain_d = d;
    
    _max_i = 0;
  }
  
  void setGains(CoeffType p, CoeffType i, CoeffType d) {
    _gain_p = p;
    _gain_i = i;
    _gain_d = d;
  }

  //! \brief Sets the limit for integral output
  void setMaxIntegral(OutputType val) {
    _max_i = val;
  }


  template<typename T>
  inline static T __min(T v1, T v2) {
    if(v1 < v2) return v1;
    else return v2;
  }

  template<typename T>
  inline static T __max(T v1, T v2) {
    if(v1 > v2) return v1;
    else return v2;
  }

  OutputType doFilter(InputType in) {
    // proportional
    OutputType p = in * _gain_p;

    // integral
    if(0 < _sum_in + in) {
      _sum_in = __min(_max_i, _sum_in + in);
    }
    else {
      _sum_in = __max(-_max_i, _sum_in + in);
    }
    OutputType i = _sum_in * _gain_i;

    // derivate
    OutputType d = (_last_in - in) * _gain_d;

    // out
    _last_in = in;
    return p + i + d;
  }
};

#endif//PID_FILTER_HPP
