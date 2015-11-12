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

#ifndef PAIR_HPP
#define PAIR_HPP

#include "integer.hpp"

//! \class Pair pair.hpp <base/pair.hpp>
//! \brief Two-member tuple.
//! \param _LeftType : left member type.
//! \param _RightType : right member type.
//! \note This class is specialized for two-boolean tuples. See Pair<bool, bool> for more information.
template<typename _LeftType, typename _RightType>
class Pair {
public:
  //! \brief Left member's type.
  typedef _LeftType LeftType;
  
  //! \brief Right member's type.
  typedef _RightType RightType;
  
  //! \brief Left member's reference type.
  typedef LeftType& LeftRef;
  
  //! \brief Right member's reference type.
  typedef RightType& RightRef;
  
  //! \brief Left member's constant reference type.
  typedef const LeftType& LeftConstRef;
  
  //! \brief Right member's constant reference type.
  typedef const RightType& RightConstRef;
  
private:
  //! \brief The left member.
  LeftType _left;
  
  //! \brief The right member.
  RightType _right;
  
public:
  //! \brief Default Constructor.
  //! \attention The objects within the pair are not set to any value (i.e.: their default constructor is called).
  constexpr inline Pair(void) {
  }
  
  //! \brief Constructor with parameters.
  //! \param l : a reference to the object to copy in the left member.
  //! \param r : a reference to the object to copy in the right member.
  //! \attention Left and right types must have a copy constructor.
  constexpr inline Pair(LeftConstRef l, RightConstRef r)
    : _left(l), _right(r) {
  }
  
  //! \brief Copy Constructor.
  //! \param other : the pair to copy.
  constexpr inline Pair(const Pair& other)
    : _left(other._left), _right(other._right) {
  }
  
  //! \brief Copy Operator.
  //! \param other : the pair to copy.
  //! \return A reference to the pair that has been written.
  inline Pair& operator=(const Pair& other) {
    _left = other._left;
    _right = other._right;
    return (*this);
  }
  
  //! \brief Access the left member.
  //! \return The reference to the left member.
  constexpr inline LeftRef left(void) {
    return _left;
  }
  
  //! \brief Access the right member.
  //! \return The reference to the right member.
  constexpr inline RightRef right(void) {
    return _right;
  }
};

#endif//PAIR_HPP
