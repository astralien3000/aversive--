# this one is important
SET(CMAKE_SYSTEM_NAME Generic)

# specify the cross compiler
SET(CMAKE_C_COMPILER   avr-gcc)
SET(CMAKE_CXX_COMPILER avr-g++)

# where is the target environment 
SET(CMAKE_FIND_ROOT_PATH .)

include_directories("/usr/avr/include")
add_compile_options(-mmcu=${TARGET})

# search for programs in the build host directories
#SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# for libraries and headers in the target directories
#SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
#SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)