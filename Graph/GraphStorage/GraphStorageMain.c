//
// Created by マリオネット on 2021/7/31.
//

#include "GraphStorage.h"

int main() {
    CLLGraph cllGraph;
    ElemType vertexes[] = {'A', 'B', 'C', 'D'};
    InitGraph(&cllGraph, vertexes, sizeof(vertexes) / sizeof(ElemType));
    return 0;
}
