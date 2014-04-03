#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <base/integer.hpp>

class Shape {
  u8 _shape_id;
  
protected:
  inline Shape(u8 shape_id)
    : _shape_id(shape_id) {
  }
  
public:
  static const u8 ID = 'u';
  
  inline Shape(void)
    : _shape_id(ID) {
  }
  
  inline u8 shapeId(void) const {
    return _shape_id;
  }
};

#endif//SHAPE_HPP
