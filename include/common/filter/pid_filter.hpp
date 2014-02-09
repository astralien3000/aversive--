#ifndef PID_FILTER_HPP
#define PID_FILTER_HPP

#include <base/integer.hpp>
#include <filter/filter.hpp>

//! \brief PID Filter
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

  CoeffType _out_shift;

  OutputType _last_out;

public:
  //! \brief Constructor with initialisation of all gains
  PidFilter(CoeffType p = 0, CoeffType i = 0, CoeffType d = 0);
  
  void setGains(CoeffType p, CoeffType i, CoeffType d);

  //! \brief Sets the limit for integral output
  void setMaxIntegral(OutputType val);

  //! \brief Sets the output divided by 2^shift
  void setOutShift(CoeffType shift);

  OutputType doFilter(InputType in);

  OutputType out(void);
};

#endif//PID_FILTER_HPP
