#include <client_thread.hpp>
#include <cstdio>
#include <cstring>
#include <iostream>

#define DEFAULT_BUFFER_SIZE 64

//static const char* msg_hello = "Hello %s\n";
//static const char* msg_bye = "Bye\n";
//static const char* err_detect = "Error impossible to detect device's name\n";
//static const char* err_unknown = "Error unknown \"%s\" device\n";

ClientThread::ClientThread(void) : QThread() {
  _keep_going = true;
  _this = this;
  _buffer = new char[DEFAULT_BUFFER_SIZE];
  _length = DEFAULT_BUFFER_SIZE;
}

ClientThread::~ClientThread(void) {
  delete[] _buffer;
  _this = NULL;
}

// void ClientThread::run(void) {
//   char buffer[BUFFER_SIZE];
//   qint64 read;
//   char* name;
//   char* pos;
  
//   if(_id == 0) {
//     std::cerr << "Client ID hasn't been set" << std::endl;
//     _keep_going = false;
//     return;
//   }
  
//   _sck = new QLocalSocket();

//   _sck->connectToServer(HOST);
//   if(!_sck->isValid()) {
//     std::cerr << "Error while connecting to server" << std::endl;
//     delete _sck;
//     _sck = NULL;
//     _keep_going = false;
//     return;
//   }
  
//   while(_sck->state() == QLocalSocket::ConnectingState) {
//     msleep(10);
//   }
  
//   if(_sck->state() != QLocalSocket::ConnectedState) {
//     std::cerr << "Error while waiting for being connected" << std::endl;
//     delete _sck;
//     _sck = NULL;
//     _keep_going = false;
//     return;
//   }
  
//   snprintf(buffer, (size_t) BUFFER_SIZE, msg_hello, _id);
//   if(!sendData(buffer)) {
//     std::cerr << "Error while saying hello" << std::endl;
//     delete _sck;
//     _sck = NULL;
//     _keep_going = false;
//     return;
//   }
  
//   // We are now ready, let's loop to receive data
//   while(_keep_going && isReady()) {
//     read = _sck->readLine(buffer, (qint64) BUFFER_SIZE);
//     if(read == 0) {
//       // Nothing was read, let's wait a bit
//       sleep(0);
//     }
//     else if(read == -1) {
//       std::cerr << "Error while retrieving data" << std::endl;
//       _keep_going = false;
//     }
//     else {
//       // We got a message to route
//       if((pos = strchr(buffer, ' ')) == NULL) {
// 	// No space were found, we can not identify the concerned device
// 	sendData(err_detect);
//       }
//       else {
// 	name = new char[pos-buffer+1];
// 	strncpy(name, buffer, pos-buffer);
// 	name[pos-buffer] = '\0';
// 	_devices_mutex.lock();
// 	if(!_devices.contains(name)) {
// 	  // Unknown device
// 	  snprintf(buffer, (size_t) BUFFER_SIZE, err_unknown, name);
// 	  sendData(buffer);
// 	}
// 	else {
// 	  // Device is known, we give its interpreter function the message
// 	  _devices[name](buffer);
// 	}
// 	_devices_mutex.unlock();
// 	delete[] name;
//       }
//     }
//   }
//   sendData(msg_bye);
//   _sck->disconnectFromServer();
//   delete _sck;
//   _sck = NULL;
// }

bool ClientThread::sendData(const char* data) {
  _com_mutex.lock();
  std::cout << data << "\n";
  std::cout.flush();
  _com_mutex.unlock();
  return true;
}

bool ClientThread::registerDevice(const char* name, const std::function<void(char*)>& interpreter) {
  QString device = name;
  _devices_mutex.lock();
  if(_devices.contains(device)) {
    // If the device is already registered
    _devices_mutex.unlock();
    return false;
  }
  else {
    _devices.insert(device, interpreter);
    _devices_mutex.unlock();
    return true;
  }
}
