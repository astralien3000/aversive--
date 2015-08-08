#include <QProcess>
#include <iostream>
#include "../../../../my_assert.hpp"
#include "../../../util.hpp"

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  QProcess client;
  client.start("./client.elf", QStringList());
  myAssert(client.waitForStarted(), "Line " S__LINE__ ": The client could not be initialized properly.");
  
  myAssert(checkMsg(client, "D io init"), "Line " S__LINE__ ": The first message is not the device declaration.");
  
  client.write("D io value 10\n");
  client.write("T 1 1\n");

  myAssert(checkMsg(client, "D io value 11"), "Line " S__LINE__ ": The device did not answer properly.");
  myAssert(checkMsg(client, "T"), "Line " S__LINE__ ": The device did not answer properly.");
    
  client.write("S\n");
  client.closeWriteChannel();
  myAssert(client.waitForFinished(), "Line " S__LINE__ ": The client did not close properly.");
  
  std::cout << "OK" << std::endl;
  return 0;
}
