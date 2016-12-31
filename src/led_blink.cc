#include <core/cpu.h>

void configure_timer()
{
  ATMega1280::cli();

  auto &cpu = ATMega1280::cpu();

  cpu.TIMSK1 = 0x02; // Timer1 CompareA match interrupt enable

  cpu.TCCR1A = 0x00;
  cpu.TCCR1B = 0x00;

  // Configure WGM1 to set CTC_OCR1A mode (0 1 0 0)
  cpu.TCCR1A |= 0x00;
  cpu.TCCR1B |= 0x08;

  // Select clock = clkIO / 256
  // clkIO == 16Mhz
  // clock = 62.5khz
  cpu.TCCR1A |= 0x00;
  cpu.TCCR1B |= 0x04;

  const unsigned int time = 0.1 * 62500; // 100 ms
  cpu.OCR1AH = (time & 0xff00) >> 8;
  cpu.OCR1AL = (time & 0x00ff) >> 0;

  ATMega1280::sei();
}

void my_int()
{
  auto &cpu = ATMega1280::cpu();
  cpu.port_b.port = ~cpu.port_b.port;
}

void install_interrupt()
{
  typedef void (myfunc)();
  myfunc** f_ = (myfunc**)(ATMega1280::memory_begin());
  *f_ = &my_int;
}

int main()
{
  auto &cpu = ATMega1280::cpu();

  cpu.port_b.ddr = 0xff;
  cpu.port_b.port = 0x00;

  install_interrupt();
  configure_timer();

  while(1);
}
