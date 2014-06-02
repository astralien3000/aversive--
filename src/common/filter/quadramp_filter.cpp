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

#include <filter/quadramp_filter.hpp>

QuadrampFilter::QuadrampFilter(void) {
  _prev_out = 0;
  _prev_var = 0;

  _lim_1st_order_pos = 0;
  _lim_1st_order_neg = 0;
  _lim_2nd_order_pos = 0;
  _lim_2nd_order_neg = 0;
}


void QuadrampFilter::setFirstOrderLimit(CoeffType pos, CoeffType neg) {
  _lim_1st_order_pos = pos;
  _lim_1st_order_neg = neg;
}


void QuadrampFilter::setSecondOrderLimit(CoeffType pos, CoeffType neg) {
  _lim_2nd_order_pos = pos;
  _lim_2nd_order_neg = neg;
}

template<typename T>
inline static T __min(T v1, T v2) {
  if(v1 < v2) return v1;
  else return v2;
}

template<typename T>
static T sqrt(T n) {
  T prev = n, x = n/2;
  while(x-prev > 1 || prev-x > 1) {
    prev = x;
    x = (prev + n/prev)/2;
  }
  return x;
}

// TAKEN FROM AVERSIVE
// TODO : Clean ?
// WARNING : VAR TYPES ARE NOT SIGNIFICANTS ? RANDOMLY DONE
typename QuadrampFilter::OutputType QuadrampFilter::doFilter(InputType in) {
	InputType d ;
	InputType pos_target;
	CoeffType var_1st_ord_pos = 0;
	CoeffType var_1st_ord_neg = 0;
	CoeffType var_2nd_ord_pos = 0;
	CoeffType var_2nd_ord_neg = 0;
	OutputType previous_var, previous_out ;

	if ( _lim_1st_order_pos )
		var_1st_ord_pos = _lim_1st_order_pos ;  

	if ( _lim_1st_order_neg )
		var_1st_ord_neg = -_lim_1st_order_neg ;

	if ( _lim_2nd_order_pos )
		var_2nd_ord_pos = _lim_2nd_order_pos ;  

	if ( _lim_2nd_order_neg )
		var_2nd_ord_neg = -_lim_2nd_order_neg ;

	previous_var = _prev_var;
	previous_out = _prev_out;

	d = in - previous_out ;

	/* Deceleration ramp */
	if ( d > 0 && var_2nd_ord_neg) {
		CoeffType ramp_pos;
		ramp_pos = sqrt( (var_2nd_ord_neg*var_2nd_ord_neg)/4 - 2*d*var_2nd_ord_neg ) + var_2nd_ord_neg/2;

		if(ramp_pos < var_1st_ord_pos)
			var_1st_ord_pos = ramp_pos ;
	}
	else if (d < 0 && var_2nd_ord_pos) {
		CoeffType ramp_neg;
		ramp_neg = -sqrt( (var_2nd_ord_pos*var_2nd_ord_pos)/4 - 2*d*var_2nd_ord_pos ) - var_2nd_ord_pos/2;
	
		if(ramp_neg > var_1st_ord_neg)
			var_1st_ord_neg = ramp_neg ;
	}
    
	/* try to set the speed : can we reach the speed with our acceleration ? */
	if ( previous_var < var_1st_ord_pos )  {
		if (var_2nd_ord_pos && ( var_1st_ord_pos - previous_var > var_2nd_ord_pos) )
			var_1st_ord_pos = previous_var + var_2nd_ord_pos ;
	}
	else if ( previous_var > var_1st_ord_pos )  { 
		if (var_2nd_ord_neg && ( var_1st_ord_pos - previous_var < var_2nd_ord_neg) )
			var_1st_ord_pos = previous_var + var_2nd_ord_neg;
	}
  
	/* same for the neg */
	if ( previous_var > var_1st_ord_neg )  {
		if (var_2nd_ord_neg && ( var_1st_ord_neg - previous_var < var_2nd_ord_neg) )
			var_1st_ord_neg = previous_var + var_2nd_ord_neg ;
	}
	else if ( previous_var < var_1st_ord_neg )  {
		if (var_2nd_ord_pos && (var_1st_ord_neg - previous_var > var_2nd_ord_pos) )
			var_1st_ord_neg = previous_var + var_2nd_ord_pos;
	}

	/*
	 * Position consign : can we reach the position with our speed ?
	 */
	if (d > var_1st_ord_pos ) {
		pos_target = previous_out + var_1st_ord_pos ;
		previous_var = var_1st_ord_pos ;
	}
	else if (d < var_1st_ord_neg ) {
		pos_target = previous_out + var_1st_ord_neg ;
		previous_var = var_1st_ord_neg ;
	}
	else {
		pos_target = previous_out + d ;
		previous_var = d ;
	}

	/* update previous_out and previous_var */
	_prev_var = previous_var;
	_prev_out = pos_target;

	return pos_target ;
}

