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
  
  if(!checkMsg(client, "D rds mode cartesian")) {
    res(false, 2);
    return EXIT_FAILURE;
  }

  client.write("D rds values 2 1 20 300 4000\n");
  client.write("T 1 1\n");

  if(!checkMsg(client, "robots number 2")) {
    res(false, 3);
    return EXIT_FAILURE;
  }

  if(!checkMsg(client, "robots[0] 1 20")) {
    res(false, 4);
    return EXIT_FAILURE;
  }

  if(!checkMsg(client, "robots[1] 300 4000")) {
    res(false, 5);
    return EXIT_FAILURE;
  }

  if(!checkMsg(client, "D rds mode polar")) {
    res(false, 6);
    return EXIT_FAILURE;
  }

  if(!checkMsg(client, "T")) {
    res(false, 7);
    return EXIT_FAILURE;
  }

  client.write("D rds values 2 1 20 300 4000\n");
  client.write("T 1 1\n");

  if(!checkMsg(client, "robots number 2")) {
    res(false, 8);
    return EXIT_FAILURE;
  }

  if(!checkMsg(client, "robots[0] 1 20")) {
    res(false, 9);
    return EXIT_FAILURE;
  }

  if(!checkMsg(client, "robots[1] 300 4000")) {
    res(false, 10);
    return EXIT_FAILURE;
  }

  client.write("S\n");
  client.closeWriteChannel();
  
  if(!client.waitForFinished()) {
    res(false, 5);
    return EXIT_FAILURE;
  }

  res(true);
  return EXIT_SUCCESS;
}
