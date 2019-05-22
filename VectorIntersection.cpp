#include <unordered_set>
#include <bits/stdc++.h>

#include "VectorIntersection.h"

int VectorIntersection::hashVectorInterSecrion(std::vector<int>& A, std::vector<int>& B) {
    if (A.empty() || B.empty()) {
        return 0;
    }

    int result = 0;

    if (B.size() < A.size()) {
        std::swap(A, B);
    }

    std::unordered_set<int> elemsFromMin(A.begin(), A.end());

    for (int b : B) {
        if (result < A.size()) {
            result += elemsFromMin.count(b);
        } else {
            break;
        }
    }

    return result;
}

int VectorIntersection::binSearchVectorInterSecrion(std::vector<int>& A, std::vector<int>& B) {
    if (A.empty() || B.empty()) {
        return 0;
    }

    int result = 0;

    if (B.size() < A.size()) {
        std::swap(A, B);
    }

    std::sort(B.begin(), B.end());

    for (int a : A) {
        auto found = std::lower_bound(B.begin(), B.end(), a);
        if (found != B.end() && a == B[found - B.begin()]) {
            result++;
        }
    }

    return result;
}

int VectorIntersection::nativeVectorInterSecrion(std::vector<int>& A, std::vector<int>& B) {
    if (A.empty() || B.empty()) {
        return 0;
    }

    int result = 0;

    for (int a : A) {
        for (int b : B) {
            if (a == b) {
                result++;
            }
        }
    }

    return result;
}