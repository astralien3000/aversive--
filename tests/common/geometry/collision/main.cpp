#include <iostream>
#include <cstdlib>
#include "../../../my_assert.hpp"

#include <geometry/collision.hpp>

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Point p1(3, 2);
  Point p2(3, 2);
  Point p3(5, 2);
  Point p4(0, 2);
  Point p5(1, 5);
  Point p6(8, 5);
  Point p7(359,248);
  Point p8(-3, 6);
  Point p9(7, 5);
  Point p10(0, 5);
  Point p11(0, 6);
  Point p12(-7, 1);
  Point p13(-7, 2);
  Point p14(4, 1);
  Point p15(0 ,0);
  Point p16(0, 1);
  
  Segment s1(0, 6, 4, 0);
  Segment s2(-3, 5, 4, 5);
  Segment s3(-3, 6, -4, 7);
  Segment s4(7, 8, 7, 3);
  Segment s5(7, 8, 12, 3);
  Segment s6(-3, 5, -6, 5);
  Segment s7(-4, 5, -2, 5);
  Segment s8(10, 6, 12, 8);
  Segment s9(0, 5, 0, 6);
  Segment s10(-7, 2, -6, 4);
  Segment s11(-8, 4, -6, 1);
  Segment s12(-1, 1, 1, 1);
  Segment s13(1, 1, 1, -1);
  Segment s14(1, -1, -1, -1);
  Segment s15(-1, -1, -1, 1);
  
  Circle c1(1, 1, 3);
  Circle c2(7, 4, 7);
  Circle c3(-4, 2, 2);
  Circle c4(-3, 1, 1);
  Circle c5(-3, 2, 1);
  Circle c6(-4, 5, 1);
  
  AABB a1(7, 4, 5, 3);
  AABB a2(-4, 1, 3, 2);
  AABB a3(8, 5, 3, 1);
  AABB a4(-2, 2, 2, 2);
  
  Triangle t1(-1, 7, 2, 7, -1, 4);
  Triangle t2(-6, 7, 0, 7, -6, 0);
  
  Quadrilateral q1(-8, 2, -6, 6, -5, 5, -7, 1);
  Quadrilateral q2(-4, 7, 0, 5, -5, 1, -7, 4);
  
  // Point/Point collisions
  myAssert(CollisionDetector::collide(p1, p2), "Line " S__LINE__ ": Point/Point collision.");
  myAssert(!CollisionDetector::collide(p1, p3), "Line " S__LINE__ ": Point/Point collision.");
  
  // Point/Segment collisions
  myAssert(CollisionDetector::collide(s2, p5), "Line " S__LINE__ ": Point/Segment collision.");
  myAssert(CollisionDetector::collide(s12, p16), "Line " S__LINE__ ": Point/Segment collision.");
  myAssert(!CollisionDetector::collide(s2, p6), "Line " S__LINE__ ": Point/Segment collision.");
  myAssert(!CollisionDetector::collide(s2, p7), "Line " S__LINE__ ": Point/Segment collision.");
  myAssert(!CollisionDetector::collide(s2, p8), "Line " S__LINE__ ": Point/Segment collision.");
  myAssert(!CollisionDetector::collide(s12, p15), "Line " S__LINE__ ": Point/Segment collision.");
  myAssert(!CollisionDetector::collide(s13, p15), "Line " S__LINE__ ": Point/Segment collision.");
  myAssert(!CollisionDetector::collide(s14, p15), "Line " S__LINE__ ": Point/Segment collision.");
  myAssert(!CollisionDetector::collide(s15, p15), "Line " S__LINE__ ": Point/Segment collision.");
  
  // Point/Circle collisions
  myAssert(CollisionDetector::collide(c1, p4), "Line " S__LINE__ ": Point/Circle collision.");
  myAssert(!CollisionDetector::collide(c1, p3), "Line " S__LINE__ ": Point/Circle collision.");
  myAssert(!CollisionDetector::collide(c1, p14), "Line " S__LINE__ ": Point/Circle collision.");
  
  // Point/AABB collisions
  myAssert(CollisionDetector::collide(a1, p6), "Line " S__LINE__ ": Point/AABB collision.");
  myAssert(!CollisionDetector::collide(a1, p7), "Line " S__LINE__ ": Point/AABB collision.");
  myAssert(!CollisionDetector::collide(a1, p9), "Line " S__LINE__ ": Point/AABB collision.");
  
  // Point/Triangle collisions
  myAssert(CollisionDetector::collide(t1, p11), "Line " S__LINE__ ": Point/Triangle collision.");
  myAssert(!CollisionDetector::collide(t1, p10), "Line " S__LINE__ ": Point/Triangle collision.");
  myAssert(!CollisionDetector::collide(t1, p1), "Line " S__LINE__ ": Point/Triangle collision.");
  
  // Point/Quadrilateral collisions
  myAssert(CollisionDetector::collide(q1, p13), "Line " S__LINE__ ": Point/Quadrilateral collision.");
  myAssert(!CollisionDetector::collide(q1, p9), "Line " S__LINE__ ": Point/Quadrilateral collision.");
  myAssert(!CollisionDetector::collide(q1, p12), "Line " S__LINE__ ": Point/Quadrilateral collision.");
  
  // Segment/Segment collisions
  myAssert(CollisionDetector::collide(s1, s2), "Line " S__LINE__ ": Segment/Segment collision.");
  myAssert(!CollisionDetector::collide(s2, s3), "Line " S__LINE__ ": Segment/Segment collision.");
  myAssert(!CollisionDetector::collide(s2, s6), "Line " S__LINE__ ": Segment/Segment collision.");
  myAssert(!CollisionDetector::collide(s6, s7), "Line " S__LINE__ ": Segment/Segment collision.");
  
  // Segment/Circle collisions
  myAssert(CollisionDetector::collide(c1, s1), "Line " S__LINE__ ": Segment/Circle collision.");
  myAssert(!CollisionDetector::collide(c1, s2), "Line " S__LINE__ ": Segment/Circle collision.");
  
  // Segment/AABB collisions
  myAssert(CollisionDetector::collide(a1, s5), "Line " S__LINE__ ": Segment/AABB collision.");
  myAssert(CollisionDetector::collide(a1, s8), "Line " S__LINE__ ": Segment/AABB collision.");
  myAssert(!CollisionDetector::collide(a1, s1), "Line " S__LINE__ ": Segment/AABB collision.");
  myAssert(!CollisionDetector::collide(a1, s2), "Line " S__LINE__ ": Segment/AABB collision.");
  myAssert(!CollisionDetector::collide(a1, s3), "Line " S__LINE__ ": Segment/AABB collision.");
  myAssert(!CollisionDetector::collide(a1, s4), "Line " S__LINE__ ": Segment/AABB collision.");
  
  // Segment/Triangle collisions
  myAssert(CollisionDetector::collide(t1, s1), "Line " S__LINE__ ": Segment/Triangle collision.");
  myAssert(CollisionDetector::collide(t1, s2), "Line " S__LINE__ ": Segment/Triangle collision.");
  myAssert(CollisionDetector::collide(t1, s9), "Line " S__LINE__ ": Segment/Triangle collision.");
  myAssert(!CollisionDetector::collide(t1, s3), "Line " S__LINE__ ": Segment/Triangle collision.");
  
  // Segment/Quadrilateral collisions
  myAssert(CollisionDetector::collide(q1, s6), "Line " S__LINE__ ": Segment/Quadrilateral collision.");
  myAssert(CollisionDetector::collide(q1, s10), "Line " S__LINE__ ": Segment/Quadrilateral collision.");
  myAssert(CollisionDetector::collide(q1, s11), "Line " S__LINE__ ": Segment/Quadrilateral collision.");
  myAssert(!CollisionDetector::collide(q1, s3), "Line " S__LINE__ ": Segment/Quadrilateral collision.");
  
  // Circle/Circle collisions
  myAssert(CollisionDetector::collide(c1, c2), "Line " S__LINE__ ": Circle/Circle collision.");
  myAssert(!CollisionDetector::collide(c1, c3), "Line " S__LINE__ ": Circle/Circle collision.");
  myAssert(!CollisionDetector::collide(c1, c4), "Line " S__LINE__ ": Circle/Circle collision.");
  
  // Circle/AABB collisions
  myAssert(CollisionDetector::collide(a2, c1), "Line " S__LINE__ ": Circle/AABB collision.");
  myAssert(CollisionDetector::collide(a2, c3), "Line " S__LINE__ ": Circle/AABB collision.");
  myAssert(CollisionDetector::collide(a2, c4), "Line " S__LINE__ ": Circle/AABB collision.");
  myAssert(CollisionDetector::collide(a2, c5), "Line " S__LINE__ ": Circle/AABB collision.");
  myAssert(!CollisionDetector::collide(a2, c2), "Line " S__LINE__ ": Circle/AABB collision.");
  
  // Circle/Triangle collisions
  myAssert(CollisionDetector::collide(t1, c2), "Line " S__LINE__ ": Circle/Triangle collision.");
  myAssert(CollisionDetector::collide(t2, c3), "Line " S__LINE__ ": Circle/Triangle collision.");
  myAssert(CollisionDetector::collide(t2, c5), "Line " S__LINE__ ": Circle/Triangle collision.");
  myAssert(CollisionDetector::collide(t2, c6), "Line " S__LINE__ ": Circle/Triangle collision.");
  myAssert(!CollisionDetector::collide(t1, c1), "Line " S__LINE__ ": Circle/Triangle collision.");
  myAssert(!CollisionDetector::collide(t2, c2), "Line " S__LINE__ ": Circle/Triangle collision.");
  
  // Circle/Quadrilateral collisions
  myAssert(CollisionDetector::collide(q2, c3), "Line " S__LINE__ ": Circle/Quadrilateral collision.");
  myAssert(CollisionDetector::collide(q2, c5), "Line " S__LINE__ ": Circle/Quadrilateral collision.");
  myAssert(CollisionDetector::collide(q2, c6), "Line " S__LINE__ ": Circle/Quadrilateral collision.");
  myAssert(!CollisionDetector::collide(q2, c1), "Line " S__LINE__ ": Circle/Quadrilateral collision.");
  myAssert(!CollisionDetector::collide(q2, c2), "Line " S__LINE__ ": Circle/Quadrilateral collision.");
  myAssert(!CollisionDetector::collide(q2, c4), "Line " S__LINE__ ": Circle/Quadrilateral collision.");
  
  // AABB/AABB collisions
  myAssert(CollisionDetector::collide(a1, a3), "Line " S__LINE__ ": AABB/AABB collision.");
  myAssert(CollisionDetector::collide(a2, a4), "Line " S__LINE__ ": AABB/AABB collision.");
  myAssert(!CollisionDetector::collide(a1, a2), "Line " S__LINE__ ": AABB/AABB collision.");
  myAssert(!CollisionDetector::collide(a3, a4), "Line " S__LINE__ ": AABB/AABB collision.");
  
  std::cout << "OK" << std::endl;
  return EXIT_SUCCESS;
}
