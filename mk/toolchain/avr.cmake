INCLUDE(CMakeForceCompiler)

SET(CMAKE_SYSTEM_NAME Generic)

SET(CMAKE_SYSTEM_VERSION 1)

#SET(CMAKE_C_COMPILER   /usr/bin/avr-gcc)
#SET(CMAKE_CXX_COMPILER /usr/bin/avr-g++)
CMAKE_FORCE_C_COMPILER(avr-gcc GNU)
CMAKE_FORCE_CXX_COMPILER(avr-g++ GNU)

# Where is the target environment:
SET(CMAKE_FIND_ROOT_PATH  /usr/lib/avr)

# Search for programs in the build host directories:
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

# For libraries and headers in the target directories:
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

add_compile_options(-mmcu=${TARGET})

