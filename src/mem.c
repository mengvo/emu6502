#include "mem.h"
#include <stdio.h>

void mem_init(Mem* mem) {
    for(u32 i = 0; i < MAX_MEM; i++) {
        mem->Data[i] = 0;
    }
}