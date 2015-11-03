
dumpname=firmware-0x0000.bin
buildname=./build/WiFiMagicShifterOS.cpp.bin

./esptool.py --baud 460800 read_flash 0x00000 $(stat -c '%s' $buildname) $dumpname
cmp --verbose $buildname $dumpname

#./esptool.py read_flash 0x00000 0xFFF my_app.elf-0x00000.bin
#./esptool.py read_flash 0x40000 0xFFFF my_app.elf-0x40000.bin
