#include <QThread>
#include <QProcess>
#include <cstring>
#include <iostream>

#define BUFFER_SIZE 1024

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

void res(bool ok, int i = 0) {
  if(ok) {
    std::cout << "OK" << std::endl;
  }
  else {
    std::cout << "NOK " << i << std::endl;
  }
}

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;

  QProcess client;
  client.start("./client", QStringList());
  if(!client.waitForStarted()) {
    res(false, 1);
    return EXIT_FAILURE;
  }

  client.write("T 1 10\n");
  
  char buffer2[80];
  for(int i = 0; i < 10; i++) {
    sprintf(buffer2, "D TESTER value is %d", i);
    if(!checkMsg(client, buffer2)) {
      res(false, 2 + i);
      return EXIT_FAILURE;
    }
  }
  
  if(!checkMsg(client, "T")) {
    res(false, 12);
    return EXIT_FAILURE;
  }

  client.write("T 2 100\n");
  
  for(int i = 10; i < 110; i++) {
    sprintf(buffer2, "D TESTER value is %d", i);
    if(!checkMsg(client, buffer2)) {
      res(false, 13 + i);
      return EXIT_FAILURE;
    }
  }
  
  if(!checkMsg(client, "T")) {
    res(false, 113);
    return EXIT_FAILURE;
  }

  client.write("S\n");

  if(!checkMsg(client, "S")) {
    res(false, 114);
    return EXIT_FAILURE;
  }

  client.closeWriteChannel();
  
  if(!client.waitForFinished()) {
    res(false, 115);
    return EXIT_FAILURE;
  }

  res(true);
  return EXIT_SUCCESS;
}
