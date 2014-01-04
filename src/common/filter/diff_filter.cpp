#include <filter/diff_filter.hpp>


DiffFilter::DiffFilter(void) : _first_call(true), _last_in(0), _delta(1) {
  
}
  
void DiffFilter::setDelta(CoeffType d) {
  _delta = d;
}

typename DiffFilter::OutputType DiffFilter::doFilter(InputType in) {
  if(!_first_call) {
    OutputType ret = (in - _last_in) / _delta;
    _last_in = in;
    return ret;
  }
  else {
    _first_call = false;
    _last_in = in;
    return 0;
  }
}
