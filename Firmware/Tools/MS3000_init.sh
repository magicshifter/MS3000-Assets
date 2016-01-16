#!/bin/bash

CONFIG_FILE=settings_ap.bin

[[ $# > 1 ]] && SERIAL_PORT="$2" || SERIAL_PORT="/dev/ttyUSB0"

echo "using nr $1 and serialport $SERIAL_PORT"

awk  'BEGIN{ printf "MS3000_Nr%03d\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", '"$1"'}' > $CONFIG_FILE

./MS3000Tool.py up $CONFIG_FILE settings/ap.bin $SERIAL_PORT 

