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
        printf("count = %" PRIu64 ", y1 = %u, y2=%u, y3 = %u\n",
                count, y1, y2, y3);
        x1 = y1;
        x2 = y2;
        x3 = y3;
    }
}
