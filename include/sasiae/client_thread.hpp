#ifndef CLIENT_THREAD_HPP
#define CLIENT_THREAD_HPP

#include "base/singleton.hpp"
#include "aversive.hpp"
#include <QThread>
#include <QLocalSocket>
#include <QMutex>
#include <QMap>
#include <QString>
#include <functional>

//! \brief ClientThread handles the communication between SASIAE and the different devices
class ClientThread : public Singleton<ClientThread>, protected QThread {
  friend class Singleton<ClientThread>;
  friend class Aversive;
  
  bool _keep_going;
  const char* _id;
  
  QLocalSocket* _sck;
  QMutex _sck_mutex;
  
  QMap<QString, std::function<void(char*)> > _devices;
  QMutex _devices_mutex;
protected:
  ClientThread(void);
  ~ClientThread(void);
  void setId(const char* id);
  void quit(void);
  bool isReady();
  void run(void) Q_DECL_OVERRIDE;

public:
  //! \brief Output devices should use this to send data to SASIAE (thread-safe method)
  //! \param data : the complete message to send to SASIEA (starting with device's name), must be a zero-terminated string
  //! \return True on success, false otherwise
  static bool sendData(const char* data);
  
  //! \brief Input devices should use this to register themselves so ClientThread can route the message it gets to the proper device (thread-safe method)
  //! \brief Attention: this doesn't declare the device to SASIAE as initialized, the device has to do it by its own
  //! \param name : the device's name (id)
  //! \param interpreter : the thread-safe function that interprets the message intended to the given device
  //! \return True on success, false otherwise
  static bool registerDevice(const char* name, const std::function<void(char*)>& interpreter);
};

#endif//CLIENT_THREAD_HPP
