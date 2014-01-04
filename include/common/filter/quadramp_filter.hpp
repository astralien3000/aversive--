#ifndef QUADRAMP_FILTER_HPP
#define QUADRAMP_FILTER_HPP

#include "../base/integer.hpp"

class QuadrampFilter {
public:
  typedef s32 InputType;
  typedef s32 OutputType;
  typedef s32 CoeffType;

private:
  OutputType _prev_out;
  OutputType _prev_var;

  CoeffType _lim_1st_order_pos;
  CoeffType _lim_1st_order_neg;
  CoeffType _lim_2nd_order_pos;
  CoeffType _lim_2nd_order_neg;

public:
  QuadrampFilter(void);
  
  void setFirstOrderLimit(CoeffType,CoeffType);
  void setSecondOrderLimit(CoeffType,CoeffType);

  OutputType doFilter(InputType);
};


#endif//QUADRAMP_FILTER_HPP
