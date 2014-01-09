#ifndef PID_FILTER_HPP
#define PID_FILTER_HPP

#include "../base/integer.hpp"
#include "filter.hpp"

//! \brief PID Filter
/*!
  \todo
 */
class PidFilter : public Filter<s32> {
public:
  typedef s32 InputType;
  typedef s32 OutputType;

private:
  typedef s32 CoeffType;

  InputType _last_in;
  InputType _sum_in;

  CoeffType _gain_p;
  CoeffType _gain_i;
  CoeffType _gain_d;

  OutputType _max_i;

public:
  //! \brief Constructor with initialisation of all gains
  PidFilter(CoeffType p = 0, CoeffType i = 0, CoeffType d = 0);
  
  void setGains(CoeffType p, CoeffType i, CoeffType d);

  //! \brief Sets the limit for integral output
  void setMaxIntegral(OutputType val);

  OutputType doFilter(InputType in);
};

#endif//PID_FILTER_HPP
