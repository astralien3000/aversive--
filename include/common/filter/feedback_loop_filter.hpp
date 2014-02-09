#ifndef FEEDBACK_LOOP_FILTER_HPP
#define FEEDBACK_LOOP_FILTER_HPP

#include <base/integer.hpp>
#include <filter/filter.hpp>

class FeedbackLoopFilter : Filter<s32> {
public:
  typedef s32 InputType;
  typedef s32 OutputType;

  typedef s32 FeedbackInputType;

private:
  Filter& _cf;
  Filter& _ff;
  Filter& _ef;

  FeedbackInputType feedback;

public:
  inline FeedbackLoopFilter(Filter& cf, Filter& ff, Filter& ef) : _cf(cf), _ff(ff), _ef(ef), feedback(0) {}

  inline void setFeedback(FeedbackInputType val) {
    feedback = val;
  }

  inline OutputType doFilter(InputType in) {
    return _ef.doFilter(_cf.doFilter(in) - _ff.doFilter(feedback));
  }
};

#endif//FEEDBACK_FILTER_HPP
