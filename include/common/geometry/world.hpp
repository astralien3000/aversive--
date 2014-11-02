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

#ifndef WORLD_HPP
#define WORLD_HPP

#include <base/integer.hpp>
#include <math/vect.hpp>
#include <container/list.hpp>
#include <geometry/shape.hpp>
#include <geometry/collision.hpp>

//! \class World world.hpp "world.hpp"
//! \brief Represents a 2D environnment.
//! \param _SIZE : the amount of objects the world can handle.
//! \param _GREATEST : the greatest type the world works with (Point, Segment, Circle, AABB, Triangle, Quadrilateral)
template<list_t _SIZE, typename _GREATEST>
class World {
public:
  static const list_t SIZE = _SIZE;
  
  List<SIZE, const Shape*> _shapes;
  
public:
  inline World(void)
    : _shapes() {
  }
  
  inline bool addShape(const Shape* s) {
    if(_shapes.contains(s)) {
      return true;
    }
    return _shapes.append(s);
  }
  
  inline bool removeShape(const Shape* s) {
    return _shapes.remove(s);
  }
  
  inline list_t usedSpace() const {
    return _shapes.usedSpace();
  }
  
  inline bool collide(const Shape& s) const {
    for(list_t  i = 0; i < _shapes.usedSpace(); i++) {
      if(_shapes.get(i) != &s && CollisionDetector::collide<_GREATEST>(*(_shapes.get(i)), s)) {
	return true;
      }
    }
    return false;
  }
  
  template<typename Callable>
  inline void doForeach(Callable func) const {
    _shapes.doForeach(func);
  }
};

#endif//WORLD_HPP
