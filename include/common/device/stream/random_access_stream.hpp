#ifndef RANDOM_ACCESS_STREAM
#define RANDOM_ACCESS_STREAM

#include <device/stream/stream.hpp>

//! \class RandomAccessStream random_access_stream.hpp <device/stream/random_access_device.hpp>
//! \brief Abstract random access stream.
class RandomAccessStream : public Stream {
private:
  //! \brief The current position of the stream's reader head.
  volatile u16 _cursor = 0;
  
public:
  //! \brief Default constructor.
  inline RandomAccessStream(void)
    : Stream() {
  }
  
  //! \brief Copy constructor.
  //! \param s : the stream to copy.
  inline RandomAccessStream(const RandomAccessStream& s)
    : Stream(s), _cursor(s._cursor) {
  }
  
  //! \brief Place the cursor at a given position.
  //! \param pos : the new cursor's position.
  inline void seek(u16 pos) {
    _cursor = pos;
  }
  
  //! \brief Move the cursor by a given offset.
  //! \param offset : the offset to move the cursor with.
  inline void move(s16 offset) {
    _cursor += offset;
  }
  
  //! \brief Return the current cursor's position.
  //! \return The cursor's position.
  inline u16 cursor(void) const {
    return _cursor;
  }
};

#endif//RANDOM_ACCESS_STREAM
