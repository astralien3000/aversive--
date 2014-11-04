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
  char buffer[80];
  char buffer2[80];
  
  for(int i = 1 ; i <= 8 ; i++) {
    sprintf(buffer, "T %d 0\n", (i * 10) + 1);
    client.write(buffer);
    
    client.waitForReadyRead();
    for(int id = 1 ; id <= 8 ; id++) {
      if(i % id == 0) {
        sprintf(buffer, "D TESTER value %d", id);
        sprintf(buffer2, "Line " S__LINE__ ": Unexpected at i=%d and id=%d", i, id);
        myAssert(checkMsg(client, buffer), buffer2);
      }
    }
    
    myAssert(checkMsg(client, "T"), "Line " S__LINE__ ": The client thread did not send \"T\" as expected.");
  }
  
  client.write("S\n");
  myAssert(checkMsg(client, "S"), "Line " S__LINE__ ": The client thread did not send \"S\" as expected.");
  
  client.closeWriteChannel();
  myAssert(client.waitForFinished(), "Line " S__LINE__ ": The client did not close properly.");
  
  std::cout << "OK" << std::endl;
  return 0;
}
