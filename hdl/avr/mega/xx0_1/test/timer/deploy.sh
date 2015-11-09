#!/bin/bash

EXE=test_atmega2560

avr-objcopy -O ihex $EXE.elf $EXE.hex
sudo avrdude -cwiring -patmega2560 -P /dev/ttyACM0 -U flash:w:$EXE.hex -D
