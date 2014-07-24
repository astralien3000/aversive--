#!/bin/bash

function usage() {
    echo "Usage: $0 test|clean|{a valid test path}"
    exit 1
}

if [ $# -ne 1 ]; then
    usage
fi

function lastDir {
    ls -l "$1" | grep "^d" | tr -s " " | cut -f 9 -d " " | sort | tail -n 1
}

function recur {
    local LAST=$(lastDir "$1")
    local TARGET="$2"
    local DEPTH="$3"
    local RES=
    local RET=
    let DEPTH+=1

    ls -1 "$1" | while read FILE; do
        FILE_PATH="$1/$FILE"
        if [ -d "$FILE_PATH" ]; then
            for (( i=1; i<$DEPTH; i++ )); do
                echo -n "  "
            done
            if [ "$FILE" = "$LAST" ]; then
                echo -n "└─"
            else
                echo -n "├─"
            fi
            echo -n "$FILE"
            if [ -f "$FILE_PATH/run_test.sh" ]; then
                echo -n ": "
                RES=$(cd "$FILE_PATH" && ./run_test.sh "$TARGET")
                RET=$?
                if [ $RET -eq 0 ]; then
                    echo -e "\e[92mOK\e[39m"
                else
                    echo -e "\e[31m$RES\e[39m"
                fi
            else
                echo
                recur "$FILE_PATH" "$TARGET" "$DEPTH"
            fi
        fi
    done;
}

if [ "$1" = "test" ]; then
    echo "./"
    recur . test 0
    exit 0
elif [ "$1" = "clean" ]; then
    recur . clean 0 &>> /dev/null
    exit 0
elif [ -d "$1" ]; then
    echo "$1"
    recur "$1" test 0
    exit 0
else
    usage
fi
