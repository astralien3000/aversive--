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

function run {
    echo -n ": "
    local RES=

    RES=$(cd "$1" && ./run_test.sh "$2")
    if [ $? -eq 0 ]; then
        echo -e "\e[92mOK\e[39m"
    else
        echo -e "\e[31m$RES\e[39m"
    fi
}

function recur {
    local LAST=$(lastDir "$1")
    local TARGET="$2"
    local DEPTH="$3"
    let DEPTH+=1

    ls -1 "$1" | while read FILE; do
        FILE_PATH="$1/$FILE"
        if [ -d "$FILE_PATH" ]; then
            for (( i=1; i<$DEPTH; i++ )); do
                local C="$FILE_PATH"
                for (( j=$i; j<$DEPTH; j++)); do
                    C="$C/.."
                done
                if [ "$(lastDir $(cd $C && echo ${PWD%/*}))" != "$(cd $C && echo ${PWD##*/})" ]; then
                    echo -n "│   "
                else
                    echo -n "    "
                fi
            done
            if [ "$FILE" = "$LAST" ]; then
                echo -n "└── "
            else
                echo -n "├── "
            fi
            echo -ne "\e[94m"
            echo -n "$FILE"
            echo -ne "\e[39m"
            if [ -f "$FILE_PATH/run_test.sh" ]; then
                run "$FILE_PATH" "$TARGET"
            else
                echo
                recur "$FILE_PATH" "$TARGET" "$DEPTH"
            fi
        fi
    done;
}

if [ "$1" = "test" ]; then
    echo -ne "\e[94m"
    echo "."
    echo -ne "\e[39m"
    recur . test 0
    exit 0
elif [ "$1" = "clean" ]; then
    recur . clean 0 &>> /dev/null
    exit 0
elif [ -d "$1" ]; then
    echo -ne "\e[94m"
    echo -n "$1"
    echo -ne "\e[39m"
    if [ -f "$1/run_test.sh" ]; then
        run "$1" "test"
    else
        echo
        recur "$1" test 0
    fi
    exit 0
else
    usage
fi
