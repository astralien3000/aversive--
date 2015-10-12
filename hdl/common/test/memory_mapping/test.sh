#!/bin/bash

LIST=$(make list && ./test.elf)

for i in $LIST
do
    echo $i
    echo -n "    .........................  "
    if [[ $i =~ .*KO$ ]]
    then
	RET=$(TEST=$i make 2> log)
	if [[ $RET == "" ]]
	then
	    echo "ERROR, should not compile"
	else
	    echo "PASSED"
	fi
    else
	TEST=$i make && ./test.elf
    fi
done
