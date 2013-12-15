#!/bin/bash

make > /dev/null

./server &
towait=$!
ROBOT=MyAwesomeRobot
./client $ROBOT > /dev/null
wait $towait
