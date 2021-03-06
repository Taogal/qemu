#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn pneg.s8.s\n");

    for (i = 0;
         i < sizeof(samples_pneg_s8_s)/sizeof(struct unary_calculation);
         i++) {
        TEST(test_pneg_s8_s(samples_pneg_s8_s[i].op1)
                     == samples_pneg_s8_s[i].result);
    }
    return done_testing();
}
