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

#ifndef KALMAN_FILTER_HPP
#define KALMAN_FILTER_HPP

#include "../base/integer.hpp"
#include "../math/vect.hpp"
#include "../math/matrix.hpp"

template<int DIM, typename T = s32>
class KalmanFilter {
public:
  typedef Vect<DIM, T> InputType;
  typedef Vect<DIM, T> OutputType;
  typedef Matrix<DIM, DIM, T> CoeffType;

private:
  OutputType _state_prediction;
  CoeffType _covariance_prediction;

  CoeffType _rec_link;
  OutputType _command;
  CoeffType _cmd_link;
  CoeffType _noise_covariance;

  OutputType _innovation;
  CoeffType _inv_covariance;
  CoeffType _optimal_gain;
  OutputType _state;
  CoeffType _covariance;

  OutputType _measure;
  CoeffType _msr_link;
  CoeffType _measure_noise_covariance;
  CoeffType _identity;

public:
  KalmanFilter(void) {
    for(int i = 0 ; i < DIM ; i++) {
      _identity.coord(i, i) = 1;
    }
  }

  void prediction(void) {
    _state_prediction = _rec_link * _state + _cmd_link * _command;
    _covariance_prediction = _rec_link * _covariance * _rec_link.transpose() + _noise_covariance;
  }

  void update(void) {
    _innovation = _measure - _msr_link * _state_prediction;
    _inv_covariance = _msr_link * _covariance_prediction * _msr_link.transpose() + _measure_noise_covariance;
    _optimal_gain = _covariance_prediction * _msr_link.transpose() * _inv_covariance.inv();
    _state = _state_prediction + _optimal_gain * _innovation;
    _covariance = (_identity - _optimal_gain * _msr_link) * _covariance_prediction;
  }
};

#endif//KALMAN_FILTER_HPP
