#ifndef VKDB_VECTORINTERSECTION_H
#define VKDB_VECTORINTERSECTION_H

#include <vector>

class VectorIntersection {
public:
    static int hashVectorInterSection(std::vector<int>& A, std::vector<int>& B);
    static int binSearchVectorInterSection(std::vector<int>& A, std::vector<int>& B);
    static int nativeVectorInterSection(std::vector<int>& A, std::vector<int>& B);

};


#endif //VKDB_VECTORINTERSECTION_H
