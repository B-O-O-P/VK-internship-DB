#include <iostream>
#include <vector>
#include <set>
#include <bits/stdc++.h>
#include <unordered_set>
#include <climits>
#include <cmath>
#include <random>
#include <chrono>
#include <time.h>

#include "VectorIntersection.h"
#include "VectorIntersectionTests.h"

int main() {
    VectorIntersectionTests tests(VectorIntersection::hashVectorInterSection,
                                  VectorIntersection::binSearchVectorInterSection,
                                  VectorIntersection::nativeVectorInterSection);

    if (tests.test("EMPTY", 1, 0, 0, 0, 0)) {
        std::cout << "\n_______________________\n"
                     "EMPTY TEST PASSED!\n\n";
    }

    if (tests.test("SMALL RANDOM", 100, 0, 10000, 0, 10000)) {
        std::cout << "\n_______________________\n"
                     "ALL SMALL RANDOM TESTS PASSED!\n\n";
    }

    if (tests.test("BIG RANDOM", 100, 0, 100000000, 0, 10000000)) {
        std::cout << "\n_______________________\n"
                     "ALL BIG RANDOM TESTS PASSED!\n\n";
    }

    if (tests.test("DIFFERENT SIZES", 100, 0, 1000, 0, 1000000)) {
        std::cout << "\n________________________________\n"
                     "ALL DIFFERENT SIZES TESTS PASSED!\n\n";
    }
    return 0;
}