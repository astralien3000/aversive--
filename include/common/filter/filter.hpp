#ifndef FILTER_HPP
#define FILTER_HPP

template<typename T>
class Filter {
public:
  typedef T InputType;
  typedef T OutputType;

public:
  virtual T doFilter(T) = 0;
};

#endif//FILTER_HPP
