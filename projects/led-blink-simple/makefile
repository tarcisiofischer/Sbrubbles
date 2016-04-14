all:
	avr-g++ -mmcu=atmega1280 -std=c++11 -nostdlib -Wall -pedantic -O0 main.cc -o a.out -I../../src/
	avr-objcopy -j .text -j .data -O ihex a.out a.hex

install:
	avrdude -c arduino -v -p atmega1280 -P /dev/ttyUSB0 -e -b 57600 -U flash:w:a.hex

clean:
	rm a.out
	rm a.hex
