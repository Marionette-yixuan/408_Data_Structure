//
// Created by マリオネット on 2021/8/12.
//

#include "MinDistance.h"
#define Floyd

int main() {
#ifdef BFS
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
#endif
#ifdef Dijkstra
    MaDGraph maDGraph;
    const unsigned short verNum = 5;
    int edges[verNum][verNum] = {
        {inf, 10 , inf, inf, 5  },
        {inf, inf, 1  , inf, 2  },
        {inf, inf, inf, 4  , inf},
        {7  , inf, 6  , inf, inf},
        {inf, 3  , 9  , 2  , inf}
    };
    ElemType vertexes[] = {'A', 'B', 'C', 'D', 'E'};
    InitDGraph(&maDGraph, vertexes, edges, sizeof(vertexes) / sizeof(vertexes[0]));
    DijkstraMinDistance(maDGraph, 3);
#endif
#ifdef Floyd
    MaDGraph maDGraph;
    const unsigned short verNum = 5;
    int edges[verNum][verNum] = {
        {0  , inf, 1  , inf, 10 },          // Floyd算法的过程导致对角线上必须为0，
        {inf, 0  , inf, 1  , 5  },          // 否则加减时还需判断一步，没必要
        {inf, 1  , 0  , inf, 7  },
        {inf, inf, inf, 0  , 1  },
        {inf, inf, inf, inf, 0  }
    };
    ElemType vertexes[] = {'A', 'B', 'C', 'D', 'E'};
    InitDGraph(&maDGraph, vertexes, edges, sizeof(vertexes) / sizeof(vertexes[0]));
    FloydMinDistance(maDGraph);
#endif
    return 0;
}