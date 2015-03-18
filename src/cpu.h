#ifndef CPU_H
#define CPU_H

#include <common.h>

class ATMega1280
{
public:
    static const unsigned int number_of_interrupts = 18;

    Port port_a;
    Port port_b;
    Port port_c;
    Port port_d;
    Port port_e;
    Port port_f;
    Port port_g;

    Register TIFR0;
    Register TIFR1;
    Register TIFR2;
    Register TIFR3;
    Register TIFR4;
    Register TIFR5;

    Register PCIFR;
    Register EIFR;
    Register EIMSK;
    Register GPIOR0;
    Register EECR;
    Register EEDR;
    Register EEARL;
    Register EEARH;
    Register GTCCR;
    Register TCCR0A;
    Register TCCR0B;
    Register TCNT0;
    Register OCR0A;
    Register OCR0B;
    Register _reserved00;
    Register GPIOR1;
    Register GPIOR2;
    Register SPCR;
    Register SPSR;
    Register SPDR;
    Register _reserved01;
    Register ACSR;
    Register OCDR;
    Register _reserved02;
    Register SMCR;
    Register MCUSR;
    Register MCUCR;
    Register _reserved03;
    Register SPMCSR;
    Register _reserved04;
    Register _reserved05;
    Register _reserved06;
    Register RAMPZ;
    Register EIND;
    Register SPL;
    Register SPH;
    Register SREG;
    Register WDTCSR;
    Register CLKPR;
    Register _reserved07;
    Register _reserved08;
    Register PRR0;
    Register PRR1;
    Register OSCCAL;
    Register _reserved09;
    Register PCICR;
    Register EICRA;
    Register EICRB;
    Register PCMSK0;
    Register PCMSK1;
    Register PCMSK2;
    Register TIMSK0;
    Register TIMSK1;
    Register TIMSK2;
    Register TIMSK3;
    Register TIMSK4;
    Register TIMSK5;
    Register XMCRA;
    Register XMCRB;
    Register _reserved10;
    Register _reserved11;
    Register ADCL;
    Register ADCH;
    Register ADCSRA;
    Register ADCSRB;
    Register ADMUX;
    Register DIDR2;
    Register DIDR0;
    Register DIDR1;
    Register TCCR1A;
    Register TCCR1B;
    Register TCCR1C;
    Register _reserved12;
    Register TCNT1L;
    Register TCNT1H;
    Register ICR1L;
    Register ICR1H;
    Register OCR1AL;
    Register OCR1AH;
    Register OCR1BL;
    Register OCR1BH;
    Register OCR1CL;
    Register OCR1CH;
    Register _reserved13;
    Register _reserved14;
    Register TCCR3A;
    Register TCCR3B;
    Register TCCR3C;
    Register _reserved15;
    Register TCNT3L;
    Register TCNT3H;
    Register ICR3L;
    Register ICR3H;
    Register OCR3AL;
    Register OCR3AH;
    Register OCR3BL;
    Register OCR3BH;
    Register OCR3CL;
    Register OCR3CH;
    Register _reserved16;
    Register _reserved17;
    Register TCCR4A;
    Register TCCR4B;
    Register TCCR4C;
    Register _reserved18;
    Register TCNT4L;
    Register TCNT4H;
    Register ICR4L;
    Register ICR4H;
    Register OCR4AL;
    Register OCR4AH;
    Register OCR4BL;
    Register OCR4BH;
    Register OCR4CL;
    Register OCR4CH;
    Register _reserved19;
    Register _reserved20;
    Register TCCR2A;
    Register TCCR2B;
    Register TCNT2;
    Register OCR2A;
    Register OCR2B;
    Register _reserved21;
    Register ASSR;
    Register _reserved22;
    Register TWBR;
    Register TWSR;
    Register TWAR;
    Register TWDR;
    Register TWCR;
    Register TWAMR;
    Register _reserved23;
    Register _reserved24;
    Register UCSR0A;
    Register UCSR0B;
    Register UCSR0C;
    Register _reserved25;
    Register UBRR0L;
    Register UBRR0H;
    Register UDR0;
    Register _reserved26;
    Register UCSR1A;
    Register UCSR1B;
    Register UCSR1C;
    Register _reserved27;
    Register UBRR1L;
    Register UBRR1H;
    Register UDR1;
    Register _reserved28;
    Register UCSR2A;
    Register UCSR2B;
    Register UCSR2C;
    Register _reserved29;
    Register UBRR2L;
    Register UBRR2H;
    Register UDR2;
    Register _reserved30[40];
    Port port_h;
    Port port_j;
    Port port_k;
    Port port_l;
    Register _reserved31[20];
    Register TCCR5A;
    Register TCCR5B;
    Register TCCR5C;
    Register _reserved32;
    Register TCNT5L;
    Register TCNT5H;
    Register ICR5L;
    Register ICR5H;
    Register OCR5AL;
    Register OCR5AH;
    Register OCR5BL;
    Register OCR5BH;
    Register OCR5CL;
    Register OCR5CH;
    Register _reserved33;
    Register _reserved34;
    Register UCSR3A;
    Register UCSR3B;
    Register UCSR3C;
    Register _reserved35;
    Register UBRR3L;
    Register UBRR3H;
    Register UDR3;

    __inline__ void cli() const
    {
        asm volatile("cli\n");
    }

    __inline__ void sei() const
    {
        asm volatile("sei\n");
    }

    static __inline__ ATMega1280 &cpu()
    {
        return *reinterpret_cast<ATMega1280*>((char*)0x20);
    } 
};

#endif
