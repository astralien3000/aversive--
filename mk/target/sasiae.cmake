add_module(base)
add_module(container)
add_module(math)
add_module(geometry)
add_module(stream)
add_module(device)
add_module(filter)

add_module(sasiae)

find_package(Qt5Core REQUIRED)
include_directories(${Qt5Core_INCLUDE_DIRS})
add_definitions(${Qt5Core_DEFINITIONS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Core_EXECUTABLE_COMPILE_FLAGS}")
