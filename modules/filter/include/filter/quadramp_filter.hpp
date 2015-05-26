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

  void reset(s32 last_out = 0) {
    _prev_out = last_out;
    _prev_var = 0;
  }
};


#endif//QUADRAMP_FILTER_HPP
