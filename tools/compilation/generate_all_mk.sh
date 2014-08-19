#!/bin/bash

TARGET_LIST=

GENERATE_MK=tools/compilation/generate_mk.sh
GENERATE_RULE=tools/compilation/generate_rule.sh

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
