#include <client_thread.hpp>
#include <aversive.hpp>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <unistd.h>

#define DEFAULT_BUFFER_SIZE 64

static const char* const err_detect_device = "M E Impossible to detect device's name";
static const char* const err_unknown_device = "M E Unknown device \"%s\"";
static const char* const err_unknown_command = "M E Unknown command %c";

ClientThread* ClientThread::_inst = NULL;

ClientThread::ClientThread(void) : QThread() {
  _keep_going = true;
  _inst = this;
  _buffer = new char[DEFAULT_BUFFER_SIZE];
  _length = DEFAULT_BUFFER_SIZE;
}

ClientThread::~ClientThread(void) {
  delete[] _buffer;
  _inst = NULL;
}

void ClientThread::expandBuffer(void) {
  char* new_buffer = new char[_length * 2];
  memset(new_buffer, 0, _length * 2);
  memcpy(new_buffer, _buffer, _length);
  _length *= 2;
  delete _buffer;
  _buffer = new_buffer;
}

void ClientThread::readLine(void) {
  unsigned int i = 0;
  int c;
  while((c = getchar()) && c != '\n' && c != -1) {
    _buffer[i++] = (char) c;
    if(i >= _length) {
      expandBuffer();
    }
  }
  _buffer[i] = '\0';
  if(c == -1) {
    Aversive::stop();
    quit();
  }
}

void ClientThread::quit(void) {
  _keep_going = false;
}

void ClientThread::run(void) {
  while(_keep_going) {
    readLine();
    if(!_keep_going)
      break;
    
    if(_buffer[0] == '\0') {
    }
    else if(_buffer[0] == 'T') {
      // Synchronization message
      long long timestamp = 0;
      sscanf((_buffer + 2), "%lld", &timestamp);
      _sync_func(timestamp);
    }
    else if(_buffer[0] == 'D') {
      // Device message
      int b = 2, e = 2;
      while(_buffer[e++] != ' ' && _buffer[e] != '\0');
      if(_buffer[e] == '\0') {
	// Impossible to detect device's name
	snprintf(_buffer, (size_t) _length, err_detect_device);
	sendData(_buffer);
	continue;
      }
      
      char* name = new char[e - b];
      memcpy(name, _buffer + 2, e - b);
      name[e - b - 1] = '\0';
      
      _devices_mutex.lock();
      if(!_devices.contains(name)) {
	// Unknown device
	_devices_mutex.unlock();
	snprintf(_buffer, (size_t) _length, err_unknown_device, name);
	sendData(_buffer);
      }
      else {
	// Device is known, we give its interpreter function the message
	const std::function<void(char*)>& interpreter = _devices[name];
	_devices_mutex.unlock();
	interpreter(_buffer + e);
      }
      delete[] name;
    }
    else if(_buffer[0] == 'B') {
      // Begin match message
    }
    else if(_buffer[0] == 'S') {
      // Stop message
      Aversive::stop();
    }
    else {
      // Unknown command
      snprintf(_buffer, (size_t) _length, err_unknown_command, _buffer[0]);
      sendData(_buffer);
    }
  }
}

bool ClientThread::sendData(const char* data) {
  _com_mutex.lock();
  std::cout << data << "\n";
  std::cout.flush();
  _com_mutex.unlock();
  return true;
}

bool ClientThread::sendDeviceMessage(const Device& dev, const char* msg) {
  return sendData((std::string("D ") + dev.name() + " " + msg).c_str());
}



bool ClientThread::sendMessage(MessageLevel lvl, const char* msg) {
  char msg_lvl[] = "I\0";
  switch(lvl) {
  case ERROR:
    msg_lvl[0] = 'E';
    break;
  case INFO:
    msg_lvl[0] = 'I';
    break;
  case DEBUG:
    msg_lvl[0] = 'D';
    break;
  case WARNING:
    msg_lvl[0] = 'W';
    break;
  }

  return sendData((std::string("M ") + msg_lvl + " " + msg).c_str());
}

bool ClientThread::registerDevice(const Device& dev, const std::function<void(char*)>& interpreter) {
  QString device = dev.name();
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

bool ClientThread::setSyncFunction(const std::function<void(int)>& interpreter) {
  _sync_func = interpreter;
  return true;
}

ClientThread& ClientThread::instance() {
  return *_inst;
}
