#include <stdio.h>
#include "cpu.h"
#include "mem.h"

int main() {
    Mem mem;
    CPU cpu;
    cpu_reset(&cpu, &mem);
    printf("PC: 0x%x\n", cpu.PC);
    mem.Data[cpu.PC] = 0xA9;
    mem.Data[cpu.PC + 1] = 0xFF;
    printf("Values at mem[PC]: 0x%x\n", mem.Data[cpu.PC]);
    printf("Values at mem[PC + 1]: 0x%x\n", mem.Data[cpu.PC + 1]);
    cpu_execute(&cpu, &mem, 2);
    printf("A register: 0x%x\nZ flag: %d\nN flag: %d\n", cpu.A, cpu.Z, cpu.N);
    return 0;
}