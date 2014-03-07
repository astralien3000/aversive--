#ifndef DIFF_FILTER_HPP
#define DIFF_FILTER_HPP

#include <base/integer.hpp>
#include <filter/filter.hpp>

//! \brief Differential Filter
/*!  

  Basically returns the difference between the current and the
  previous input.

 */
class DiffFilter : public Filter<s32> {
public:
  typedef s32 InputType;
  typedef s32 OutputType;
  typedef s32 CoeffType;

private:
  bool _first_call;
  InputType _last_in;
  CoeffType _delta;
  OutputType _last_out;
  
public:
  //! \brief Default Constructor
  DiffFilter(void);
  
  //! \brief Set the output divider
  void setDelta(CoeffType d);

  //! \brief Return the output divider
  CoeffType getDelta(void);

  //! \brief Computes output in function of input
  OutputType doFilter(InputType in);
};

#endif//DIFF_FILTER_HPP
