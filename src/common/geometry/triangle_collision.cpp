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

#include <base/integer.hpp>
#include <geometry/collision.hpp>

bool CollisionDetector::collide(const Point& p, const Triangle& t) {
  for(u8 i = 0; i < 3; i++) {
    const Vect<2, s32>& A = t[i];
    const Vect<2, s32>& B = t[(i == 2) ? 0 : i + 1];
    
    const Vect<2, s32> AB(B[0] - A[0], B[1] - A[1]);
    const Vect<2, s32> AP(p.x() - A[0], p.y() - A[1]);
    
    s32 d = AB[0] * AP[1] - AB[1] * AP[0];
    if(d >= 0) { // If P is on the left of AB, P is outside
      return false;
    }
  }
  return true;
}

bool CollisionDetector::collide(const Segment&s, const Triangle& t) {
  const Point sA(s.a());
  const Point sB(s.b());
  
  // If one of the extremum of the segment is in the triangle.
  if(collide(sA, t) || collide(sB, t)) {
    return true;
  }
  
  for(u8 i = 0; i < 3; i++) {
    const Vect<2, s32>& A = t[i];
    const Vect<2, s32>& B = t[(i == 2) ? 0 : i + 1];
    
    const Segment AB(A, B);
    if(collide(s, AB)) {
      return true;
    }
  }
  return false;
}

bool CollisionDetector::collide(const Circle& c, const Triangle& t) {
  const Point O(c.centre());
  if(collide(O, t)) { // If the centre of the circle is within the triangle.
    return true;
  }
  
  for(u8 i = 0; i < 3; i++) {
    const Vect<2, s32>& A = t[i];
    const Vect<2, s32>& B = t[(i == 2) ? 0 : i + 1];
    
    const Segment AB(A, B);
    if(collide(AB, c)) {
      return true;
    }
  }
  return false;
}

//! \todo Implement!
bool CollisionDetector::collide(const AABB& a, const Triangle& t) {
  (void) a;
  (void) t;
  return false;
}

//! \todo Implement!
bool CollisionDetector::collide(const Triangle& t1, const Triangle& t2) {
  (void) t1;
  (void) t2;
  return false;
}
