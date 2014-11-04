#include <iostream>
#include <cstdlib>
#include "../../../my_assert.hpp"

#include <geometry/world.hpp>

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Point p1(3, 2);
  Point p3(5, 2);
  
  Segment s1(0, 6, 4, 0);
  Segment s2(-3, 5, 4, 5);
  
  Circle c1(1, 1, 3);
  
  AABB a1(7, 4, 5, 3);
  AABB a2(-4, 1, 3, 2);
  AABB a3(8, 5, 3, 1);
  
  Triangle t1(-1, 7, 2, 7, -1, 4);
  
  World<10, AABB> myw;
  
  myAssert(myw.usedSpace() == 0, "Line " S__LINE__ ": World<SIZE, AABB>::usedSpace(void)");
  myAssert(myw.addShape(&p1), "Line " S__LINE__ ": World<SIZE, AABB>::addShape(Shape*)");
  myAssert(myw.usedSpace() == 1, "Line " S__LINE__ ": World<SIZE, AABB>::usedSpace(void)");
  myAssert(myw.addShape(&s1), "Line " S__LINE__ ": World<SIZE, AABB>::addShape(Shape*)");
  myAssert(myw.addShape(&s2), "Line " S__LINE__ ": World<SIZE, AABB>::addShape(Shape*)");
  myAssert(myw.usedSpace() == 3, "Line " S__LINE__ ": World<SIZE, AABB>::usedSpace(void)");
  myAssert(myw.addShape(&p3), "Line " S__LINE__ ": World<SIZE, AABB>::addShape(Shape*)");
  myAssert(myw.usedSpace() == 4, "Line " S__LINE__ ": World<SIZE, AABB>::usedSpace(void)");
  myAssert(myw.removeShape(&p3), "Line " S__LINE__ ": World<SIZE, AABB>::removeShape(Shape*)");
  myAssert(myw.usedSpace() == 3, "Line " S__LINE__ ": World<SIZE, AABB>::usedSpace(void)");
  myAssert(myw.collide(c1), "Line " S__LINE__ ": World<SIZE, AABB>::collide(const Shape&)");
  myAssert(!myw.collide(p3), "Line " S__LINE__ ": World<SIZE, AABB>::collide(const Shape&)");
  myAssert(myw.addShape(&a1), "Line " S__LINE__ ": World<SIZE, AABB>::addShape(Shape*)");
  myAssert(myw.addShape(&c1), "Line " S__LINE__ ": World<SIZE, AABB>::addShape(Shape*)");
  myAssert(myw.collide(a2), "Line " S__LINE__ ": World<SIZE, AABB>::collide(const Shape&)");
  myAssert(myw.collide(a3), "Line " S__LINE__ ": World<SIZE, AABB>::collide(const Shape&)");
  myAssert(!myw.collide(t1), "Line " S__LINE__ ": World<SIZE, AABB>::collide(const Shape&)");
  myAssert(!myw.removeShape(&t1), "Line " S__LINE__ ": World<SIZE, AABB>::removeShape(Shape*)");
  
  std::cout << "OK" << std::endl;  
  return EXIT_SUCCESS;
}
