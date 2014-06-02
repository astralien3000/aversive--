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

#ifndef PID_FILTER_HPP
#define PID_FILTER_HPP

#include <base/integer.hpp>
#include <filter/filter.hpp>

//! \brief PID Filter
class PidFilter : public Filter<s32> {
public:
  typedef s32 InputType;
  typedef s32 OutputType;
  typedef s32 CoeffType;

private:
  InputType _last_in;
  InputType _sum_in;

  CoeffType _gain_p;
  CoeffType _gain_i;
  CoeffType _gain_d;

  OutputType _max_i;

  CoeffType _out_shift;

  OutputType _last_out;

public:
  //! \brief Constructor with initialisation of all gains
  PidFilter(CoeffType p = 0, CoeffType i = 0, CoeffType d = 0);
  
  //! \brief Set coefficients of the PID
  void setGains(CoeffType p, CoeffType i, CoeffType d);

  //! \brief Sets the limit for integral output
  void setMaxIntegral(OutputType val);

  //! \brief Sets the output divided by 2^shift
  void setOutShift(CoeffType shift);

  //! \brief Return Proportionnal Gain
  CoeffType getGainP(void);

  //! \brief Return Integral Gain
  CoeffType getGainI(void);

  //! \brief Return Derivate Gain
  CoeffType getGainD(void);

  //! \brief Return limit for integral output
  OutputType getMaxIntegral(void);

  //! \brief Return the log2 division of output
  CoeffType getOutShift(void);

  //! \brief Compute output in function of input
  OutputType doFilter(InputType in);

  //! \brief Return last computed output
  OutputType lastOut(void);

  //! \brief Create a PID in which the output is the input
  static PidFilter identity(void);

  inline void reset(void) {
    _last_in = 0;
    _sum_in = 0;
    _last_out = 0;
  }
};

#endif//PID_FILTER_HPP
