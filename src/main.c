#include <stdio.h>
#include "cpu.h"
#include "mem.h"

int main() {
    Mem mem;
    CPU cpu;
    cpu_reset(&cpu, &mem);
    return 0;
}