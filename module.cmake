FILE(
  GLOB_RECURSE
  FOUND_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
  )

FILE(
  GLOB_RECURSE
  FOUND_HEADERS
  ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp
  )

SET(
  SOURCES 
  ${SOURCES} 
  ${FOUND_SOURCES}
  PARENT_SCOPE
  )

SET(
  HEADERS
  ${HEADERS}
  ${FOUND_HEADERS}
  PARENT_SCOPE
  )

SET(
  INCLUDE_DIRS
  ${INCLUDE_DIRS}
  "${CMAKE_CURRENT_SOURCE_DIR}/include" 
  PARENT_SCOPE
  )