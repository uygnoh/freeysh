all:
	sdcc -mmcs51 main.c

hex:
	packihx main.ihx >main.hex

program:
	stcflash.py main.hex --port /dev/ttyUSB0

.PHONY: clean
clean:
	rm -f *.rel
	rm -f *.asm
	rm -f *.lst
	rm -f *.sym
	rm -f *.map
	rm -f *.lk
	rm -f *.mem
	rm -f *.rst
	rm -f *.ihx
	rm -f *.hex
	rm -f *.bin
