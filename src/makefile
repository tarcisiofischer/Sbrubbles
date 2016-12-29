CC=avr-g++
TARGET_MCU=atmega1280
MCU_TYPE=avr51
CFLAGS=-c -mmcu=$(TARGET_MCU) -std=c++11 -Wall -pedantic -nostdlib -nostartfiles -O2 -I.

dependencies:
	$(MAKE) -C core

led_blink: led_blink.o core/interrupt_vector_table.o dependencies
	avr-ld \
		-m$(MCU_TYPE) \
		core/interrupt_vector_table.o \
		$< \
		-o $@.out
	avr-objcopy \
		-j .text \
		-j .data \
		-O ihex $@.out \
		$@.hex

led_blink_simple: led_blink_simple.o core/interrupt_vector_table.o dependencies
	avr-ld \
		-m$(MCU_TYPE) \
		core/interrupt_vector_table.o \
		$< \
		-o $@.out
	avr-objcopy \
		-j .text \
		-j .data \
		-O ihex $@.out \
		$@.hex

%.o: %.cc
	 $(CC) $(CFLAGS) -o $@ $<

install: $(TARGET)
	avrdude \
	-v \
	-e \
	-c arduino \
	-p atmega1280 \
	-P /dev/ttyUSB0 \
	-b 57600 \
	-U flash:w:$(TARGET).hex

clean:
	rm a.out
	rm a.hex
