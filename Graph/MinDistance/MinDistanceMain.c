//
// Created by マリオネット on 2021/8/12.
//

#include "MinDistance.h"

int main() {
    MatGraph myGraph;
    const unsigned short verNum = 8;
    bool edges[verNum][verNum] = {
        {0, 1, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 1, 1, 0},
        {0, 0, 1, 0, 0, 0, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 0, 1, 0},
        {0, 0, 1, 1, 0, 1, 0, 1},
        {0, 0, 0, 1, 0, 0, 1, 0}
    };
    ElemType vertexes[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    InitGraph(&myGraph, vertexes, edges, sizeof(vertexes) / sizeof(vertexes[0]));
    BFSMinDistance(myGraph, 0);
    return 0;
}