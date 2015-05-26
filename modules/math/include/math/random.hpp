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

#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <base/integer.hpp>
#include <math/vect.hpp>

//! \class Random random.hpp <math/random.hpp>
//! \brief Random number generator.
//! \note The implemented PRNG passes the BigCrush tests.
//! \warning Do not use for cryptographic purposes.
class Random {
  inline Random() {
  }
  
  inline Random(const Random& o) {
    (void) o;
  }
  
  //! \brief The current state of the PRNG
  static Vect<2, u64> state;

public:
  //! \brief Seed the PRNG.
  //! \param s : the new state of the PRNG
  inline static void seed(const Vect<2, u64>& s) {
    state = s;
  }
  
  //! \brief Generate the next random value.
  //! \return The new randomly generated value.
  static u64 next(void);
};

#endif//RANDOM_HPP
