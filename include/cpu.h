#ifndef CPU_H
#define CPU_H

#include "types.h"
#include "mem.h"

#define INS_LDA_IM 0xA9

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

void cpu_reset(CPU* cpu, Mem* mem);
Byte cpu_fetchbyte(CPU* cpu, Mem* mem, u32* cycles);
void cpu_execute(CPU* cpu, Mem* mem, u32 cycles);

#endif