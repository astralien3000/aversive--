#!/bin/bash

cd include/common
g++ --std=c++11 -I./ -Wall -Wextra config.hpp
strings config.hpp.gch | grep "^_.*__PARAM" | sort | uniq
rm config.hpp.gch
