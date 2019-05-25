#include <map>
#include <unordered_set>
#include <climits>
#include <cmath>
#include <chrono>
#include <time.h>

#include "VectorIntersectionTests.h"

VectorIntersectionTests::VectorIntersectionTests(int (* hashVectorIntersection)(std::vector<int>&, std::vector<int>&),
                                                 int (* binSearchVectorIntersection)(std::vector<int>&,std::vector<int>&),
                                                 int (* nativeVectorIntersection)(std::vector<int>&, std::vector<int>&))
                                                    : hashVectorIntersection(hashVectorIntersection),
                                                      binSearchVectorIntersection(binSearchVectorIntersection),
                                                      nativeVectorIntersection(nativeVectorIntersection) {
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());

    gen = generator;
    gen.seed(static_cast<unsigned int>(time(nullptr)));
}

int VectorIntersectionTests::getRandomInt(int min, int max) {
    std::uniform_int_distribution<> distribution(min, max);

    return distribution(gen);
}

std::vector<int> VectorIntersectionTests::generateRandomDistinctVector(int size) {
    std::vector<int> result;

    std::unordered_set<int> set;
    while (set.size() != size) {
        set.insert(getRandomInt(MINUS_INF, PLUS_INF));
    }

    result.reserve(set.size());

    for (auto it = set.begin(); it != set.end();) {
        result.push_back(set.extract(it++).value());
    }

    return result;
}

std::pair<int, int>
VectorIntersectionTests::getFunctionTimeAndResult(int (* f)(std::vector<int>&, std::vector<int>&), std::vector<int>& A,
                                                  std::vector<int>& B) {
    const auto start = std::chrono::high_resolution_clock::now();

    int result = f(A, B);

    const auto stop = std::chrono::high_resolution_clock::now();

    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    return {result, duration.count()};
}

bool VectorIntersectionTests::test(const std::string& testName, int testsNumber, int minSizeA, int maxSizeA,
                                   int minSizeB, int maxSizeB) {
    std::cout << "\nRunning " << testName << " tests...\n\n";

    bool nativeInc = maxSizeA < 10001 && maxSizeB < 10001;

    std::map<std::string, int> testResults;

    testResults[HASH] = 0;
    testResults[BIN_SEARCH] = 0;
    if (nativeInc) {
        testResults[NATIVE] = 0;
    }

    for (int i = 1; i <= testsNumber; ++i) {
        std::vector<int> A = generateRandomDistinctVector(getRandomInt(minSizeA, maxSizeA));
        std::vector<int> B = generateRandomDistinctVector(getRandomInt(minSizeB, maxSizeB));

        std::pair<int, int> nativeResult = {0, 0};
        std::pair<int, int> binSearchResult = getFunctionTimeAndResult(binSearchVectorIntersection, A, B);
        std::pair<int, int> hashResult = getFunctionTimeAndResult(hashVectorIntersection, A, B);

        bool passed = binSearchResult.first == hashResult.first;

        if (nativeInc) {
            nativeResult = getFunctionTimeAndResult(nativeVectorIntersection, A, B);
            passed = passed && hashResult.first == nativeResult.first;
        }

        if (!passed) {
            std::cout << testName << " test number:" << i << " failed!\n ";

            std::cout << "Binary Search result: " << binSearchResult.first << "\n";

            std::cout << "HashSet result: " << hashResult.first << "\n";

            if (nativeInc) {
                std::cout << "Native result: " << nativeResult.first << "\n";
            }

            return false;
        } else {
            std::cout << testName << " test number: " << i << " passed!\n";

            int min = hashResult.second;

            if (min > binSearchResult.second) {
                min = binSearchResult.second;

                if (nativeInc && min > nativeResult.second) {
                    testResults[NATIVE]++;
                } else {
                    testResults[BIN_SEARCH]++;
                }
            } else {
                if (nativeInc && min > nativeResult.second) {
                    testResults[NATIVE]++;
                } else {
                    testResults[HASH]++;
                }
            }

            std::cout << "Binary Search passed in: " << binSearchResult.second << " ms.\n";

            std::cout << "HashSet passed in: " << hashResult.second << " ms.\n";

            if (nativeInc) {
                std::cout << "Native passed in: " << nativeResult.second << " ms.\n";
            }

            std::cout << "\n";
        }
    }

    std::cout << "Test results:\n";
    std::cout << "Binary Search was faster in " << testResults[BIN_SEARCH] << "/" << testsNumber << ".\n";
    std::cout << "Hash was faster in " << testResults[HASH] << "/" << testsNumber << ".\n";

    if (nativeInc) {
        std::cout << "Native was faster in " << testResults[NATIVE] << "/" << testsNumber << ".\n";
    }

    return true;
}