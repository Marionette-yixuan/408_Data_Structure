//
// Created by マリオネット on 2021/7/31.
//

#include "GraphStorage.h"

int main() {
#ifdef CROSS_LINK_LIST
    CLLGraph cllGraph;
    ElemType vertexes[] = {'A', 'B', 'C', 'D'};
    InitGraph(&cllGraph, vertexes, sizeof(vertexes) / sizeof(ElemType));
    AddArc(&cllGraph, 'A', 'B', 0);
    AddArc(&cllGraph, 'A', 'C', 0);
    DelArc(&cllGraph, 'A', 'B');
#endif // CROSS_LINK_LIST
    return 0;
}
