#include <client_thread.hpp>
#include <cstdio>
#include <cstring>
#include <iostream>

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

bool ClientThread::readLine(void) {
  unsigned int i = 0;
  int c;
  while((c = getchar()) && c != '\n' && c != -1) {
    _buffer[i++] = (char) c;
    if(i > _length) {
      expandBuffer();
    }
  }
  _buffer[i] = '\0';
  return (c == '\n');
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
      _keep_going = false;
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

ClientThread& ClientThread::instance() {
  return *_inst;
}
