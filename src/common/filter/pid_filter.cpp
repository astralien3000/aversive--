#include <filter/pid_filter.hpp>


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

PidFilter::PidFilter(CoeffType p, CoeffType i, CoeffType d) {
  _last_in = 0;
  _sum_in = 0;

  _gain_p = p;
  _gain_i = i;
  _gain_d = d;

  _max_i = 0;
}

void PidFilter::setGains(CoeffType p, CoeffType i, CoeffType d) {
  _gain_p = p;
  _gain_i = i;
  _gain_d = d;
}

void PidFilter::setMaxIntegral(OutputType val) {
  _max_i = val;
}

typename PidFilter::OutputType PidFilter::doFilter(InputType in) {
  OutputType p = in * _gain_p;
 
  _sum_in = __min(_max_i, _sum_in + in);
  OutputType i = _sum_in * _gain_i;

  OutputType d = (_last_in - in) * _gain_d;

  _last_in = in;
  return p + i + d;
}
  

