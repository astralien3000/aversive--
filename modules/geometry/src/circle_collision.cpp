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

bool CollisionDetector::collide(const Point& p, const Circle& c) {
  if(((p.x() - c.centre()[0]) * (p.x() - c.centre()[0]) + // square delta x
      (p.y() - c.centre()[1]) * (p.y() - c.centre()[1])) // square delta y
     >= (c.radius() * c.radius())) {
    return false;
  }
  else {
    return true;
  }
}

bool CollisionDetector::collide(const Segment& s, const Circle& c) {
  if(collide(Point(s.a()), c) || collide(Point(s.b()), c)) { // One of the extremums of the segment is in the circle.
    return true;
  }
  
  const Vect<2, s32>& A = s.a();
  const Vect<2, s32>& B = s.b();
  const Vect<2, s32>& C = c.centre();
  const s32& r = c.radius();
  
  // Does the line defined with s at least collides with c.
  const Vect<2, s32> u(B[0] - A[0], B[1] - A[1]);
  const Vect<2, s32> AC(C[0] - A[0], C[1] - A[1]);
  float numerator = u[0] * AC[1] - u[1] * AC[0];
  numerator *= numerator; // squared to avoid using sqrt on the divisor.
  float divisor = u[0] * u[0] + u[1] * u[1]; // square norm of u.
  float CI = numerator / divisor;
  if(CI >= static_cast<float>(r * r)) { // The line does not collide with the circle.
    return false;
  }
  
  // So we know the line collides with c, but does s collide too ?
  const Vect<2, s32> AB(B[0] - A[0], B[1] - A[1]);
  // AC has already been computed.
  const Vect<2, s32> BC(C[0] - B[0], C[1] - B[1]);
  float scal1 = AB[0] * AC[0] + AB[1] * AC[1];
  float scal2 = -AB[0] * BC[0] - AB[1] * BC[1];
  if(scal1 >= 0.f && scal2 >= 0.f) {
    return true;
  }
  
  return false;
}

bool CollisionDetector::collide(const Circle& c1, const Circle& c2) {
  if(((c1.centre()[0] - c2.centre()[0]) * (c1.centre()[0] - c2.centre()[0]) + // square delta x
      (c1.centre()[1] - c2.centre()[1]) * (c1.centre()[1] - c2.centre()[1])) // square delta y
     >= ((c1.radius() + c2.radius()) * (c1.radius() + c2.radius()))) {
    return false;
  }
  else {
    return true;
  }
}
