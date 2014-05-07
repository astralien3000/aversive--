#ifndef IDENTIFIER_HPP
#define IDENTIFIER_HPP

#include <string>
#include <sstream>

class Identifier {
private:
  bool _templated;
  int _val;
  std::string _str;

public:
  inline Identifier(std::string str) {
    _templated = false;
    _val = 0;
    _str = str;
  }

  inline Identifier(std::string str, int val) {
    _templated = true;
    _val = val;
    _str = str;
  }

  inline Identifier(int val) {
    _templated = true;
    _val = val;
    _str = std::string("value");
  }


  std::string name(void) {
    if(_templated) {
      std::stringstream oss;
      oss << _str << "<" << _val << ">";
      return oss.str();
    }
    return _str;
  }
  
  std::string rawName(void) {
    return _str;
  }

  bool isTemplate(void) {
    return _templated;
  }
};

#endif//IDENTIFIER_HPP
