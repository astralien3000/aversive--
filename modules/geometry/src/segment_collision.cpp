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

bool CollisionDetector::collide(const Point& p, const Segment& s) {
  const Vect<2, s32>& A = s.a();
  const Vect<2, s32>& B = s.b();
  
  // If the crossproduct is strictly positive, the three points are not aligned.
  if(((p.y() - A[1]) * (B[0] - A[0]) - (p.x() - A[0]) * (B[1] - A[1])) != 0) {
    return false;
  }
  
  // Dot product of B-A and C-A
  const s32 dot_product = (p.x() - A[0]) * (B[0] - A[0]) + (p.x() - A[0]) * (B[1] - A[1]);
  if(dot_product <= 0) {
    return false;
  }
  
  const s32 squared_delta_AB = (B[0] - A[0]) * (B[0] - A[0]) + (B[1] - A[1]) * (B[1] - A[1]);
  if(dot_product >= squared_delta_AB) {
    return false;
  }
  
  return true;
}

bool CollisionDetector::collide(const Segment& s1, const Segment& s2) {
  const Vect<2, s32>& A = s1.a();
  const Vect<2, s32>& B = s1.b();
  const Vect<2, s32>& O = s2.a();
  const Vect<2, s32>& P = s2.b();
  
  // We test collision between [AB] and (OP)
  const Vect<2, s32> AO(O[0] - A[0], O[1] - A[1]);
  const Vect<2, s32> AP(P[0] - A[0], P[1] - A[1]);
  const Vect<2, s32> AB(B[0] - A[0], B[1] - A[1]);
  if((AB[0] * AP[1] - AB[1] * AP[0]) * (AB[0] * AO[1] - AB[1] * AO[0]) >= 0) {
    return false;
  }
  
  // We test collision between [OP] and (AB)
  const Vect<2, s32> OA(A[0] - O[0], A[1] - O[1]);
  const Vect<2, s32> OB(B[0] - O[0], B[1] - O[1]);
  const Vect<2, s32> OP(P[0] - O[0], P[1] - O[1]);
  if((OP[0] * OB[1] - OP[1] * OB[0]) * (OP[0] * OA[1] - OP[1] * OA[0]) >= 0) {
    return false;
  }
  
  return true;
}
