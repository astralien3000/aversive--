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

  for(int i = 1 ; i <= 8 ; i++) {
    char buffer[80];
    sprintf(buffer, "T %d 0\n", (i * 10) + 1);
    client.write(buffer);

    client.waitForReadyRead();
    for(int id = 1 ; id <= 8 ; id++) {
      if(i % id == 0) {
        char buffer[80];
        sprintf(buffer, "D TESTER value %d", id);
        if(!checkMsg(client, buffer)) {
          res(false, i * 8 + id - 1);
          printf("%d %d", i, id);
          return EXIT_FAILURE;
        }
      }
    }

    if(!checkMsg(client, "T")) {
      res(false, 3);
      return EXIT_FAILURE;
    }
  }

  client.write("S\n");

  if(!checkMsg(client, "S")) {
    res(false, 9);
    return EXIT_FAILURE;
  }

  client.closeWriteChannel();
  
  if(!client.waitForFinished()) {
    res(false, 10);
    return EXIT_FAILURE;
  }

  res(true);
  return EXIT_SUCCESS;
}
