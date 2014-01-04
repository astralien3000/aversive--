#ifndef FEEDBACK_LOOP_FILTER_HPP
#define FEEDBACK_LOOP_FILTER_HPP

#include "../base/integer.hpp"

template <class ConsignFilter, class FeedbackFilter, class ErrorFilter>
class FeedbackLoopFilter {
public:
  typedef typename ConsignFilter::InputType InputType;
  typedef typename ErrorFilter::OutputType OutputType;

  typedef typename FeedbackFilter::InputType FeedbackInputType;

private:
  ConsignFilter& _cf;
  FeedbackFilter& _ff;
  ErrorFilter& _ef;

  FeedbackInputType feedback;

public:
  inline FeedbackLoopFilter(ConsignFilter& cf, FeedbackFilter& ff, ErrorFilter& ef) : _cf(cf), _ff(ff), _ef(ef), feedback(0) {}

  inline void setFeedback(FeedbackInputType val) {
    feedback = val;
  }

  inline OutputType doFilter(InputType in) {
    return _ef.doFilter(_cf.doFilter(in) - _ff.doFilter(feedback));
  }
};

#endif//FEEDBACK_FILTER_HPP
