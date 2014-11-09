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

#ifndef SATURATE_HPP
#define SATURATE_HPP

namespace Math {

  //! \brief Ensures that an integer is contained into an interval (template version)
  template<int min, int max, typename T>
  inline const T saturate(T val) {
    if(val > (T)max) return max;
    else if(val < (T)min) return min;
    return val;
  }

  //! \brief Ensures that an integer is contained into an interval
  template<typename T>
  inline const T saturate(T val, T min, T max) {
    if(val > (T)max) return max;
    else if(val < (T)min) return min;
    return val;
  }

  //! \brief Useful for circula buffers
  template<int min, int max, typename T>
  inline const T mod(T val) {
    return min + ((val - min) % (max - min));
  }

  //! \brief Test if value is contained into an interval
  template<int min, int max, typename T>
  inline bool belong(T val) {
    return !(val < (T)min || (T)max < val);
  }

  template<typename T>
  inline bool belong(T val, T min, T max) {
    return !(val < (T)min || (T)max < val);
  }

  //! \brief The absolute value
  template<typename T>
  inline const T abs(T val) {
    return ((val < (T)0) ? -val : val);
  }

  //! \brief The maximum of two values
  template<typename T>
  inline T& max(T& v1, T& v2) {
    return ((v1 > v2) ? v1 : v2);
  }

  //! \brief The minimum of two values
  template<typename T>
  inline T& min(T& v1, T& v2) {
    return ((v1 < v2) ? v1 : v2);
  }

}

#endif//SATURATE_HPP
