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
  static bool collide(const Shape& s1, const Shape& s2);
  
  // Point's collision
  static bool collide(const Point& p, const Shape& s);
  static bool collide(const Point& p1, const Point& p2);
  static bool collide(const Point& p, const Segment& s);
  static bool collide(const Point& p, const Circle& c);
  static bool collide(const Point& p, const AABB& a);
  static bool collide(const Point& p, const Triangle& t);
  static bool collide(const Point& p, const Quadrilateral& q);
  
  // Segment's collision
  static bool collide(const Segment& s1, const Shape& s2);
  inline static bool collide(const Segment& s, const Point& p) {
    return collide(p, s);
  }
  static bool collide(const Segment& s1, const Segment& s2);
  static bool collide(const Segment& s, const Circle& c);
  static bool collide(const Segment& s, const AABB& a);
  static bool collide(const Segment& s, const Triangle& t);
  static bool collide(const Segment& s, const Quadrilateral& q);
  
  // Circle's collision
  static bool collide(const Circle& c, const Shape& s);
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
  static bool collide(const AABB& a, const Shape& s);
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
  static bool collide(const Triangle& t, const Shape& s);
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
  static bool collide(const Quadrilateral& q, const Shape& s);
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

#endif//COLLISION_HPP
