#ifndef NODE_HPP
#define NODE_HPP

#include <string>
#include "indented_stream.hpp"

class Node {
public:
  virtual ~Node(void) {}

  virtual std::string name(void) = 0;
  virtual std::string fullName(void) = 0;

  virtual void declare(indented_stream&) = 0;
  virtual void define(indented_stream&) = 0;
  virtual void defineValue(indented_stream&) = 0;
};

#endif//NODE_HPP
