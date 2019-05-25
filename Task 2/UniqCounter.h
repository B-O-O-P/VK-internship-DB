#ifndef VKDB2_UNIQCOUNTER_H
#define VKDB2_UNIQCOUNTER_H

#include <vector>

class UniqCounter {
public:
    explicit UniqCounter(uint8_t rb = 8);

    void add(int32_t x);

    int get_uniq_num() const;

private:
    uint8_t countLeadingZeros(uint32_t x);

    double getAlpha() const;

    double pow2_32() const;

    double negPow2_32() const;

    uint8_t registerBit;
    uint32_t bitSize;
    std::vector<uint8_t> registers;

    const uint32_t BITS_NUMBER = 32;
};


#endif //VKDB2_UNIQCOUNTER_H
