#!/bin/bash

TARGET_LIST=

GENERATE_MK=tools/compilation/generate_mk.sh
GENERATE_RULE=tools/compilation/generate_rule.sh

$GENERATE_MK sasiae
$GENERATE_RULE sasiae
TARGET_LIST+="sasiae "

AVR_MMCUS=`ls architecture`

for i in $AVR_MMCUS
do
  if [ ${i%.*} == ${i%%.*} ]
  then
    $GENERATE_MK avr ${i%.*}
    $GENERATE_RULE ${i%.*}
    TARGET_LIST+="${i%.*} "
  fi
done

echo "all_targets: " $TARGET_LIST
