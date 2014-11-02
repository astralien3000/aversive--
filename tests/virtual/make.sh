#! /bin/bash

function inst {
    NUM=$1

    echo -n "$NUM "

    while [ $# -ge 2 ]
    do
	avr-g++ -std=c++11 -I/home/astralien3000/Bureau/aversive++/include/ $2 $FLAG -o $2.elf
	
	echo -n $(ls -l $2.elf | cut -d" " -f5)
	echo -n " "
	shift
    done

    echo ""
}

function test {
    NUM=$1
    shift
    FLAG=$1
    shift

    for i in $(seq 0 $NUM)
    do
	
	echo -n "" > macro_test

	for j in $(seq 0 $i)
	do
	    echo "ACTUATOR_TEST($j)" >> macro_test
	    echo "INTERFACE_TEST($j)" >> macro_test
	done

	inst $i $@ 

    done
}

test 20 -O3 test{1,2,3,4}.cpp > virtualO3.dat
test 20 "" test{1,2,3,4}.cpp > virtual.dat