CC=avr-g++
TARGET_MCU=atmega1280
CFLAGS=-c -mmcu=$(TARGET_MCU) -std=c++11 -Wall -pedantic -nostdlib -nostartfiles -O2 -I../

interrupt_vector_table.o: interrupt_vector_table.cc
	$(CC) $(CFLAGS) -o $@ $<
