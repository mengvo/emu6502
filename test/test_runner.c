#include <stdio.h>

void test_mem_init();
void test_cpu_reset();
void test_lda_immediate();

int main() {
    test_mem_init();
    test_cpu_reset();
    test_lda_immediate();
    printf("All tests passed\n");
    return 0;
}