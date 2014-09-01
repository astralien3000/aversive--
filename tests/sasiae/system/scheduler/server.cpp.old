#include <QProcess>
#include <iostream>
#include "../../../my_assert.hpp"
#include "../../util.hpp"

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  QProcess client;
  client.start("./client.elf", QStringList());
  myAssert(client.waitForStarted(), "Line " S__LINE__ ": The client could not be initialized properly.");
  
  client.write("T 11 0\n");
  
  myAssert(checkMsg(client, "D TESTER value 1"), "Line " S__LINE__ ": Unexpected message.");
  
  myAssert(checkMsg(client, "D TESTER value 2"), "Line " S__LINE__ ": Unexpected message.");
  
  myAssert(checkMsg(client, "T"), "Line " S__LINE__ ": The client thread did not send \"T\" as expected.");
  
  client.write("T 31 0\n");
  
  for(int i = 0 ; i < 2 ; i++) {
    myAssert(checkMsg(client, "D TESTER value 1"), "Line " S__LINE__ ": Unexpected message.");
    myAssert(checkMsg(client, "D TESTER value 2"), "Line " S__LINE__ ": Unexpected message.");
  }
  
  myAssert(checkMsg(client, "T"), "Line " S__LINE__ ": The client thread did not send \"T\" as expected.");
  
  client.write("S\n");
  
  myAssert(checkMsg(client, "S"), "Line " S__LINE__ ": The client thread did not send \"S\" as expected.");
  
  client.closeWriteChannel();
  myAssert(client.waitForFinished(), "Line " S__LINE__ ": The client did not close properly.");
  
  std::cout << "OK" << std::endl;
  return 0;
}
