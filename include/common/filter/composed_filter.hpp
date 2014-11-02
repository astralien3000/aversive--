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

#ifndef COMPOSED_FILTER_HPP
#define COMPOSED_FILTER_HPP

#include "../base/integer.hpp"
#include <filter/filter.hpp>

class ComposedFilter : public Filter<s32> {
public:
  typedef s32 InputType;
  typedef s32 OutputType;
  
private:
  Filter& _f1;
  Filter& _f2;

public:
  inline ComposedFilter(Filter& f1, Filter& f2) : _f1(f1), _f2(f2) {}
  
  OutputType doFilter(InputType in) {
    return _f2.doFilter(_f1.doFilter(in));
  }
};

#endif//COMPOSED_FILTER_HPP
