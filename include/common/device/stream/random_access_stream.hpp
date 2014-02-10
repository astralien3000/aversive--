#ifndef RANDOM_ACCESS_STREAM
#define RANDOM_ACCESS_STREAM

#include <device/stream/stream.hpp>

class RandomAccessStream : public Stream {
private:
  volatile u16 _cursor = 0;
  
protected:
  //! \brief gives the cursor's position
  inline u16 cursor(void) {
    return _cursor;
  }

public:
  //! \brief Default Constructor
  inline RandomAccessStream(const char* name) : Stream(name) {}

  //! \brief Place the cursor at the position
  inline void seek(u16 cursor) {
    _cursor = cursor;
  }
};

#endif//RANDOM_ACCESS_STREAM
