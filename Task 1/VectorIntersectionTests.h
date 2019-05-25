#ifndef VKDB_VECTORINTERSECTIONTESTS_H
#define VKDB_VECTORINTERSECTIONTESTS_H


#include <iostream>
#include <vector>
#include <random>


class VectorIntersectionTests {

public:
    VectorIntersectionTests(int (* hashVectorIntersection)(std::vector<int>&, std::vector<int>&),
                            int (* binSearchVectorIntersection)(std::vector<int>&, std::vector<int>&),
                            int (* nativeVectorIntersection)(std::vector<int>&, std::vector<int>&));

    bool test(const std::string& testName, int testsNumber, int minSizeA, int maxSizeA, int minSizeB, int maxSizeB);

private:
    int getRandomInt(int min, int max);

    std::vector<int> generateRandomDistinctVector(int size);

    std::pair<int, int>
    getFunctionTimeAndResult(int (* f)(std::vector<int>&, std::vector<int>&), std::vector<int>& A, std::vector<int>& B);


    const int PLUS_INF = INT_MAX;
    const int MINUS_INF = INT_MIN;

    const char* NATIVE = "Native";
    const char* BIN_SEARCH = "Binary search";
    const char* HASH = "Hash";

    std::mt19937 gen;

    int (* hashVectorIntersection)(std::vector<int>&, std::vector<int>&);

    int (* binSearchVectorIntersection)(std::vector<int>&, std::vector<int>&);

    int (* nativeVectorIntersection)(std::vector<int>&, std::vector<int>&);
};


#endif //VKDB_VECTORINTERSECTIONTESTS_H
