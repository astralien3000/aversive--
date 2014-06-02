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

#include <filter/diff_filter.hpp>

DiffFilter::DiffFilter(void) : _first_call(true), _last_in(0), _delta(1), _last_out(0) {}
  
void DiffFilter::setDelta(CoeffType d) {
  _delta = d;
}

typename DiffFilter::CoeffType DiffFilter::getDelta(void) {
  return _delta;
}

typename DiffFilter::OutputType DiffFilter::doFilter(typename DiffFilter::InputType in) {
  if(!_first_call) {
    _last_out = (in - _last_in) / _delta;
  }
  else {
    _first_call = false;
    _last_out = 0;
  }

  _last_in = in;
  return _last_out;
}
