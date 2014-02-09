#ifndef CLIENT_THREAD_HPP
#define CLIENT_THREAD_HPP

#include <QtCore/QThread>
#include <QMutex>
#include <QSemaphore>
#include <QMap>
#include <QString>
#include <functional>

#include <device/device.hpp>

//! \brief ClientThread handles the communication between SASIAE and the different devices
class ClientThread : protected QThread {
private:
  void expandBuffer(void);
  void readLine(void);
  
protected:
  bool _keep_going;
  
  char* _buffer;
  unsigned long _length;
  QMutex _com_mutex;

  unsigned long int _time;
  QSemaphore _iteration;

  bool _timed_task_done;
  bool _synchronized;
  QMutex _sync_mutex;
  
  QMap<QString, std::function<void(char*)> > _devices;
  QMutex _devices_mutex;

  std::function<void(int)> _sync_func;

  static ClientThread* _inst;

  ClientThread(void);
  virtual ~ClientThread(void);
  
  void quit(void);
  void run(void) Q_DECL_OVERRIDE;
  
  void sync(void);

public:
  //! \brief Raw data sent to SASIAE
  //! \brief The function adds a '\n' to the message, therefore the device does not have to do it
  //! \param data : the complete message to send to SASIAE, must be a zero-terminated string
  //! \return True on success, false otherwise
  bool sendData(const char* data);

  //! \brief Output devices should use this to send data to SASIAE (thread-safe method)
  //! \param data : the complete message to send to SASIAE, must be a zero-terminated string
  //! \return True on success, false otherwise
  bool sendDeviceMessage(const Device& dev, const char* msg);

  //! \brief Type of the message to send, used in sendMessage method
  enum MessageLevel {
    ERROR,
    INFO,
    DEBUG, 
    WARNING
  };
  
  //! \brief Output devices should use this to send data to SASIAE (thread-safe method)
  //! \param data : the complete message to send to SASIAE, must be a zero-terminated string
  //! \return True on success, false otherwise
  bool sendMessage(MessageLevel lvl, const char* msg);

  //! \brief Input devices should use this to register themselves so ClientThread can route the message it gets to the proper device (thread-safe method)
  //! \warning This does not declare the device to SASIAE as initialized, the device has to do it by its own
  //! \param name : the device's name (id)
  //! \param interpreter : the thread-safe function that interprets the message intended to the given device
  //! \return True on success, false otherwise
  bool registerDevice(const Device& dev, const std::function<void(char*)>& interpreter);
  
  bool setSyncFunction(const std::function<void(int)>& interpreter);
  
  //! \brief Get the unique instance of the Client Thread
  //! \warning Should not be called before Aversive::init !
  static ClientThread& instance(void);

  unsigned long int time() const;
};

#endif//CLIENT_THREAD_HPP
