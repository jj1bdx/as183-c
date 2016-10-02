/*
 * AS183 internal state dumping code.
 * License: MIT license as follows:
 *
 * Copyright (c) 2014-2016 Kenji Rikitake.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy
 * of this software and associated documentation files (the "Software"), to
 * deal
 * in the Software without restriction, including without limitation the
 * rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

#define PRIME1 (30269)
#define PRIME2 (30307)
#define PRIME3 (30323)

#define INIT1 (3172)
#define INIT2 (9814)
#define INIT3 (20125)

#define INTERVAL (100000000)

int main(int argc, char *argv[]) {
    uint16_t x1 = INIT1;
    uint16_t x2 = INIT2;
    uint16_t x3 = INIT3;
    uint16_t y1, y2, y3;
    uint64_t count = 0;
    int keeploop = 1;

    while (keeploop) {
        y1 = (x1 * 171) % PRIME1;
        y2 = (x2 * 172) % PRIME2;
        y3 = (x3 * 170) % PRIME3;
        count++;
        printf("count = %" PRIu64 " y1 = %u y2 = %u y3 = %u\n",
                count, y1, y2, y3);
        x1 = y1;
        x2 = y2;
        x3 = y3;
    }
}
