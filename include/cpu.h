#ifndef CPU_H
#define CPU_H

#include "types.h"

typedef struct CPU {
    Word PC;            //program counter
    Byte SP;            //stack pointer

    Byte A, X, Y;       //registers

    Byte C : 1;         //status flag
    Byte Z : 1;         //status flag
    Byte I : 1;         //status flag
    Byte D : 1;         //status flag
    Byte B : 1;         //status flag
    Byte V : 1;         //status flag
    Byte N : 1;         //status flag
} CPU;

void cpu_reset(CPU* cpu);

#endif