#ifndef MEM_H
#define MEM_H

#include "types.h"

enum { MAX_MEM = 1024 * 64 };

typedef struct Mem {
    Byte Data[MAX_MEM];
} Mem;

void mem_init(Mem* mem);

#endif
