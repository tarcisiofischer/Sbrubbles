all:
	avr-g++ \
		-mmcu=atmega1280 \
		-std=c++11 \
		-Wall \
		-pedantic \
		-nostdlib \
		-nostartfiles \
		-O0 \
		-o a.out \
		-I../../src/ \
		main.cc
	avr-objcopy \
		-j .text \
		-j .data \
		-O ihex a.out \
		a.hex

install:
	avrdude \
	-v \
	-e \
	-c arduino \
	-p atmega1280 \
	-P /dev/ttyUSB0 \
	-b 57600 \
	-U flash:w:a.hex

clean:
	rm a.out
	rm a.hex
