typedef unsigned char uint8;

int main()
{
    asm volatile ("cli");
    uint8 *ddrb = (unsigned char*)0x24;
    uint8 *portb = (unsigned char*)0x25;

    *ddrb = 0xff;
    *portb = 0xff;

    long int i = 0xffff;
    while (1) {
        while (--i);
        *portb = ~*portb;
        i = 0xffff;
    }

    return 0;
}
