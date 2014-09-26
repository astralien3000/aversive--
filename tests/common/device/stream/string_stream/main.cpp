#include <device/stream/string_stream.hpp>
#include <iostream>
#include <cstring>
#include <cstdio>
#include "../../../../my_assert.hpp"

static constexpr buffer_t SIZE = Buffer<>::MAX_SIZE;
static constexpr u64 BUFFER_SIZE = 1024;
static char buffer[BUFFER_SIZE] = { '\0' };
static constexpr s64 VALUE = 15;

static const char* const str1 = "Hello";
static const char* const str2 = "How are you?";

template<int BIT>
void integerTester(StringStream<SIZE>& stream) {
  stream.setMode(Stream::FORMATTED);
  
  stream << "   " << (typename Integer<BIT>::Unsigned) VALUE << " ";
  typename Integer<BIT>::Unsigned a;
  stream >> a;
  snprintf(buffer, BUFFER_SIZE, "Line " S__LINE__ ": StringStream formatted u%d read and write", BIT);
  myAssert(a == (typename Integer<BIT>::Unsigned) VALUE, buffer);
  
  stream << "   " << (typename Integer<BIT>::Signed) VALUE << " ";
  typename Integer<BIT>::Signed b;
  stream >> b;
  snprintf(buffer, BUFFER_SIZE, "Line " S__LINE__ ": StringStream formatted s%d read and write", BIT);
  myAssert(b == (typename Integer<BIT>::Signed) VALUE, buffer);
  
  stream.getValue();
  
  stream.setMode(Stream::BINARY);
  
  stream << (typename Integer<BIT>::Unsigned) VALUE;
  stream >> a;
  snprintf(buffer, BUFFER_SIZE, "Line " S__LINE__ ": StringStream binary u%d read and write", BIT);
  myAssert(a == (typename Integer<BIT>::Unsigned) VALUE, buffer);
  
  stream << (typename Integer<BIT>::Signed) VALUE;
  stream >> b;
  snprintf(buffer, BUFFER_SIZE, "Line " S__LINE__ ": StringStream binary s%d read and write", BIT);
  myAssert(b == (typename Integer<BIT>::Signed) VALUE, buffer);
}

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  StringStream<SIZE> stream;
  
  myAssert(stream.outputFreeSpace() == SIZE, "Line " S__LINE__ ": StringStream<SIZE>::outputFreeSpace");
  myAssert(stream.inputUsedSpace() == 0, "Line " S__LINE__ ": StringStream<SIZE>::inputUsedSpace");
  stream.setValue('a');
  
  myAssert(stream.outputFreeSpace() == SIZE - 1, "Line " S__LINE__ ": StringStream<SIZE>::outputFreeSpace");
  myAssert(stream.inputUsedSpace() == 1, "Line " S__LINE__ ": StringStream<SIZE>::inputUsedSpace");
  
  char a = stream.getValue();
  myAssert(a == 'a',  "Line " S__LINE__ ": StringStream get and set value");
  myAssert(stream.outputFreeSpace() == SIZE, "Line " S__LINE__ ": StringStream<SIZE>::outputFreeSpace");
  myAssert(stream.inputUsedSpace() == 0, "Line " S__LINE__ ": StringStream<SIZE>::inputUsedSpace");
  
  integerTester<8>(stream);
  integerTester<16>(stream);
  integerTester<32>(stream);
  integerTester<64>(stream);
  
  myAssert(stream.outputFreeSpace() == SIZE, "Line " S__LINE__ ": StringStream<SIZE>::outputFreeSpace");
  myAssert(stream.inputUsedSpace() == 0, "Line " S__LINE__ ": StringStream<SIZE>::inputUsedSpace");
  
  stream.setMode(Stream::FORMATTED);
  stream.setSeparatorMode(FormattedStream::WORD);
  stream.setUserBufferSize(255);
  stream << "   " << str1 << "   " << str2 << "\n";
  
  stream >> buffer;
  myAssert(strcmp(str1, buffer) == 0, "Line " S__LINE__ ": StringStream fomatted word read and write");
  
  stream.setSeparatorMode(FormattedStream::LINE);
  stream >> buffer;
  myAssert(strcmp(str2, buffer) == 0, "Line " S__LINE__ ": StringStream formatted line read and write");
  
  myAssert(stream.outputFreeSpace() == SIZE, "Line " S__LINE__ ": StringStream<SIZE>::outputFreeSpace");
  myAssert(stream.inputUsedSpace() == 0, "Line " S__LINE__ ": StringStream<SIZE>::inputUsedSpace");
  
  std::cout << "OK" << std::endl;
  return 0;
}
