#!/bin/bash

TARGET=$1

echo "HEADERS = " $(find include/{$TARGET,common})
echo "SOURCES = " $(find src/{$TARGET,common})
