#include <QThread>
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
  client.start("./client", QStringList());
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
