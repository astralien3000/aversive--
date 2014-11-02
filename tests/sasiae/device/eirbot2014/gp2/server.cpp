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
  
  myAssert(checkMsg(client, "D in init"), "Line " S__LINE__ ": The first message is not the device declaration.");  
  
  myAssert(checkMsg(client, "in value 0"), "Line " S__LINE__ ": The initial value is not 0.");  
  
  client.write("D in value 200\n");
  client.write("T 1 1\n");
  
  myAssert(checkMsg(client, "in value 200"), "Line " S__LINE__ ": The value did not get properly set to 200 as expected.");  
  
  client.write("S\n");
  client.closeWriteChannel();
  myAssert(client.waitForFinished(), "Line " S__LINE__ ": The client did not close properly.");
  
  std::cout << "OK" << std::endl;
  return 0;
}
