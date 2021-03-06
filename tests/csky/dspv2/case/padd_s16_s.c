#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn padd.s16.s\n");

    for (i = 0;
         i < sizeof(samples_padd_s16_s)/sizeof(struct binary_calculation);
         i++) {
        TEST(test_padd_s16_s(samples_padd_s16_s[i].op1, samples_padd_s16_s[i].op2)
                     == samples_padd_s16_s[i].result);
    }
    return done_testing();
}
