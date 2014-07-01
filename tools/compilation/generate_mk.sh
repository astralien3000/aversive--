#!/bin/bash

TARGET=$1
QMAKE=qmake-qt5

if [ "$TARGET" == "avr" ]
then
  MMCU=$2
  echo "MMCU = " $MMCU > project/generated/avr.mmcu.pro
  $QMAKE project/$TARGET.pro -o $MMCU.mk
  mv $MMCU.mk mk/
elif [ "$TARGET" == "stm32" ]
then
  MMCU=$2
  echo "MMCU = " $MMCU > project/generated/stm32.mmcu.pro
  $QMAKE project/$TARGET.pro -o $MMCU.mk
  mv $MMCU.mk mk/
else
  $QMAKE project/$TARGET.pro -o $TARGET.mk
  mv $TARGET.mk mk/
fi

