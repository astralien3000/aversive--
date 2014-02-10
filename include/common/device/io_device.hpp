#ifndef IO_DEVICE_HPP
#define IO_DEVICE_HPP


template<typename T1, typename T2 = T1>
class IODevice : public Input<T1>, public Output<T2>, public Device {
public:
  IODevice(const char* name);
};

#endif//IO_DEVICE_HPP
