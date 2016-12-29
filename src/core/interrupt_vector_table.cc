asm volatile (
    "interrupt_vector_table:\r\n"
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

#include <core/cpu.h>

extern "C" void timer() __attribute__ ((signal));
void timer()
{
  auto &cpu = ATMega1280::cpu();
  cpu.port_b.port = ~cpu.port_b.port;
  cpu.TCNT1L = 0x00;
  cpu.TCNT1H = 0x10;
}

extern "C" void bad_interrupt() __attribute__ ((naked));
void bad_interrupt()
{
  auto &cpu = ATMega1280::cpu();
  cpu.port_b.port = 0xff;
  ATMega1280::halt();
}
