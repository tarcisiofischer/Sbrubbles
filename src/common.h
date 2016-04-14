#ifndef COMMON_H
#define COMMON_H

#define force_inline __attribute__((always_inline))

typedef volatile unsigned char Register;

struct Port {
    Register pin;
    Register ddr;
    Register port;
};

#endif
