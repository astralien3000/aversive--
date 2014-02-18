#include <filter/pid_filter.hpp>
#include <math/saturate.hpp>

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
  
  _out_shift = 0;
}

void PidFilter::setGains(CoeffType p, CoeffType i, CoeffType d) {
  _gain_p = p;
  _gain_i = i;
  _gain_d = d;
}

void PidFilter::setMaxIntegral(OutputType val) {
  _max_i = val;
}

void PidFilter::setOutShift(CoeffType shift) {
  _out_shift = shift;
}

typename PidFilter::CoeffType PidFilter::getGainP(void) {
  return _gain_p;
}

typename PidFilter::CoeffType PidFilter::getGainI(void) {
  return _gain_i;
}

typename PidFilter::CoeffType PidFilter::getGainD(void) {
  return _gain_d;
}

typename PidFilter::OutputType PidFilter::getMaxIntegral(void) {
  return _max_i;
}

typename PidFilter::CoeffType PidFilter::getOutShift(void) {
  return _out_shift;
}

typename PidFilter::OutputType PidFilter::doFilter(InputType in) {
  OutputType p = in * _gain_p;
 
  _sum_in = Math::saturate(_sum_in + in, -_max_i, _max_i);
  OutputType i = _sum_in * _gain_i;

  OutputType d = (_last_in - in) * _gain_d;

  _last_in = in;
  
  OutputType out = (p + i + d);
  if(out < 0) {
    out = -((-out) >> _out_shift);
  }
  else {
    out = out >> _out_shift;
  }

  return _last_out = out;
}

typename PidFilter::OutputType PidFilter::lastOut(void) {
  return _last_out;
}

PidFilter PidFilter::identity(void) {
  static PidFilter id(1,0,0);
  return id;
}
