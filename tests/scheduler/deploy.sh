#!/bin/bash

avr-objcopy -O ihex robot_atmega2560.elf robot_atmega2560.hex
sudo avrdude -cwiring -patmega2560 -P /dev/ttyACM0 -U flash:w:robot_atmega2560.hex -D