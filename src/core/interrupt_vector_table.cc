asm volatile (
    "interrupt_vector_table:\r\n"
    "jmp main\r\n"                // 01  0x0000  RESET
    "jmp bad_interrupt\r\n"       // 02  0x0002  INT0
    "jmp bad_interrupt\r\n"       // 03  0x0004  INT1
    "jmp bad_interrupt\r\n"       // 04  0x0006  INT2
    "jmp bad_interrupt\r\n"       // 05  0x0008  INT3
    "jmp bad_interrupt\r\n"       // 06  0x000A  INT4
    "jmp bad_interrupt\r\n"       // 07  0x000C  INT5
    "jmp bad_interrupt\r\n"       // 08  0x000E  INT6
    "jmp bad_interrupt\r\n"       // 09  0x0010  INT7
    "jmp bad_interrupt\r\n"       // 10  0x0012  PCINT0
    "jmp bad_interrupt\r\n"       // 11  0x0014  PCINT1
    "jmp bad_interrupt\r\n"       // 12  0x0016  PCINT2
    "jmp bad_interrupt\r\n"       // 13  0x0018  WDT
    "jmp bad_interrupt\r\n"       // 14  0x001A  TIMER2 COMPA
    "jmp bad_interrupt\r\n"       // 15  0x001C  TIMER2 COMPB
    "jmp bad_interrupt\r\n"       // 16  0x001E  TIMER2 OVF
    "jmp bad_interrupt\r\n"       // 17  0x0020  TIMER1 CAPT
    "jmp timer\r\n"               // 18  0x0022  TIMER1 COMPA
    "jmp bad_interrupt\r\n"       // 19  0x0024  TIMER1 COMPB
    "jmp bad_interrupt\r\n"       // 20  0x0026  TIMER1 COMPC
    "jmp bad_interrupt\r\n"       // 21  0x0028  TIMER1 OVF
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

extern "C" void timer() __attribute__ ((naked));
void timer()
{
  typedef void (f)();
  (*(f**)(ATMega1280::memory_begin()))();
  asm volatile("reti");
}

extern "C" void bad_interrupt() __attribute__ ((naked));
void bad_interrupt()
{
  auto &cpu = ATMega1280::cpu();
  cpu.port_b.port = 0xff;
  ATMega1280::halt();
}
