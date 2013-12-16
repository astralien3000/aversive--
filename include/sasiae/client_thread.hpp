#ifndef CLIENT_THREAD_HPP
#define CLIENT_THREAD_HPP

#include <QThread>
#include <QMutex>
#include <QMap>
#include <QString>
#include <functional>

//! \brief ClientThread handles the communication between SASIAE and the different devices
class ClientThread : protected QThread {
private:
  void expandBuffer(void);
  void readLine(void);
  
protected:
  bool _keep_going;
  
  char* _buffer;
  quint32 _length;
  QMutex _com_mutex;
  
  QMap<QString, std::function<void(char*)> > _devices;
  QMutex _devices_mutex;

  static ClientThread* _this;

  ClientThread(void);
  ~ClientThread(void);

public:
  //! \brief Output devices should use this to send data to SASIAE (thread-safe method)
  //! \brief The function adds a '\n' to the message, therefore the device does not have to do it
  //! \param data : the complete message to send to SASIAE, must be a zero-terminated string
  //! \return True on success, false otherwise
  bool sendData(const char* data);
  
  //! \brief Input devices should use this to register themselves so ClientThread can route the message it gets to the proper device (thread-safe method)
  //! \warning This does not declare the device to SASIAE as initialized, the device has to do it by its own
  //! \param name : the device's name (id)
  //! \param interpreter : the thread-safe function that interprets the message intended to the given device
  //! \return True on success, false otherwise
  bool registerDevice(const char* name, const std::function<void(char*)>& interpreter);
  
  //! \brief Get the unique instance of the Client Thread
  //! \warning Should not be called before Aversive::init !
  static ClientThread& instance(void);
};

#endif//CLIENT_THREAD_HPP
