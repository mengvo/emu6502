#include <stdio.h>
#include "cpu.h"
#include "mem.h"

int main() {
    Mem mem;
    CPU cpu;
    cpu_reset(&cpu, &mem);
    mem.Data[cpu.PC] = 0xA9;
    mem.Data[cpu.PC + 1] = 0xFF;
    cpu_execute(&cpu, &mem, 2);
    return 0;
}