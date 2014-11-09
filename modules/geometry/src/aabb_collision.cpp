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

bool CollisionDetector::collide(const Point& p, const AABB& a) {
  const s32 left = a.o()[0];
  const s32 right = a.o()[0] + a.w();
  const s32 bottom = a.o()[1];
  const s32 top = a.o()[1] + a.h();
  
  if(p.x() <= left) {
    return false;
  }
  else if(p.x() >= right) {
    return false;
  }
  else if(p.y() <= bottom) {
    return false;
  }
  else if(p.y() >= top) {
    return false;
  }
  
  return true;
}

bool CollisionDetector::collide(const Segment&s, const AABB& a) {
  const Point sA(s.a());
  const Point sB(s.b());
  
  // If one of the extremum of the segment is in the AABB.
  if(collide(sA, a) || collide(sB, a)) {
    return true;
  }
  
  // Otherwise, we have to test collision between the segment and the AABB edges.
  const s32& x = a.o()[0];
  const s32& y = a.o()[1];
  const s32& w = a.w();
  const s32& h = a.h();
  
  const Segment aLeft(x, y, x, y+h);
  if(collide(aLeft, s)) {
    return true;
  }
  
  const Segment aRight(x + w, y, x + w, y + h);
  if(collide(aRight, s)) {
    return true;
  }
  
  const Segment aBottom(x, y, x + w, y);
  if(collide(aBottom, s)) {
    return true;
  }
  
  const Segment aTop(x, y + h, x + w, y + h);
  if(collide(aTop, s)) {
    return true;
  }
  
  return false;
}

bool CollisionDetector::collide(const Circle& c, const AABB& a) {
  const Point O(c.centre());
  if(collide(O, a)) { // If the centre of the circle is within the AABB.
    return true;
  }
  
  const s32& x = a.o()[0];
  const s32& y = a.o()[1];
  const s32& w = a.w();
  const s32& h = a.h();
  
  const Segment aLeft(x, y, x, y+h);
  if(collide(aLeft, c)) {
    return true;
  }
  
  const Segment aRight(x + w, y, x + w, y + h);
  if(collide(aRight, c)) {
    return true;
  }
  
  const Segment aBottom(x, y, x + w, y);
  if(collide(aBottom, c)) {
    return true;
  }
  
  const Segment aTop(x, y + h, x + w, y + h);
  if(collide(aTop, c)) {
    return true;
  }
  
  return false;
}

bool CollisionDetector::collide(const AABB& a1, const AABB& a2) {
  s32 x = a1.o()[0];
  s32 y = a1.o()[1];
  s32 w = a1.w();
  s32 h = a1.h();
  
  Point P(x, y);
  if(collide(P, a2)) {
    return true;
  }
  
  P = Point(x + w, y);
  if(collide(P, a2)) {
    return true;
  }
  
  P = Point(x, y + h);
  if(collide(P, a2)) {
    return true;
  }
  
  P = Point(x + w, y + h);
  if(collide(P, a2)) {
    return true;
  }
  
  x = a2.o()[0];
  y = a2.o()[1];
  w = a2.w();
  h = a2.h();
  
  P = Point(x, y);
  if(collide(P, a1)) {
    return true;
  }
  
  P = Point(x + w, y);
  if(collide(P, a1)) {
    return true;
  }
  
  P = Point(x, y + h);
  if(collide(P, a1)) {
    return true;
  }
  
  P = Point(x + w, y + h);
  if(collide(P, a1)) {
    return true;
  }
  
  return false;
}
