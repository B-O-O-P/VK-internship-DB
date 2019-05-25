#ifndef VKDB2_HASHES_H
#define VKDB2_HASHES_H


struct Hashes {
    static uint32_t knuth(int32_t x);

    static uint32_t jenkin(int32_t x);

    static uint32_t wang(int32_t x);
};


#endif //VKDB2_HASHES_H
