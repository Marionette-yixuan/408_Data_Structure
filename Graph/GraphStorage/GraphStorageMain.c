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

#ifdef ADHERE_MULTI_LIST
    AMLGraph amlGraph;
    ElemType vertexes[] = {'A', 'B', 'C', 'D'};
    InitGraph(&amlGraph, vertexes, sizeof(vertexes) / sizeof(ElemType));
    AddArc(&amlGraph, 'A', 'B', 0);
    AddArc(&amlGraph, 'A', 'C', 0);
#endif // ADHERE_MULTI_LIST
    return 0;
}
