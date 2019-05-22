#ifndef VKDB_VECTORINTERSECTION_H
#define VKDB_VECTORINTERSECTION_H

#include <vector>

class VectorIntersection {
public:
    static int hashVectorInterSecrion(std::vector<int>& A, std::vector<int>& B);
    static int binSearchVectorInterSecrion(std::vector<int>& A, std::vector<int>& B);
    static int nativeVectorInterSecrion(std::vector<int>& A, std::vector<int>& B);

};


#endif //VKDB_VECTORINTERSECTION_H
