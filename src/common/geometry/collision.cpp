#include <base/integer.hpp>
#include <geometry/collision.hpp>

bool CollisionDetector::collide(const Shape& s1, const Shape& s2) {
  if(s1.shapeId() == Point::ID) {
    return collide(*reinterpret_cast<const Point*>(&s1), s2);
  }
  else if(s1.shapeId() == Segment::ID) {
    return collide(*reinterpret_cast<const Segment*>(&s1), s2);
  }
  else if(s1.shapeId() == Circle::ID) {
    return collide(*reinterpret_cast<const Circle*>(&s1), s2);
  }
  else if(s1.shapeId() == AABB::ID) {
    return collide(*reinterpret_cast<const AABB*>(&s1), s2);
  }
  else if(s1.shapeId() == Triangle::ID) {
    return collide(*reinterpret_cast<const Triangle*>(&s1), s2);
  }
  else if(s1.shapeId() == Quadrilateral::ID) {
    return collide(*reinterpret_cast<const Quadrilateral*>(&s1), s2);
  }
  return false;
}

bool CollisionDetector::collide(const Point& p, const Shape& s) {
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

bool CollisionDetector::collide(const Point& p1, const Point& p2) {
  return p1 == p2;
}

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

bool CollisionDetector::collide(const Point& p, const Quadrilateral& q) {
  for(u8 i = 0; i < 4; i++) {
    const Vect<2, s32>& A = q[i];
    const Vect<2, s32>& B = q[(i == 3) ? 0 : i + 1];
    
    const Vect<2, s32> AB(B[0] - A[0], B[1] - A[1]);
    const Vect<2, s32> AP(p.x() - A[0], p.y() - A[1]);
    
    s32 d = AB[0] * AP[1] - AB[1] * AP[0];
    if(d >= 0) { // If P is on the left of AB, P is outside
      return false;
    }
  }
  return true;
}

bool CollisionDetector::collide(const Segment& s1, const Shape& s2) {
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

bool CollisionDetector::collide(const Segment&s, const Quadrilateral& q) {
  const Point sA(s.a());
  const Point sB(s.b());
  
  // If one of the extremum of the segment is in the triangle.
  if(collide(sA, q) || collide(sB, q)) {
    return true;
  }
  
  for(u8 i = 0; i < 4; i++) {
    const Vect<2, s32>& A = q[i];
    const Vect<2, s32>& B = q[(i == 3) ? 0 : i + 1];
    
    const Segment AB(A, B);
    if(collide(s, AB)) {
      return true;
    }
  }
  return false;
}

bool CollisionDetector::collide(const Circle& c, const Shape& s) {
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

bool CollisionDetector::collide(const Circle& c, const Quadrilateral& q) {
    const Point O(c.centre());
  if(collide(O, q)) { // If the centre of the circle is within the quadrilateral.
    return true;
  }
  
  for(u8 i = 0; i < 4; i++) {
    const Vect<2, s32>& A = q[i];
    const Vect<2, s32>& B = q[(i == 3) ? 0 : i + 1];
    
    const Segment AB(A, B);
    if(collide(AB, c)) {
      return true;
    }
  }
  return false;
}

bool CollisionDetector::collide(const AABB& a, const Shape& s) {
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

//! \todo Implement!
bool CollisionDetector::collide(const AABB& a, const Triangle& t) {
  (void) a;
  (void) t;
  return false;
}

//! \todo Implement!
bool CollisionDetector::collide(const AABB& a, const Quadrilateral& q) {
  (void) a;
  (void) q;
  return false;
}

bool CollisionDetector::collide(const Triangle& t, const Shape& s) {
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

//! \todo Implement!
bool CollisionDetector::collide(const Triangle& t1, const Triangle& t2) {
  (void) t1;
  (void) t2;
  return false;
}

//! \todo Implement!
bool CollisionDetector::collide(const Triangle& t, const Quadrilateral& q) {
  (void) t;
  (void) q;
  return false;
}

bool CollisionDetector::collide(const Quadrilateral& q, const Shape& s) {
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

//! \todo Implement!
bool CollisionDetector::collide(const Quadrilateral& q1, const Quadrilateral& q2) {
  (void) q1;
  (void) q2;
  return false;
}
