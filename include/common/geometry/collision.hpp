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

#ifndef COLLISION_HPP
#define COLLISION_HPP

#include <geometry/shape.hpp>
#include <geometry/triangle.hpp>
#include <geometry/quadrilateral.hpp>
#include <geometry/aabb.hpp>
#include <geometry/circle.hpp>
#include <geometry/segment.hpp>
#include <geometry/point.hpp>

class CollisionDetector {
public:
  // Generic
  template<typename T>
  static inline bool collide(const Shape& s1, const Shape& s2) {
    return false;
  }
  
  // Point's collision
  template<typename T>
  static inline bool collide(const Point& s1, const Shape& s2) {
    return false;
  }
  
  static bool collide(const Point& p1, const Point& p2);
  static bool collide(const Point& p, const Segment& s);
  static bool collide(const Point& p, const Circle& c);
  static bool collide(const Point& p, const AABB& a);
  static bool collide(const Point& p, const Triangle& t);
  static bool collide(const Point& p, const Quadrilateral& q);
  
  // Segment's collision
  template<typename T>
  static inline bool collide(const Segment& s1, const Shape& s2) {
    return false;
  }
  
  inline static bool collide(const Segment& s, const Point& p) {
    return collide(p, s);
  }
  static bool collide(const Segment& s1, const Segment& s2);
  static bool collide(const Segment& s, const Circle& c);
  static bool collide(const Segment& s, const AABB& a);
  static bool collide(const Segment& s, const Triangle& t);
  static bool collide(const Segment& s, const Quadrilateral& q);
  
  // Circle's collision
  template<typename T>
  static inline bool collide(const Circle& s1, const Shape& s2) {
    return false;
  }
    
  inline static bool collide(const Circle& c, const Point& p) {
    return collide(p, c);
  }
  inline static bool collide(const Circle& c, const Segment& s) {
    return collide(s, c);
  }
  static bool collide(const Circle& c1, const Circle& c2);
  static bool collide(const Circle& c, const AABB& a);
  static bool collide(const Circle& c, const Triangle& t);
  static bool collide(const Circle& c, const Quadrilateral& q);
  
  // AABB's collision
  template<typename T>
  static inline bool collide(const AABB& s1, const Shape& s2) {
    return false;
  }
    
  inline static bool collide(const AABB& a, const Point& p) {
    return collide(p, a);
  }
  inline static bool collide(const AABB& a, const Segment& s) {
    return collide(s, a);
  }
  inline static bool collide(const AABB& a, const Circle& c) {
    return collide(c, a);
  }
  static bool collide(const AABB& a1, const AABB& a2);
  static bool collide(const AABB& a, const Triangle& t);
  static bool collide(const AABB& a, const Quadrilateral& q);
  
  // Triangle's collision
  template<typename T>
  static inline bool collide(const Triangle& s1, const Shape& s2) {
    return false;
  }
  
  inline static bool collide(const Triangle& t, const Point& p) {
    return collide(p, t);
  }
  inline static bool collide(const Triangle& t, const Segment& s) {
    return collide(s, t);
  }
  inline static bool collide(const Triangle& t, const Circle& c) {
    return collide(c, t);
  }
  inline static bool collide(const Triangle& t, const AABB& a) {
    return collide(a, t);
  }
  static bool collide(const Triangle& t1, const Triangle& t2);
  static bool collide(const Triangle& t, const Quadrilateral& q);
  
  // Quadrilateral's collision
  template<typename T>
  static inline bool collide(const Quadrilateral& s1, const Shape& s2) {
    return false;
  }
  
  inline static bool collide(const Quadrilateral& q, const Point& p) {
    return collide(p, q);
  }
  inline static bool collide(const Quadrilateral& q, const Segment& s) {
    return collide(s, q);
  }
  inline static bool collide(const Quadrilateral& q, const Circle& c) {
    return collide(c, q);
  }
  inline static bool collide(const Quadrilateral& q, const AABB& a) {
    return collide(a, q);
  }
  inline static bool collide(const Quadrilateral& q, const Triangle& t) {
    return collide(t, q);
  }
  static bool collide(const Quadrilateral& q1, const Quadrilateral& q2);
};

// Point
template<>
inline bool CollisionDetector::collide<Point>(const Point& p, const Shape& s) {
  if(s.shapeId() == Point::ID) {
    return collide(p, *reinterpret_cast<const Point*>(&s));
  }
  return false;
}
  
template<>
inline bool CollisionDetector::collide<Segment>(const Point& p, const Shape& s) {
  if(s.shapeId() == Point::ID) {
    return collide(p, *reinterpret_cast<const Point*>(&s));
  }
  else if(s.shapeId() == Segment::ID) {
    return collide(p, *reinterpret_cast<const Segment*>(&s));
  }
  return false;
}
  
template<>
inline bool CollisionDetector::collide<Circle>(const Point& p, const Shape& s) {
  if(s.shapeId() == Point::ID) {
    return collide(p, *reinterpret_cast<const Point*>(&s));
  }
  else if(s.shapeId() == Segment::ID) {
    return collide(p, *reinterpret_cast<const Segment*>(&s));
  }
  else if(s.shapeId() == Circle::ID) {
    return collide(p, *reinterpret_cast<const Circle*>(&s));
  }
  return false;
}
  
template<>
inline bool CollisionDetector::collide<AABB>(const Point& p, const Shape& s) {
  if(s.shapeId() == Point::ID) {
    return collide(p, *reinterpret_cast<const Point*>(&s));
  }
  else if(s.shapeId() == Segment::ID) {
    return collide(p, *reinterpret_cast<const Segment*>(&s));
  }
  else if(s.shapeId() == Circle::ID) {
    return collide(p, *reinterpret_cast<const Circle*>(&s));
  }
  else if(s.shapeId() == AABB::ID) {
    return collide(p, *reinterpret_cast<const AABB*>(&s));
  }
  return false;
}
  
template<>
inline bool CollisionDetector::collide<Triangle>(const Point& p, const Shape& s) {
  if(s.shapeId() == Point::ID) {
    return collide(p, *reinterpret_cast<const Point*>(&s));
  }
  else if(s.shapeId() == Segment::ID) {
    return collide(p, *reinterpret_cast<const Segment*>(&s));
  }
  else if(s.shapeId() == Circle::ID) {
    return collide(p, *reinterpret_cast<const Circle*>(&s));
  }
  else if(s.shapeId() == AABB::ID) {
    return collide(p, *reinterpret_cast<const AABB*>(&s));
  }
  else if(s.shapeId() == Triangle::ID) {
    return collide(p, *reinterpret_cast<const Triangle*>(&s));
  }
  return false;
}
  
template<>
inline bool CollisionDetector::collide<Quadrilateral>(const Point& p, const Shape& s) {
  if(s.shapeId() == Point::ID) {
    return collide(p, *reinterpret_cast<const Point*>(&s));
  }
  else if(s.shapeId() == Segment::ID) {
    return collide(p, *reinterpret_cast<const Segment*>(&s));
  }
  else if(s.shapeId() == Circle::ID) {
    return collide(p, *reinterpret_cast<const Circle*>(&s));
  }
  else if(s.shapeId() == AABB::ID) {
    return collide(p, *reinterpret_cast<const AABB*>(&s));
  }
  else if(s.shapeId() == Triangle::ID) {
    return collide(p, *reinterpret_cast<const Triangle*>(&s));
  }
  else if(s.shapeId() == Quadrilateral::ID) {
    return collide(p, *reinterpret_cast<const Quadrilateral*>(&s));
  }
  return false;
}

// Segment
template<>
inline bool CollisionDetector::collide<Segment>(const Segment& s1, const Shape& s2) {
  if(s2.shapeId() == Point::ID) {
    return collide(s1, *reinterpret_cast<const Point*>(&s2));
  }
  else if(s2.shapeId() == Segment::ID) {
    return collide(s1, *reinterpret_cast<const Segment*>(&s2));
  }
  return false;
}
  
template<>
inline bool CollisionDetector::collide<Circle>(const Segment& s1, const Shape& s2) {
  if(s2.shapeId() == Point::ID) {
    return collide(s1, *reinterpret_cast<const Point*>(&s2));
  }
  else if(s2.shapeId() == Segment::ID) {
    return collide(s1, *reinterpret_cast<const Segment*>(&s2));
  }
  else if(s2.shapeId() == Circle::ID) {
    return collide(s1, *reinterpret_cast<const Circle*>(&s2));
  }
  return false;
}
  
template<>
inline bool CollisionDetector::collide<AABB>(const Segment& s1, const Shape& s2) {
  if(s2.shapeId() == Point::ID) {
    return collide(s1, *reinterpret_cast<const Point*>(&s2));
  }
  else if(s2.shapeId() == Segment::ID) {
    return collide(s1, *reinterpret_cast<const Segment*>(&s2));
  }
  else if(s2.shapeId() == Circle::ID) {
    return collide(s1, *reinterpret_cast<const Circle*>(&s2));
  }
  else if(s2.shapeId() == AABB::ID) {
    return collide(s1, *reinterpret_cast<const AABB*>(&s2));
  }
  return false;
}
  
template<>
inline bool CollisionDetector::collide<Triangle>(const Segment& s1, const Shape& s2) {
  if(s2.shapeId() == Point::ID) {
    return collide(s1, *reinterpret_cast<const Point*>(&s2));
  }
  else if(s2.shapeId() == Segment::ID) {
    return collide(s1, *reinterpret_cast<const Segment*>(&s2));
  }
  else if(s2.shapeId() == Circle::ID) {
    return collide(s1, *reinterpret_cast<const Circle*>(&s2));
  }
  else if(s2.shapeId() == AABB::ID) {
    return collide(s1, *reinterpret_cast<const AABB*>(&s2));
  }
  else if(s2.shapeId() == Triangle::ID) {
    return collide(s1, *reinterpret_cast<const Triangle*>(&s2));
  }
  return false;
}
  
template<>
inline bool CollisionDetector::collide<Quadrilateral>(const Segment& s1, const Shape& s2) {
  if(s2.shapeId() == Point::ID) {
    return collide(s1, *reinterpret_cast<const Point*>(&s2));
  }
  else if(s2.shapeId() == Segment::ID) {
    return collide(s1, *reinterpret_cast<const Segment*>(&s2));
  }
  else if(s2.shapeId() == Circle::ID) {
    return collide(s1, *reinterpret_cast<const Circle*>(&s2));
  }
  else if(s2.shapeId() == AABB::ID) {
    return collide(s1, *reinterpret_cast<const AABB*>(&s2));
  }
  else if(s2.shapeId() == Triangle::ID) {
    return collide(s1, *reinterpret_cast<const Triangle*>(&s2));
  }
  else if(s2.shapeId() == Quadrilateral::ID) {
    return collide(s1, *reinterpret_cast<const Quadrilateral*>(&s2));
  }
  return false;
}

// Circle
template<>
inline bool CollisionDetector::collide<Circle>(const Circle& c, const Shape& s) {
  if(s.shapeId() == Point::ID) {
    return collide(c, *reinterpret_cast<const Point*>(&s));
  }
  else if(s.shapeId() == Segment::ID) {
    return collide(c, *reinterpret_cast<const Segment*>(&s));
  }
  else if(s.shapeId() == Circle::ID) {
    return collide(c, *reinterpret_cast<const Circle*>(&s));
  }
  return false;
}
  
template<>
inline bool CollisionDetector::collide<AABB>(const Circle& c, const Shape& s) {
  if(s.shapeId() == Point::ID) {
    return collide(c, *reinterpret_cast<const Point*>(&s));
  }
  else if(s.shapeId() == Segment::ID) {
    return collide(c, *reinterpret_cast<const Segment*>(&s));
  }
  else if(s.shapeId() == Circle::ID) {
    return collide(c, *reinterpret_cast<const Circle*>(&s));
  }
  else if(s.shapeId() == AABB::ID) {
    return collide(c, *reinterpret_cast<const AABB*>(&s));
  }
  return false;
}
  
template<>
inline bool CollisionDetector::collide<Triangle>(const Circle& c, const Shape& s) {
  if(s.shapeId() == Point::ID) {
    return collide(c, *reinterpret_cast<const Point*>(&s));
  }
  else if(s.shapeId() == Segment::ID) {
    return collide(c, *reinterpret_cast<const Segment*>(&s));
  }
  else if(s.shapeId() == Circle::ID) {
    return collide(c, *reinterpret_cast<const Circle*>(&s));
  }
  else if(s.shapeId() == AABB::ID) {
    return collide(c, *reinterpret_cast<const AABB*>(&s));
  }
  else if(s.shapeId() == Triangle::ID) {
    return collide(c, *reinterpret_cast<const Triangle*>(&s));
  }
  return false;
}
  
template<>
inline bool CollisionDetector::collide<Quadrilateral>(const Circle& c, const Shape& s) {
  if(s.shapeId() == Point::ID) {
    return collide(c, *reinterpret_cast<const Point*>(&s));
  }
  else if(s.shapeId() == Segment::ID) {
    return collide(c, *reinterpret_cast<const Segment*>(&s));
  }
  else if(s.shapeId() == Circle::ID) {
    return collide(c, *reinterpret_cast<const Circle*>(&s));
  }
  else if(s.shapeId() == AABB::ID) {
    return collide(c, *reinterpret_cast<const AABB*>(&s));
  }
  else if(s.shapeId() == Triangle::ID) {
    return collide(c, *reinterpret_cast<const Triangle*>(&s));
  }
  else if(s.shapeId() == Quadrilateral::ID) {
    return collide(c, *reinterpret_cast<const Quadrilateral*>(&s));
  }
  return false;
}

// AABB
template<>
inline bool CollisionDetector::collide<AABB>(const AABB& a, const Shape& s) {
  if(s.shapeId() == Point::ID) {
    return collide(a, *reinterpret_cast<const Point*>(&s));
  }
  else if(s.shapeId() == Segment::ID) {
    return collide(a, *reinterpret_cast<const Segment*>(&s));
  }
  else if(s.shapeId() == Circle::ID) {
    return collide(a, *reinterpret_cast<const Circle*>(&s));
  }
  else if(s.shapeId() == AABB::ID) {
    return collide(a, *reinterpret_cast<const AABB*>(&s));
  }
  return false;
}
  
template<>
inline bool CollisionDetector::collide<Triangle>(const AABB& a, const Shape& s) {
  if(s.shapeId() == Point::ID) {
    return collide(a, *reinterpret_cast<const Point*>(&s));
  }
  else if(s.shapeId() == Segment::ID) {
    return collide(a, *reinterpret_cast<const Segment*>(&s));
  }
  else if(s.shapeId() == Circle::ID) {
    return collide(a, *reinterpret_cast<const Circle*>(&s));
  }
  else if(s.shapeId() == AABB::ID) {
    return collide(a, *reinterpret_cast<const AABB*>(&s));
  }
  else if(s.shapeId() == Triangle::ID) {
    return collide(a, *reinterpret_cast<const Triangle*>(&s));
  }
  return false;
}
  
template<>
inline bool CollisionDetector::collide<Quadrilateral>(const AABB& a, const Shape& s) {
  if(s.shapeId() == Point::ID) {
    return collide(a, *reinterpret_cast<const Point*>(&s));
  }
  else if(s.shapeId() == Segment::ID) {
    return collide(a, *reinterpret_cast<const Segment*>(&s));
  }
  else if(s.shapeId() == Circle::ID) {
    return collide(a, *reinterpret_cast<const Circle*>(&s));
  }
  else if(s.shapeId() == AABB::ID) {
    return collide(a, *reinterpret_cast<const AABB*>(&s));
  }
  else if(s.shapeId() == Triangle::ID) {
    return collide(a, *reinterpret_cast<const Triangle*>(&s));
  }
  else if(s.shapeId() == Quadrilateral::ID) {
    return collide(a, *reinterpret_cast<const Quadrilateral*>(&s));
  }
  return false;
}

// Triangle
template<>
inline bool CollisionDetector::collide<Triangle>(const Triangle& t, const Shape& s) {
  if(s.shapeId() == Point::ID) {
    return collide(t, *reinterpret_cast<const Point*>(&s));
  }
  else if(s.shapeId() == Segment::ID) {
    return collide(t, *reinterpret_cast<const Segment*>(&s));
  }
  else if(s.shapeId() == Circle::ID) {
    return collide(t, *reinterpret_cast<const Circle*>(&s));
  }
  else if(s.shapeId() == AABB::ID) {
    return collide(t, *reinterpret_cast<const AABB*>(&s));
  }
  else if(s.shapeId() == Triangle::ID) {
    return collide(t, *reinterpret_cast<const Triangle*>(&s));
  }
  return false;
}
  
template<>
inline bool CollisionDetector::collide<Quadrilateral>(const Triangle& t, const Shape& s) {
  if(s.shapeId() == Point::ID) {
    return collide(t, *reinterpret_cast<const Point*>(&s));
  }
  else if(s.shapeId() == Segment::ID) {
    return collide(t, *reinterpret_cast<const Segment*>(&s));
  }
  else if(s.shapeId() == Circle::ID) {
    return collide(t, *reinterpret_cast<const Circle*>(&s));
  }
  else if(s.shapeId() == AABB::ID) {
    return collide(t, *reinterpret_cast<const AABB*>(&s));
  }
  else if(s.shapeId() == Triangle::ID) {
    return collide(t, *reinterpret_cast<const Triangle*>(&s));
  }
  else if(s.shapeId() == Quadrilateral::ID) {
    return collide(t, *reinterpret_cast<const Quadrilateral*>(&s));
  }
  return false;
}

// Quadrilateral
template<>
inline bool CollisionDetector::collide<Quadrilateral>(const Quadrilateral& q, const Shape& s) {
  if(s.shapeId() == Point::ID) {
    return collide(q, *reinterpret_cast<const Point*>(&s));
  }
  else if(s.shapeId() == Segment::ID) {
    return collide(q, *reinterpret_cast<const Segment*>(&s));
  }
  else if(s.shapeId() == Circle::ID) {
    return collide(q, *reinterpret_cast<const Circle*>(&s));
  }
  else if(s.shapeId() == AABB::ID) {
    return collide(q, *reinterpret_cast<const AABB*>(&s));
  }
  else if(s.shapeId() == Triangle::ID) {
    return collide(q, *reinterpret_cast<const Triangle*>(&s));
  }
  else if(s.shapeId() == Quadrilateral::ID) {
    return collide(q, *reinterpret_cast<const Quadrilateral*>(&s));
  }
  return false;
}

// Generic
template<>
inline bool CollisionDetector::collide<Point>(const Shape& s1, const Shape& s2) {
  if(s1.shapeId() == Point::ID) {
    return collide<Point>(*reinterpret_cast<const Point*>(&s1), s2);
  }
  return false;
}
  
template<>
inline bool CollisionDetector::collide<Segment>(const Shape& s1, const Shape& s2) {
  if(s1.shapeId() == Point::ID) {
    return collide<Segment>(*reinterpret_cast<const Point*>(&s1), s2);
  }
  else if(s1.shapeId() == Segment::ID) {
    return collide<Segment>(*reinterpret_cast<const Segment*>(&s1), s2);
  }
  return false;
}
  
template<>
inline bool CollisionDetector::collide<Circle>(const Shape& s1, const Shape& s2) {
  if(s1.shapeId() == Point::ID) {
    return collide<Circle>(*reinterpret_cast<const Point*>(&s1), s2);
  }
  else if(s1.shapeId() == Segment::ID) {
    return collide<Circle>(*reinterpret_cast<const Segment*>(&s1), s2);
  }
  else if(s1.shapeId() == Circle::ID) {
    return collide<Circle>(*reinterpret_cast<const Circle*>(&s1), s2);
  }
  return false;
}
  
template<>
inline bool CollisionDetector::collide<AABB>(const Shape& s1, const Shape& s2) {
  if(s1.shapeId() == Point::ID) {
    return collide<AABB>(*reinterpret_cast<const Point*>(&s1), s2);
  }
  else if(s1.shapeId() == Segment::ID) {
    return collide<AABB>(*reinterpret_cast<const Segment*>(&s1), s2);
  }
  else if(s1.shapeId() == Circle::ID) {
    return collide<AABB>(*reinterpret_cast<const Circle*>(&s1), s2);
  }
  else if(s1.shapeId() == AABB::ID) {
    return collide<AABB>(*reinterpret_cast<const AABB*>(&s1), s2);
  }
  return false;
}
  
template<>
inline bool CollisionDetector::collide<Triangle>(const Shape& s1, const Shape& s2) {
  if(s1.shapeId() == Point::ID) {
    return collide<Triangle>(*reinterpret_cast<const Point*>(&s1), s2);
  }
  else if(s1.shapeId() == Segment::ID) {
    return collide<Triangle>(*reinterpret_cast<const Segment*>(&s1), s2);
  }
  else if(s1.shapeId() == Circle::ID) {
    return collide<Triangle>(*reinterpret_cast<const Circle*>(&s1), s2);
  }
  else if(s1.shapeId() == AABB::ID) {
    return collide<Triangle>(*reinterpret_cast<const AABB*>(&s1), s2);
  }
  else if(s1.shapeId() == Triangle::ID) {
    return collide<Triangle>(*reinterpret_cast<const Triangle*>(&s1), s2);
  }
  return false;
}
  
template<>
inline bool CollisionDetector::collide<Quadrilateral>(const Shape& s1, const Shape& s2) {
  if(s1.shapeId() == Point::ID) {
    return collide<Quadrilateral>(*reinterpret_cast<const Point*>(&s1), s2);
  }
  else if(s1.shapeId() == Segment::ID) {
    return collide<Quadrilateral>(*reinterpret_cast<const Segment*>(&s1), s2);
  }
  else if(s1.shapeId() == Circle::ID) {
    return collide<Quadrilateral>(*reinterpret_cast<const Circle*>(&s1), s2);
  }
  else if(s1.shapeId() == AABB::ID) {
    return collide<Quadrilateral>(*reinterpret_cast<const AABB*>(&s1), s2);
  }
  else if(s1.shapeId() == Triangle::ID) {
    return collide<Quadrilateral>(*reinterpret_cast<const Triangle*>(&s1), s2);
  }
  else if(s1.shapeId() == Quadrilateral::ID) {
    return collide<Quadrilateral>(*reinterpret_cast<const Quadrilateral*>(&s1), s2);
  }
  return false;
}

#endif//COLLISION_HPP
