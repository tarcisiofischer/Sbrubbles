#include <cpu.h>

const long int COUNTDOWN = 0xffff;

int main()
{
  auto &cpu = ATMega1280::cpu();
  cpu.cli();

  cpu.port_b.ddr = 0xff;
  cpu.port_b.port = 0xff;

  long int i = COUNTDOWN;
  while (1) {
    while (--i);
    cpu.port_b.port = ~cpu.port_b.port;
    i = COUNTDOWN;
  }

  return 0;
}
