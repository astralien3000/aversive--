#include <QProcess>
#include <iostream>
#include "../../my_assert.hpp"
#include "../util.hpp"

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  QProcess client;
  client.start("./client.elf", QStringList());
  if(!client.waitForStarted()) {
    myAssert(false, "Line " S__LINE__ ": The client could not be initialized properly.");
  }
  
  myAssert(checkMsg(client, "D TESTER I'm new"), "Line " S__LINE__ ": The first message is not the device declaration.");
  
  client.write("D TESTER Stop\n");
  
  myAssert(checkMsg(client, "D TESTER Stop? :'("), "Line " S__LINE__ ": The device did not answer properly.");
  myAssert(checkMsg(client, "S"), "Line " S__LINE__ ": The client thread did not send \"S\" as expected.");
  
  client.write("D TESTER Love u\n");
  
  myAssert(checkMsg(client, "D TESTER Love u too"), "Line " S__LINE__ ": The device did not answer properly.");
  
  client.write("S\n");
  client.closeWriteChannel();
  
  if(!client.waitForFinished()) {
    myAssert(false, "Line " S__LINE__ ": The client did not close properly.");
  }
  
  std::cout << "OK" << std::endl;
  return 0;
}
