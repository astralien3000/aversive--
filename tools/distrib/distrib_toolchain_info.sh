#!/bin/bash

DISTRIB=$1
CMD=$2
MODULE=$3

MODULE_PATHS=""

if [ "$MODULE" == "" ]
then
    MODULE_PATHS=$(cat $DISTRIB)
else
    for m in $(cat $DISTRIB)
    do
	if [ -f $m/.module ]
	then
	    if [ "$(cat $m/.module)" == "$MODULE" ]
	    then
		MODULE_PATHS=$m
	    fi
	else
	    if [ "$m" == "$MODULE" ]
	    then
		MODULE_PATHS=$m
	    fi
	fi
    done
fi

if [ "$CMD" == "modules" ]
then

    for m in $MODULE_PATHS
    do
	if [ -f $m/.module ]
	then
	    cat $m/.module
	    echo -n " "
	else
	    echo -n "$m "
	fi
    done

elif [ "$CMD" == "paths" ]
then

    echo -n $MODULE_PATHS

elif [ "$CMD" == "targets" ]
then

    for m in $MODULE_PATHS
    do
	if [ -f $m/mk/targets ]
	then
	    echo -n $(cat $m/mk/targets)
	fi
    done

elif [ "$CMD" == "cc" ]
then

    for m in $MODULE_PATHS
    do
	if [ -f $m/mk/cc ]
	then
	    cat $m/mk/cc
	fi
    done

elif [ "$CMD" == "cxx" ]
then

    for m in $MODULE_PATHS
    do
	if [ -f $m/mk/cxx ]
	then
	    cat $m/mk/cxx
	fi
    done

elif [ "$CMD" == "ar" ]
then

    for m in $MODULE_PATHS
    do
	if [ -f $m/mk/ar ]
	then
	    cat $m/mk/ar
	fi
    done

elif [ "$CMD" == "ld" ]
then

    for m in $MODULE_PATHS
    do
	if [ -f $m/mk/ld ]
	then
	    cat $m/mk/ld
	fi
    done

elif [ "$CMD" == "cflags" ]
then

    for m in $MODULE_PATHS
    do
	if [ -f $m/mk/flags ]
	then
	    cat $m/mk/flags
	    echo -n " "
	fi
	if [ -f $m/mk/cflags ]
	then
	    cat $m/mk/cflags
	    echo -n " "
	fi
    done

elif [ "$CMD" == "cxxflags" ]
then

    for m in $MODULE_PATHS
    do
	if [ -f $m/mk/flags ]
	then
	    cat $m/mk/flags
	    echo -n " "
	fi
	if [ -f $m/mk/cxxflags ]
	then
	    cat $m/mk/cxxflags
	    echo -n " "
	fi
    done

elif [ "$CMD" == "include" ]
then

    for m in $MODULE_PATHS
    do
	if [ -d $m/include ]
	then
	    echo -n "$m/include "
	fi
    done

elif [ "$CMD" == "csources" ]
then

    for m in $MODULE_PATHS
    do
	if [ -d $m/src ]
	then
	    FOUND=$(echo $(find $m/src -name "*\.c"))
	    if [ "$FOUND" != "" ]
	    then
		echo -n "$FOUND "
	    fi
	fi
    done

elif [ "$CMD" == "asmsources" ]
then

    for m in $MODULE_PATHS
    do
	if [ -d $m/src ]
	then
	    FOUND=$(echo $(find $m/src -name "*\.s"))
	    if [ "$FOUND" != "" ]
	    then
		echo -n "$FOUND "
	    fi
	fi
    done

elif [ "$CMD" == "cxxsources" ]
then

    for m in $MODULE_PATHS
    do
	if [ -d $m/src ]
	then
	    FOUND=$(echo $(find $m/src -name "*\.cpp"))
	    if [ "$FOUND" != "" ]
	    then
		echo -n "$FOUND "
	    fi
	fi
    done

fi
