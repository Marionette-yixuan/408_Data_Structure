//
// Created by マリオネット on 2021/8/11.
//

#include "MinSpanningTree.h"

int main() {
    MatGraph myGraph;
    const unsigned short verNum = 6;
    int edges[verNum][verNum] = {
        {inf, 6  , 5  , 1  , inf, inf},
        {6  , inf, inf, 5  , 3  , inf},
        {5  , inf, inf, 4  , inf, 2  },
        {1  , 5  , 4  , inf, 6  , 4  },
        {inf, 3  , inf, 6  , inf, 6  },
        {inf, inf, 2  , 4  , 6  , inf}
    };
    ElemType vertexes[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    InitGraph(&myGraph, vertexes, edges, sizeof(vertexes) / sizeof(vertexes[0]));
    Prim(myGraph);
    Kruskal(myGraph);
    return 0;
}

