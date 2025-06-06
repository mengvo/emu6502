#include "cpu.h"
#include <stdio.h>

void cpu_reset(CPU* cpu, Mem* mem) {
    cpu->PC = 0xFFFC;
    cpu->SP = 0x0100;
    cpu->C = cpu->Z = cpu->I = cpu->D = cpu->B = cpu->V = cpu->N = 0;
    cpu->A = cpu->X = cpu->Y = 0;
    mem_init(mem);
}

Byte cpu_fetchbyte(CPU* cpu, Mem* mem, u32* cycles) {
    Byte data = mem->Data[cpu->PC++];
    (*cycles)--;
    return data;
}

void cpu_execute(CPU* cpu, Mem* mem, u32 cycles) {
    while(cycles > 0) {
        Byte ins = cpu_fetchbyte(cpu, mem, &cycles);
        switch(ins) {
            case INS_LDA_IM:
                Byte value = cpu_fetchbyte(cpu, mem, &cycles);
                cpu->A = value;
                cpu->Z = (cpu->A == 0);
                cpu->N = (cpu->A & 0b10000000) > 0;
                break;
        }
    }
}