#include <stdint-gcc.h>
#include <cmath>

#include "UniqCounter.h"
#include "Hashes.h"

UniqCounter::UniqCounter(uint8_t rb) : registerBit(rb), bitSize(static_cast<uint32_t>(1 << rb)),
                                       registers(bitSize, 0) {}

void UniqCounter::add(int32_t x) {
    uint32_t hash = Hashes::wang(x);
    uint32_t index = hash >> (BITS_NUMBER - registerBit);
    uint8_t rank = countLeadingZeros(hash << registerBit);
    registers[index] = std::max(registers[index], rank);
}

int UniqCounter::get_uniq_num() const {
    double count;
    double sum = 0.0;

    for (unsigned char r : registers) {
        sum += 1.0 / (1 << r);
    }

    count = getAlpha() / sum;

    if (count > 2.5 * bitSize) {
        if (count > (1.0 / 30.0) * pow2_32()) {
            count = negPow2_32() * log(1.0 - (count / pow2_32()));
        }
    } else {
        uint32_t zeros = 0;

        for (unsigned char i : registers) {
            if (!i) {
                zeros++;
            }
        }

        if (zeros) {
            count = bitSize * std::log(static_cast<double>(bitSize) / zeros);
        }
    }

    return static_cast<int32_t>(count);
}

double UniqCounter::pow2_32() const {
    return 1ULL << 32;
}

double UniqCounter::negPow2_32() const {
    return -pow2_32();
}

double UniqCounter::getAlpha() const {
    double alpha;

    switch (bitSize) {
        case 16: {
            alpha = 0.673;
            break;
        }
        case 32: {
            alpha = 0.697;
            break;
        }
        case 64: {
            alpha = 0.709;
            break;
        }
        default: {
            alpha = 0.7213 / (1.0 + 1.079 / bitSize);
        }
    }

    return alpha * bitSize * bitSize;
}

uint8_t UniqCounter::countLeadingZeros(uint32_t x) {
    uint8_t count = 1;
    while (count <= (BITS_NUMBER - registerBit) && !(x & 0x80000000)) {
        count++;
        x <<= 1;
    }
    return count;
}