#ifndef COMMON_H
#define COMMON_H

#define inline __attribute__((always_inline))  __inline__

typedef unsigned char Register;

struct Port {
    Register pin;
    Register ddr;
    Register port;
};

#endif
