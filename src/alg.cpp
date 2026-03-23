// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
    uint64_t max = 1;
    while (num != 1) {
        if (num % 2) {
            if (max < 3 * num + 1) {
                max = 3 * num + 1;
            }
            num = 3 * num + 1;
        } else {
            if (max < num / 2) {
                max = num / 2;
            }
            num = num / 2;
        }
    }
    return max;
}

unsigned int collatzLen(uint64_t num) {
    unsigned int lenght = 1;
    while (num != 1) {
        lenght++;
        if (num % 2) {
            num = 3 * num + 1;
        } else {
            num = num / 2;
        }
    }
    return lenght;
}

unsigned int seqCollatz(unsigned int* maxlen,
    uint64_t lbound,
    uint64_t rbound) {
    unsigned int num = 1;
    unsigned int max = 1;
    for (uint64_t i = lbound; i <= rbound; i++)
    {
        if (max < collatzLen(i)) {
            num = i;
        }
    }
    *maxlen = collatzLen(num);
    return num;
}
