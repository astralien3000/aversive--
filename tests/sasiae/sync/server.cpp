#include <QProcess>
#include <cstring>
#include <iostream>
#include "../../my_assert.hpp"

static constexpr int BUFFER_SIZE = 1024;

char buffer[BUFFER_SIZE];

bool readLine(QProcess& client) {
  unsigned int i = 0;
  char c;
  if(!client.getChar(&c)) {
    client.waitForReadyRead();
  }
  else {
    buffer[i++] = c;
  }
  
  while(client.getChar(&c) && c != '\n') {
    buffer[i++] = c;
  }
  buffer[i] = '\0';
  
  if(c == '\n') {
    return true;
  }
  else {
    client.kill();
    client.waitForFinished();
    return false;
  }
}

bool checkMsg(QProcess& client, const char* str) {
  if(!readLine(client)) {
    return false;
  }
  
  return !strcmp(buffer, str);
}

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  QProcess client;
  client.start("./client.elf", QStringList());
  if(!client.waitForStarted()) {
    myAssert(false, "Line " S__LINE__ ": The client could not be initialized properly.");
  }
  
  client.write("T 1 10\n");
  
  char buffer2[80];
  for(int i = 0; i < 10; i++) {
    sprintf(buffer2, "D TESTER value is %d", i);
    myAssert(checkMsg(client, buffer2), "Line " S__LINE__ ": Unexpected message.");
  }
  
  myAssert(checkMsg(client, "T"), "Line " S__LINE__ ": The client thread did not send \"T\" as expected.");
  
  client.write("T 2 100\n");
  
  for(int i = 10; i < 110; i++) {
    sprintf(buffer2, "D TESTER value is %d", i);
    myAssert(checkMsg(client, buffer2), "Line " S__LINE__ ": Unexpected message.");
  }
  
  myAssert(checkMsg(client, "T"), "Line " S__LINE__ ": The client thread did not send \"T\" as expected.");
  
  client.write("S\n");
  
  myAssert(checkMsg(client, "S"), "Line " S__LINE__ ": The client thread did not send \"S\" as expected.");
  
  client.closeWriteChannel();
  if(!client.waitForFinished()) {
    myAssert(false, "Line " S__LINE__ ": The client did not close properly.");
  }
  
  std::cout << "OK" << std::endl;
  return 0;
}
