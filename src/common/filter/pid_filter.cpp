#include <filter/pid_filter.hpp>
/*
PidFilter::PidFilter(void) {
  PidFilter(0,0,0);
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
  /* proportional 
  OutputType p = in * _gain_p;

  /* integral 
  _sum_in = __min(_max_i, _sum_in + in);
  OutputType i = _sum_in * _gain_i;

  /* derivate 
  OutputType d = (_last_in - in) * _gain_d;

  /* out 
  _last_in = in;
  return p + i + d;
}
*/
