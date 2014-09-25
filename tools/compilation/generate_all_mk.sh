#!/bin/bash

TARGET_LIST=

GENERATE_MK=generate_mk
GENERATE_RULE=generate_rule

########################################
# Generate mk

function generate_mk
{
  TARGET=$1

  if type qmake 2> /dev/null
  then
      QMAKE=qmake
  else
      QMAKE=qmake-qt5
  fi


  if [ "$TARGET" == "avr" ]
  then
    MMCU=$2
    echo "MMCU = " $MMCU > project/generated/avr.mmcu.pro
    $QMAKE project/$TARGET.pro -o $MMCU.mk
    cat $MMCU.mk | grep '$(QMAKE)' -v > mk/$MMCU.mk
    rm -f $MMCU.mk
  elif [ "$TARGET" == "stm32" ]
  then
    MMCU=$2
    echo "MMCU = " $MMCU > project/generated/stm32.mmcu.pro
    $QMAKE project/$TARGET.pro -o $MMCU.mk
    cat $MMCU.mk | grep '$(QMAKE)' -v > mk/$MMCU.mk
    rm -f $MMCU.mk
  else
    $QMAKE project/$TARGET.pro -o $TARGET.mk
    cat $TARGET.mk | grep '$(QMAKE)' -v > mk/$TARGET.mk
    rm -f $TARGET.mk
  fi
}

########################################
# Generate rule

function generate_rule
{
  TARGET=$1

  echo ""
  echo -e "$1:"
  echo -e "\t\$(MAKE) -f mk/$TARGET.mk"
  echo ""
}

########################################
# SASIAE

$GENERATE_MK sasiae &> /dev/null
$GENERATE_RULE sasiae
TARGET_LIST+="sasiae "

########################################
# AVR

AVR_MMCUS=`ls architecture`

for i in $AVR_MMCUS
do
  if [ ${i%.*} == ${i%%.*} ]
  then
    $GENERATE_MK avr ${i%.*} &> /dev/null
    $GENERATE_RULE ${i%.*}
    TARGET_LIST+="${i%.*} "
  fi
done

########################################
# STM32

$GENERATE_MK stm32 stm32f4 &> /dev/null
$GENERATE_RULE stm32f4
TARGET_LIST+="stm32f4 "


########################################
# ALL

echo "all_targets: " $TARGET_LIST
