#include <stdint-gcc.h>

#include "Hashes.h"

uint32_t Hashes::wang(int32_t x) {
    x = (x + 0x479ab41d) + (x << 8);
    x = (x ^ 0xe4aa10ce) ^ (x >> 5);
    x = (x + 0x9942f0a6) - (x << 14);
    x = (x ^ 0x5aedd67d) ^ (x >> 3);
    x = (x + 0x17bea992) + (x << 7);
    return static_cast<uint32_t>(x);
}

uint32_t Hashes::jenkin(int32_t x) {
    x = (x+0x7ed55d16) + (x<<12);
    x = (x^0xc761c23c) ^ (x>>19);
    x = (x+0x165667b1) + (x<<5);
    x = (x+0xd3a2646c) ^ (x<<9);
    x = (x+0xfd7046c5) + (x<<3);
    x = (x^0xb55a4f09) ^ (x>>16);
    return static_cast<uint32_t>(x);
}

uint32_t Hashes::knuth(int32_t x) {
    x = static_cast<int32_t>(x * 2654435761 % 2 ^ 32);
    return static_cast<uint32_t>(x);
}