#!/bin/bash

make > /dev/null

./server &
towait=$!
./client MyAwesomeRobot > /dev/null
wait $towait
