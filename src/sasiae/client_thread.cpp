#include <client_thread.hpp>
#include <cstdio>
#include <cstring>
#include <iostream>

#define HOST "SASIAE-SRV"
#define BUFFER_SIZE 1024

static const char* msg_hello = "Hello %s\n";
static const char* msg_bye = "Bye\n";
static const char* err_detect = "Error impossible to detect device's name\n";
static const char* err_unknown = "Error unknown \"%s\" device\n";

ClientThread::ClientThread(void) : Singleton<ClientThread>(), QThread() {
  _sck = NULL;
  _id = 0;
  _keep_going = true;
}

ClientThread::~ClientThread(void) {
}

void ClientThread::setId(const char* id) {
  if(!isRunning()) {
    _id = id;
  }
}

void ClientThread::quit(void) {
  _keep_going = false;
}

bool ClientThread::isGoing(void) {
  return _keep_going;
}

bool ClientThread::isReady(void) {
  return (_sck != NULL && _sck->state() == QLocalSocket::ConnectedState);
}

void ClientThread::run(void) {
  char buffer[BUFFER_SIZE];
  qint64 read;
  char* name;
  char* pos;
  
  if(_id == 0) {
    std::cerr << "Client ID hasn't been set" << std::endl;
    _keep_going = false;
    return;
  }
  
  _sck = new QLocalSocket();

  _sck->connectToServer(HOST);
  if(!_sck->isValid()) {
    std::cerr << "Error while connecting to server" << std::endl;
    delete _sck;
    _sck = NULL;
    _keep_going = false;
    return;
  }
  
  while(_sck->state() == QLocalSocket::ConnectingState) {
    msleep(10);
  }
  
  if(_sck->state() != QLocalSocket::ConnectedState) {
    std::cerr << "Error while waiting for being connected" << std::endl;
    delete _sck;
    _sck = NULL;
    _keep_going = false;
    return;
  }
  
  snprintf(buffer, (size_t) BUFFER_SIZE, msg_hello, _id);
  if(!sendData(buffer)) {
    std::cerr << "Error while saying hello" << std::endl;
    delete _sck;
    _sck = NULL;
    _keep_going = false;
    return;
  }
  
  // We are now ready, let's loop to receive data
  while(_keep_going && isReady()) {
    read = _sck->readLine(buffer, (qint64) BUFFER_SIZE);
    if(read == 0) {
      // Nothing was read, let's wait a bit
      sleep(0);
    }
    else if(read == -1) {
      std::cerr << "Error while retrieving data" << std::endl;
      _keep_going = false;
    }
    else {
      // We got a message to route
      if((pos = strchr(buffer, ' ')) == NULL) {
	// No space were found, we can not identify the concerned device
	sendData(err_detect);
      }
      else {
	name = new char[pos-buffer+1];
	strncpy(name, buffer, pos-buffer);
	name[pos-buffer] = '\0';
	_devices_mutex.lock();
	if(!_devices.contains(name)) {
	  // Unknown device
	  snprintf(buffer, (size_t) BUFFER_SIZE, err_unknown, name);
	  sendData(buffer);
	}
	else {
	  // Device is known, we give its interpreter function the message
	  _devices[name](buffer);
	}
	_devices_mutex.unlock();
	delete[] name;
      }
    }
  }
  sendData(msg_bye);
  _sck->disconnectFromServer();
  delete _sck;
  _sck = NULL;
}

bool ClientThread::sendData(const char* data) {
  ClientThread &ct = ClientThread::instance();
  if(!ct.isReady()) {
    return false;
  }
  ct._sck_mutex.lock();
  ct._sck->write(data);
  ct._sck->flush();
  ct._sck_mutex.unlock();
  return true;
}

bool ClientThread::registerDevice(const char* name, const std::function<void(char*)>& interpreter) {
  QString device = name;
  ClientThread &ct = ClientThread::instance();
  ct._devices_mutex.lock();
  if(ct._devices.contains(device)) {
    // If the device is already registered
    ct._devices_mutex.unlock();
    return false;
  }
  else {
    ct._devices.insert(device, interpreter);
    ct._devices_mutex.unlock();
    return true;
  }
}
