#ifndef AVR_RANDOM_ACCESS_STREAM_HPP
#define AVR_RANDOM_ACCESS_STREAM_HPP

#include "../../../common/device/stream/random_access_stream.hpp"

inline RandomAccessStream::RandomAccessStream(const char* name) : Stream(name) {}

inline u16 RandomAccessStream::cursor(void) {
  return _cursor;
}

inline void RandomAccessStream::seek(u16 cursor) {
  _cursor = cursor;
}

#endif//AVR_RANDOM_ACCESS_STREAM_HPP
