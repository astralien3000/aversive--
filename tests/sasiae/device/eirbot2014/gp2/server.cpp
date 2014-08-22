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

  if(!checkMsg(client, "D in init")) {
    res(false, 2);
    return EXIT_FAILURE;
  }

  if(!checkMsg(client, "in value 0")) {
    res(false, 3);
    return EXIT_FAILURE;
  }

  client.write("D in value 200\n");
  client.write("T 1 1\n");

  if(!checkMsg(client, "in value 200")) {
    res(false, 3);
    return EXIT_FAILURE;
  }

  client.write("S\n");
  client.closeWriteChannel();
  
  if(!client.waitForFinished()) {
    res(false, 4);
    return EXIT_FAILURE;
  }

  res(true);
  return EXIT_SUCCESS;
}
