#ifndef COMPOSED_FILTER_HPP
#define COMPOSED_FILTER_HPP

#include "../base/integer.hpp"
#include <filter/filter.hpp>

class ComposedFilter : public Filter<s32> {
public:
  typedef s32 InputType;
  typedef s32 OutputType;
  
private:
  Filter& _f1;
  Filter& _f2;

public:
  inline ComposedFilter(Filter& f1, Filter& f2) : _f1(f1), _f2(f2) {}
  
  OutputType doFilter(InputType in) {
    return _f2.doFilter(_f1.doFilter(in));
  }
};

#endif//COMPOSED_FILTER_HPP
