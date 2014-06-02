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
