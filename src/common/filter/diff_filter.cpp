#include <filter/diff_filter.hpp>

DiffFilter::DiffFilter(void) : _first_call(true), _last_in(0), _delta(1), _last_out(0) {}
  
void DiffFilter::setDelta(CoeffType d) {
  _delta = d;
}

typename DiffFilter::CoeffType DiffFilter::getDelta(void) {
  return _delta;
}

typename DiffFilter::OutputType DiffFilter::doFilter(typename DiffFilter::InputType in) {
  if(!_first_call) {
    _last_out = (in - _last_in) / _delta;
  }
  else {
    _first_call = false;
    _last_out = 0;
  }

  _last_in = in;
  return _last_out;
}
