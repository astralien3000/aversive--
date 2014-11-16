set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-fno-threadsafe-statics -D__STDC_LIMIT_MACROS -O3 -mmcu=${TARGET} -std=c++11")
link_directories(${AVERSIVE_ROOT}/build/)

macro(add_module name)
  include_directories(${AVERSIVE_ROOT}/modules/${name}/include)
endmacro(add_module)

include(${AVERSIVE_ROOT}/mk/target/${TARGET}.cmake)

file(GLOB_RECURSE SOURCES *.cpp *.c)
add_executable(${PROJECT} ${SOURCES})
target_link_libraries(${PROJECT} aversive++_${TARGET})