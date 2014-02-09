#ifndef QUADRAMP_FILTER_HPP
#define QUADRAMP_FILTER_HPP

#include <base/integer.hpp>
#include <filter/filter.hpp>

class QuadrampFilter : public Filter<s32> {
public:
  typedef s32 InputType;
  typedef s32 OutputType;

private:
  typedef s32 CoeffType;

  OutputType _prev_out;
  OutputType _prev_var;

  CoeffType _lim_1st_order_pos;
  CoeffType _lim_1st_order_neg;
  CoeffType _lim_2nd_order_pos;
  CoeffType _lim_2nd_order_neg;

public:
  QuadrampFilter(void);
  
  void setFirstOrderLimit(CoeffType pos, CoeffType neg);

  void setSecondOrderLimit(CoeffType pos, CoeffType neg);

  OutputType doFilter(InputType in);
};


#endif//QUADRAMP_FILTER_HPP
