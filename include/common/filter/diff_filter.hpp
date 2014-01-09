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
  DiffFilter(void);
  
  void setDelta(CoeffType d);

  OutputType doFilter(InputType in);
};

#endif//DIFF_FILTER_HPP
