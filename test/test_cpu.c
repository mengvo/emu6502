#include <assert.h>
#include "cpu.h"
#include "mem.h"

void test_cpu_reset() {
    CPU cpu;
    Mem mem;
    cpu_reset(&cpu, &mem);

    assert(cpu.PC == 0xFFFC);
    assert(cpu.SP == 0x01);
    assert(cpu.C == 0 && cpu.Z == 0 && cpu.I == 0 && cpu.D == 0 && 
           cpu.B == 0 && cpu.V == 0 && cpu.N == 0);
    assert(cpu.A == 0 && cpu.X == 0 && cpu.Y == 0);
}

void test_lda_immediate() {
    CPU cpu;
    Mem mem;

    cpu.PC = 0x1217;
    mem.Data[0x1217] = INS_LDA_IM;

    mem.Data[0x1218] = 0x17;
    cpu_execute(&cpu, &mem, 2);
    assert(cpu.A == 0x17);
    assert(cpu.Z == 0);
    assert(cpu.N == 0);

    cpu.PC = 0x1217;
    mem.Data[0x1218] = 0;
    cpu_execute(&cpu, &mem, 2);
    assert(cpu.A == 0);
    assert(cpu.Z == 1);
    assert(cpu.N == 0);

    cpu.PC = 0x1217;
    mem.Data[0x1218] = 0xFF;
    cpu_execute(&cpu, &mem, 2);
    assert(cpu.A == 0xFF);
    assert(cpu.Z == 0);
    assert(cpu.N == 1);
}
