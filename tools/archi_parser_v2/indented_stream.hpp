#ifndef INDENTED_STREAM_HPP
#define INDENTED_STREAM_HPP

#include <ostream>

class indented_stream {
private:
  int _indent_level = 0;
  bool _new_line = true;
  std::ostream& _out;

public:
  indented_stream(std::ostream& other) : _out(other) {
  }

  int& indentLevel(void) {
    return _indent_level;
  }

  template<typename T>
  indented_stream& operator<<(const T& val) {
    if(_new_line) {
      for(int i = 0 ; i < _indent_level ; i++) {
	_out << "  ";
      }
      _new_line = false;
    }
    _out << val;

    return *this;
  }

  template<typename T>
  indented_stream& operator<<(T& val) {
    return *this << (const T&)val;
  }

  indented_stream& operator<<(std::ostream& val(std::ostream&)) {
    _new_line = true;
    _out << val;

    return *this;
  }
};

#endif//INDENTED_STREAM_HPP
