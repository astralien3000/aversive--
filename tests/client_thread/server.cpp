#include <iostream>
#include <cstring>
#include <QLocalServer>
#include <QThread>
#include <QLocalSocket>
#include <QByteArray>
#include <QDebug>

#define BUFFER_SIZE 1024
#define CLI_ID "MyAwesomeRobot"

void get_next_msg(QLocalSocket* sck, char* buffer){
  qint64 read;
  while(1) {
    read = sck->readLine(buffer, (qint64) BUFFER_SIZE);
    if(read == 0) {
      QThread::msleep(10);
    }
    else if(read == -1) {
      qDebug() << "Problem occured while receiving a new message";
      *buffer = '\0';
      break;
    }
    else {
      break;
    }
  }
}

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  QLocalServer srv;
  char buffer[BUFFER_SIZE];
  
  srv.removeServer("SASIAE-SRV");
  if(!srv.listen("SASIAE-SRV")) {
    qDebug() << "Error msg: " << srv.errorString();
    return 1;
  }
  
  std::cout << "Waiting for the client to connect" << std::endl;
  if(!srv.waitForNewConnection(5000)) {
    std::cout << "No one tried to connect within 5 seconds" << std::endl;
    srv.close();
    return 0;
  }
  
  QLocalSocket* sck = srv.nextPendingConnection();
  std::cout << "Client is now connected" << std::endl;
  
  get_next_msg(sck, buffer);
  if(strcmp(buffer, "Hello " CLI_ID "\n") == 0) {
    std::cout << "[OK] Client said hello properly" << std::endl;
  }
  else {
    std::cout << "[NO] Client didn't say hello properly" << std::endl;
    std::cout << "It said instead: " << buffer << std::endl;
  }
  
  get_next_msg(sck, buffer);
  if(strcmp(buffer, "TESTER I'm new\n") == 0) {
    std::cout << "[OK] Client declared TESTER device properly" << std::endl;
  }
  else {
    std::cout << "[NO] Client didn't declared TESTER device properly" << std::endl;
    std::cout << "It said instead: " << buffer << std::endl;
  }

  sck->write("TESTER well received!\n");
  sck->flush();
  
  sck->write("TESTER let me test a bit more.\n");
  sck->flush();
  
  sck->write("WhatAboutThat,DoYouLike?YouShouldn't!\n");
  sck->flush();

  get_next_msg(sck, buffer);
  if(strcmp(buffer, "Error impossible to detect device's name\n") == 0) {
    std::cout << "[OK] Client said impossible to detect device's name properly" << std::endl;
  }
  else {
    std::cout << "[NO] Client didn't say impossible to detect device's name properly" << std::endl;
    std::cout << "It said instead: " << buffer << std::endl;
  }
  
  sck->write("42 Do you know that one?\n");
  sck->flush();
  
  get_next_msg(sck, buffer);
  if(strcmp(buffer, "Error unknown \"42\" device\n") == 0) {
    std::cout << "[OK] Client said unknown device properly" << std::endl;
  }
  else {
    std::cout << "[NO] Client didn't say unknown device properly" << std::endl;
    std::cout << "It said instead: " << buffer << std::endl;
  }
  
  sck->write("TESTER Stop\n");
  sck->flush();

  get_next_msg(sck, buffer);
  if(strcmp(buffer, "Bye\n") == 0) {
    std::cout << "[OK] Client said bye properly" << std::endl;
  }
  else {
    std::cout << "[NO] Client didn't say bye properly" << std::endl;
    std::cout << "It said instead: " << buffer << std::endl;
  }
  
  sck->disconnectFromServer();
  sck->close();
  srv.close();
  
  return 0;
}
