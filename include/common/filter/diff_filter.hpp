#ifndef DIFF_FILTER_HPP
#define DIFF_FILTER_HPP

#include "../base/integer.hpp"

//! \brief Differential Filter
/*!  

  Basically returns the difference between the current and the
  previous input.

 */
class DiffFilter {
public:
  typedef s32 InputType;
  typedef s32 OutputType;
  typedef s32 CoeffType;

private:
  bool _first_call;
  InputType _last_in;
  CoeffType _delta;
  
public:
  //! \brief Default Constructor
  DiffFilter(void) : _first_call(true), _last_in(0), _delta(1) {}
  
  void setDelta(CoeffType d) {
    _delta = d;
  }

  OutputType doFilter(InputType in) {
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

};

#endif//DIFF_FILTER_HPP
