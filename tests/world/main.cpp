#include <iostream>
#include <cstdlib>
#include <cassert>

#include <geometry/world.hpp>
#include <geometry/collision.hpp>

inline void print(const char* str) {
  std::cout << str;
}

inline void println(const char* str) {
  std::cout << str << std::endl;
}

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
  print("Point/Point");
  assert(CollisionDetector::collide(p1, p2)); print(".");
  assert(!CollisionDetector::collide(p1, p3)); print(".");
  println("OK");
  
  // Point/Segment collisions
  print("Point/Segment");
  assert(CollisionDetector::collide(s2, p5)); print(".");
  assert(CollisionDetector::collide(s12, p16)); print(".");
  assert(!CollisionDetector::collide(s2, p6)); print(".");
  assert(!CollisionDetector::collide(s2, p7)); print(".");
  assert(!CollisionDetector::collide(s2, p8)); print(".");
  assert(!CollisionDetector::collide(s12, p15)); print(".");
  assert(!CollisionDetector::collide(s13, p15)); print(".");
  assert(!CollisionDetector::collide(s14, p15)); print(".");
  assert(!CollisionDetector::collide(s15, p15)); print(".");
  println("OK");
  
  // Point/Circle collisions
  print("Point/Circle");
  assert(CollisionDetector::collide(c1, p4)); print(".");
  assert(!CollisionDetector::collide(c1, p3)); print(".");
  assert(!CollisionDetector::collide(c1, p14)); print(".");
  println("OK");
  
  // Point/AABB collisions
  print("Point/AABB");
  assert(CollisionDetector::collide(a1, p6)); print(".");
  assert(!CollisionDetector::collide(a1, p7)); print(".");
  assert(!CollisionDetector::collide(a1, p9)); print(".");
  println("OK");
  
  // Point/Triangle collisions
  print("Point/Triangle");
  assert(CollisionDetector::collide(p11, t1)); print(".");
  assert(!CollisionDetector::collide(p10, t1)); print(".");
  assert(!CollisionDetector::collide(p1, t1)); print(".");
  println("OK");
  
  // Point/Quadrilateral collisions
  print("Point/Quadrilateral");
  assert(CollisionDetector::collide(p13, q1)); print(".");
  assert(!CollisionDetector::collide(p9, q1)); print(".");
  assert(!CollisionDetector::collide(p12, q1)); print(".");
  println("OK");
  
  // Segment/Segment collisions
  print("Segment/Segment");
  assert(CollisionDetector::collide(s1, s2)); print(".");
  assert(!CollisionDetector::collide(s2, s3)); print(".");
  assert(!CollisionDetector::collide(s2, s6)); print(".");
  assert(!CollisionDetector::collide(s6, s7)); print(".");
  println("OK");
  
  // Segment/Circle collisions
  print("Segment/Circle");
  assert(CollisionDetector::collide(c1, s1)); print(".");
  assert(!CollisionDetector::collide(c1, s2)); print(".");
  println("OK");
  
  // Segment/AABB collisions
  print("Segment/AABB");
  assert(CollisionDetector::collide(s5, a1)); print(".");
  assert(CollisionDetector::collide(s8, a1)); print(".");
  assert(!CollisionDetector::collide(s1, a1)); print(".");
  assert(!CollisionDetector::collide(s2, a1)); print(".");
  assert(!CollisionDetector::collide(s3, a1)); print(".");
  assert(!CollisionDetector::collide(s4, a1)); print(".");
  println("OK");
  
  // Segment/Triangle collisions
  print("Segment/Triangle");
  assert(CollisionDetector::collide(s1, t1)); print(".");
  assert(CollisionDetector::collide(s2, t1)); print(".");
  assert(CollisionDetector::collide(s9, t1)); print(".");
  assert(!CollisionDetector::collide(s3, t1)); print(".");
  println("OK");
  
  // Segment/Quadrilateral collisions
  print("Segment/Quadrilateral");
  assert(CollisionDetector::collide(s6, q1)); print(".");
  assert(CollisionDetector::collide(s10, q1)); print(".");
  assert(CollisionDetector::collide(s11, q1)); print(".");
  assert(!CollisionDetector::collide(s3, q1)); print(".");
  println("OK");
  
  // Circle/Circle collisions
  print("Circle/Circle");
  assert(CollisionDetector::collide(c1, c2)); print(".");
  assert(!CollisionDetector::collide(c1, c3)); print(".");
  assert(!CollisionDetector::collide(c1, c4)); print(".");
  println("OK");
  
  // Circle/AABB collisions
  print("Circle/AABB");
  assert(CollisionDetector::collide(c1, a2)); print(".");
  assert(CollisionDetector::collide(c3, a2)); print(".");
  assert(CollisionDetector::collide(c4, a2)); print(".");
  assert(CollisionDetector::collide(c5, a2)); print(".");
  assert(!CollisionDetector::collide(c2, a2)); print(".");
  println("OK");
  
  // Circle/Triangle collisions
  print("Circle/Triangle");
  assert(CollisionDetector::collide(c2, t1)); print(".");
  assert(CollisionDetector::collide(c3, t2)); print(".");
  assert(CollisionDetector::collide(c5, t2)); print(".");
  assert(CollisionDetector::collide(c6, t2)); print(".");
  assert(!CollisionDetector::collide(c1, t1)); print(".");
  assert(!CollisionDetector::collide(c2, t2)); print(".");
  println("OK");
  
  // Circle/Quadrilateral collisions
  print("Circle/Quadrilateral");
  assert(CollisionDetector::collide(c3, q2)); print(".");
  assert(CollisionDetector::collide(c5, q2)); print(".");
  assert(CollisionDetector::collide(c6, q2)); print(".");
  assert(!CollisionDetector::collide(c1, q2)); print(".");
  assert(!CollisionDetector::collide(c2, q2)); print(".");
  assert(!CollisionDetector::collide(c4, q2)); print(".");
  println("OK");
  
  // AABB/AABB collisions
  print("AABB/AABB");
  assert(CollisionDetector::collide(a1, a3)); print(".");
  assert(CollisionDetector::collide(a2, a4)); print(".");
  assert(!CollisionDetector::collide(a1, a2)); print(".");
  assert(!CollisionDetector::collide(a3, a4)); print(".");
  println("OK");
  
  // World collisions
  print("World");
  World<10, AABB> myw;
  assert(myw.usedSpace() == 0); print(".");
  assert(myw.addShape(&p1)); print(".");
  assert(myw.usedSpace() == 1); print(".");
  assert(myw.addShape(&s1)); print(".");
  assert(myw.addShape(&s2)); print(".");
  assert(myw.usedSpace() == 3); print(".");
  assert(myw.addShape(&p3)); print(".");
  assert(myw.usedSpace() == 4); print(".");
  assert(myw.removeShape(&p3)); print(".");
  assert(myw.usedSpace() == 3); print(".");
  assert(myw.collide(c1)); print(".");
  assert(!myw.collide(p3)); print(".");
  assert(myw.addShape(&a1)); print(".");
  assert(myw.addShape(&c1)); print(".");
  assert(myw.collide(a2)); print(".");
  assert(myw.collide(a3)); print(".");
  assert(!myw.collide(t1)); print(".");
  assert(!myw.removeShape(&t1)); print(".");
  println("OK");
  
  return EXIT_SUCCESS;
}
