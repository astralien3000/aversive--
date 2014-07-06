#!/bin/bash

TARGET=$1

echo "HEADERS += " $(find include/$TARGET -name *.hpp)
echo "SOURCES += " $(find src/$TARGET -name *.cpp)
