/*
    Aversive++                                                           
    Copyright (C) 2014 Eirbot                                            
                                                                         
    This program is free software: you can redistribute it and/or modify 
    it under the terms of the GNU General Public License as published by 
    the Free Software Foundation, either version 3 of the License, or    
    (at your option) any later version.                                  
                                                                         
    This program is distributed in the hope that it will be useful,      
    but WITHOUT ANY WARRANTY; without even the implied warranty of       
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        
    GNU General Public License for more details.                         
                                                                         
    You should have received a copy of the GNU General Public License    
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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
