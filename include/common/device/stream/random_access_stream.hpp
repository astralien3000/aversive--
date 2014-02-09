#ifndef RANDOM_ACCESS_STREAM
#define RANDOM_ACCESS_STREAM

#include <device/stream/stream.hpp>

class RandomAccessStream : public Stream {
private:
  volatile u16 _cursor = 0;
  
protected:
  //! \brief gives the cursor's position
  u16 cursor(void);

public:
  //! \brief Default Constructor
  RandomAccessStream(const char*);

  //! \brief Place the cursor at the position
  void seek(u16);
};

#endif//RANDOM_ACCESS_STREAM
