/* ---------------------------------------------------------------------------
 * Copyright (C) 2016 CSKY Limited. All rights reserved.
 *
 * Redistribution and use of this software in source and binary forms,
 * with or without modification, are permitted provided that the following
 * conditions are met:
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 *   * Neither the name of CSKY Ltd. nor the names of CSKY's contributors may
 *     be used to endorse or promote products derived from this software without
 *     specific prior written permission of CSKY Ltd.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
 * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 * -------------------------------------------------------------------------- */
#include "testsuite.h"
#include "test_device.h"
#include "dsp_insn.h"
#define TEST_TIMES      14
int main(void)
{
    int i = 0;

    init_testsuite("Testing insn PADDH.S16 \n");

    /*
     * PADDH.S16
     * rz[15:0] = (rx[15:0] + ry[15:0])/2,
     * rz[31:16] = (rx[31:16] + ry[31:16])/2, signed
     */
    struct binary_calculation bin_sample[TEST_TIMES] = {
        {0x56785678, 0xc000b000, 0x0b3c033c},
        {0x12345678, 0x12345678, 0x1234d678},
        {0x8080c0c0, 0x9090a0a0, 0x088830b0},
        {0xf0007fff, 0x90000001, 0xc000c000},
        {0X00000000, 0X00000000, 0x00000000},
        {0X00000001, 0X00010000, 0x00000000},
        {0X00010001, 0X00010001, 0x00010001},
        {0XFFFF0001, 0X0001FFFF, 0x00000000},
        {0XFFFFFFFF, 0XFFFF0000, 0xffff0000},
        {0X0000FFFF, 0XFFFFFFFF, 0x0000ffff},
        {0X60003000, 0X30006000, 0xc800c800},
        {0X80018001, 0X80000001, 0x0000c001},
        {0X7FFF8000, 0X7FFF8000, 0xffff0000},
        {0X7FFF8000, 0X80007FFF, 0x00000000},
    };

    for (i = 0; i < TEST_TIMES; i++) {
        TEST(test_paddh_s16(bin_sample[i].op1, bin_sample[i].op2)
                     == bin_sample[i].result);
    }

    return done_testing();
}

