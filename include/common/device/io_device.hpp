#ifndef IO_DEVICE_HPP
#define IO_DEVICE_HPP


template<typename T>
class IODevice : public Input<T>, public Output<T>, public Device {
public:
  IODevice(const char* name);
  
  T getValue(void); 
  void setValue(T);
};

#endif//IO_DEVICE_HPP
