asm("vector_table:\r\n");

asm volatile (
    "jmp main\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp timer\r\n"  // 21 0x0028 = TIMER1 OVF
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
    "jmp bad_interrupt\r\n"
);

#include <cpu.h>

extern "C" void timer() __attribute__ ((signal));
void timer()
{
  auto &cpu = ATMega1280::cpu();
  cpu.port_b.port = ~cpu.port_b.port;
  cpu.TCNT1L = 0x00;
  cpu.TCNT1H = 0xF0;
}

extern "C" void bad_interrupt() __attribute__ ((naked));
void bad_interrupt()
{
  auto &cpu = ATMega1280::cpu();
  cpu.port_b.port = 0xff;
  ATMega1280::halt();
}

int main()
{
  auto &cpu = ATMega1280::cpu();

  cpu.port_b.ddr = 0xff;
  cpu.port_b.port = 0x00;
  ATMega1280::cli();

  // Interrupt Mask Register for timer 1. Datasheet pg. 161
  // Bit 1 = TOIE[n]: Timer/Counter[n], Overflow Interrupt Enable
  // The corresponding Interrupt Vector (see “Interrupts” on page 101) is
  // executed when the TOV[n] Flag, located in TIFR[n], is set.
  // In this case, TIMER1 OVF = addr(0x0028)
  cpu.TIMSK1 = 0x01;
  cpu.TCNT1L = 0x00;
  cpu.TCNT1H = 0xF0;
  cpu.TIFR1 = 0x00;
  cpu.TCCR1A = 0x00;
  cpu.TCCR1B = 0x04;

  ATMega1280::sei();
  while(1);
}
