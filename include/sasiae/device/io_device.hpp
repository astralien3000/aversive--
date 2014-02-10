#ifndef SASIAE_IO_DEVICE_HPP
#define SASIAE_IO_DEVICE_HPP

#include "../../common/device/io_device.hpp"
#include <io_device.hpp>

template<typename T1, typename T2>
IODevice<T1,T2>::IODevice(char* name):Device(name){}

#endif//SASIAE_IO_DEVICE_HPP
