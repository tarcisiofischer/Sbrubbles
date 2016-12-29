#include <core/cpu.h>

int main()
{
  auto &cpu = ATMega1280::cpu();
  cpu.cli();

  cpu.port_b.ddr = 0xff;
  cpu.port_b.port = 0xff;

  while (1) {
    int j = 1000; while (--j) { int i = 1000; while (--i); };
    cpu.port_b.port = ~cpu.port_b.port;
  }

  return 0;
}
