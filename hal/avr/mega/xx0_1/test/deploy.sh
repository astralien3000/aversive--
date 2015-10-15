#!/bin/bash

avr-objcopy -O ihex test_atmega2560.elf test_atmega2560.hex
sudo avrdude -cwiring -patmega2560 -P /dev/ttyACM0 -U flash:w:test_atmega2560.hex -D
