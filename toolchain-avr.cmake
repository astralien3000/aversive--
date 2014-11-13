INCLUDE(CMakeForceCompiler)

# This one is important:
#
# This one is mandatory, it is the name of the target system, i.e. the same as CMAKE_SYSTEM_NAME 
# would have if CMake would run on the target system. Typical examples are "Linux" and "Windows". 
# This variable is used for constructing the file names of the platform files like Linux.cmake 
# or Windows-gcc.cmake. If your target is an embedded system without OS set CMAKE_SYSTEM_NAME 
# to "Generic". If CMAKE_SYSTEM_NAME is preset, the CMake variable CMAKE_CROSSCOMPILING is 
# automatically set to TRUE, so this can be used for testing in the CMake files.
SET(CMAKE_SYSTEM_NAME Generic)

# This one not so much:
#
# Optional, version of your target system, not used very much. 
SET(CMAKE_SYSTEM_VERSION 1)

# Specify the cross compiler:
#
# The C compiler executable, may be the full path or just the filename. If it is specified with 
# full path, then this path will be prefered when searching the C++ compiler and the other tools 
# (binutils, linker, etc.). If this compiler is a gcc-cross compiler with a prefixed name (e.g. 
# "arm-elf-gcc") CMake will detect this and automatically find the corresponding C++ compiler 
# (i.e. "arm-elf-c++"). The compiler can also be preset via the CC environment variables. 
#SET(CMAKE_C_COMPILER   /usr/bin/avr-gcc)
#SET(CMAKE_CXX_COMPILER /usr/bin/avr-g++)
CMAKE_FORCE_C_COMPILER(avr-gcc GNU)
CMAKE_FORCE_CXX_COMPILER(avr-g++ GNU)

# For testing the host system, there is a corresponding set of variables, which is set 
# automatically by CMake:
#  * CMAKE_HOST_SYSTEM_NAME
#  * CMAKE_HOST_SYSTEM_VERSION
#  * CMAKE_HOST_SYSTEM_PROCESSOR
#  * CMAKE_HOST_SYSTEM 

# Where is the target environment:
SET(CMAKE_FIND_ROOT_PATH  /usr/lib/avr)

# Search for programs in the build host directories:
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

# For libraries and headers in the target directories:
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)