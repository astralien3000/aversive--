#!/bin/bash

st-flash --reset write build/test.bin 0x08000000
