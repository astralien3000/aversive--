#ifndef COMPOSED_FILTER_HPP
#define COMPOSED_FILTER_HPP

#include "../base/integer.hpp"
#include "filter.hpp"

template<class Filter1, class Filter2>
class ComposedFilter : public Filter<typename Filter1::InputType> {
public:
  typedef typename Filter1::InputType InputType;
  typedef typename Filter2::OutputType OutputType;
  
private:
  Filter1& _f1;
  Filter2& _f2;

public:
  inline ComposedFilter(Filter1& f1, Filter2& f2) : _f1(f1), _f2(f2) {}
  
  OutputType doFilter(InputType in) {
    return _f2.doFilter(_f1.doFilter(in));
  }
};

#endif//COMPOSED_FILTER_HPP
