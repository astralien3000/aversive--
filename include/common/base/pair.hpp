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

//! \class Pair pair.hpp <base/pair.hpp>
//! \brief Two-member tuple.
//! \param _LeftType : left member type.
//! \param _RightType : right member type.
template<typename _LeftType, typename _RightType>
class Pair {
public:
  //! \brief Left member's type.
  typedef _LeftType LeftType;
  
  //! \brief Right member's type.
  typedef _RightType RightType;
  
private:
  //! \brief The left member.
  LeftType _left;
  
  //! \brief The right member.
  RightType _right;
  
public:  
  //! \brief Default Constructor.
  //! \attention The objects within the pair are not set to any value.
  inline Pair(void) {
  }
  
  //! \brief Constructor with parameters.
  //! \param l : a reference to the object to copy in the left member.
  //! \param r : a reference to the object to copy in the right member.
  //! \attention Left and right types must have a copy constructor.
  inline Pair(const LeftType& l, const RightType& r)
    : _left(l), _right(r) {
  }
  
  //! \brief Copy Constructor.
  //! \param other : the pair to copy.
  inline Pair(const Pair& other) {
    (*this) = other;
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
  inline LeftType& left(void) {
    return _left;
  }
  
  //! \brief Access the right member.
  //! \return The reference to the right member.
  inline RightType& right(void) {
    return _right;
  }
  
  //! \brief Access the left member (constant version).
  //! \return The constant reference to the left member.
  inline const LeftType& left(void) const {
    return _left;
  }
  
  //! \brief Access the right member (constant version).
  //! \return The constant reference to the right member.
  inline const RightType& right(void) const {
    return _right;
  }
};

#endif//PAIR_HPP
