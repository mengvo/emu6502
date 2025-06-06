#include "cpu.h"
#include <stdio.h>

void cpu_reset(CPU* cpu, Mem* mem) {
    cpu->PC = 0xFFFC;
    cpu->SP = 0x0100;
    cpu->C = cpu->Z = cpu->I = cpu->D = cpu->B = cpu->V = cpu->N = 0;
    cpu->A = cpu->X = cpu->Y = 0;
    mem_init(mem);
}