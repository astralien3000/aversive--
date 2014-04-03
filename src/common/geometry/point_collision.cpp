#include <base/integer.hpp>
#include <geometry/collision.hpp>

bool CollisionDetector::collide(const Point& p1, const Point& p2) {
  return p1 == p2;
}
