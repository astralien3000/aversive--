#!/bin/bash

function usage() {
    echo "Usage: $0 test|clean"
    exit 1
}

if [ $# -ne 1 ]; then
    usage
fi

if [ "$1" = "test" ]; then
    make &>> /dev/null
    if [ $? -ne 0 ]; then
        echo "Compilation error"
        exit 1
    fi
    #sudo ./alloc.elf
    #exit $?
    echo "Non-functional test due to bug in Stream string read."
    exit 1
elif [ "$1" = "clean" ]; then
    make mrproper &>> /dev/null
    exit 0
else
    usage
fi
