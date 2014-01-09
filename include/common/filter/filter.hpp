#ifndef FILTER_HPP
#define FILTER_HPP

template<typename T>
class Filter {
public:
  typedef T InputType;
  typedef T OutputType;

public:
  T doFilter(T);
};

#endif//FILTER_HPP
