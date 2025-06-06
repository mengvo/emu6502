#include <assert.h>
#include "mem.h"

void test_mem_init() {
    Mem mem;
    mem_init(&mem);

    for(u32 i = 0; i < MAX_MEM; i++) {
        assert(mem.Data[i] == 0);
    }
}