//
// Created by マリオネット on 2021/8/11.
//

#include "MinSpanningTree.h"

void InitGraph(MatGraph *matGraph, const ElemType vertexes[], int edges[][6], int vertexNum) {
    matGraph->vertexNum = vertexNum;
    int edgeNum = 0, i = 0, j = 0;
    for (; i < vertexNum; i++)
        matGraph->vertexes[i] = vertexes[i];
    for (; i < MaxGraphVertex; i++)
        matGraph->vertexes[i] = '\0';
    for (i = 0; i < vertexNum; i++) {
        for (j = 0; j < vertexNum; j++) {
            matGraph->edges[i][j] = edges[i][j];
            edgeNum += (edges[i][j] != inf);
        }
        for (; j < MaxGraphVertex; j++)
            matGraph->edges[i][j] = inf;
    }
    for (; i < MaxGraphVertex; i++) {
        for (j = 0; j < MaxGraphVertex; j++)
            matGraph->edges[i][j] = inf;
    }
    matGraph->edgeNum = edgeNum >> 1;
}

void Prim(MatGraph matGraph) {
    int vertexNum = matGraph.vertexNum;
    /* 两个数组记录顶点入树和最小代价 */
    bool isAdd[MaxGraphVertex];
    int minWeight[2][MaxGraphVertex];       // 这里使用二维数组，第一行记录第i个顶点加入树的最小代价，第二行记录对应边的另一端为哪个顶点
    isAdd[0] = true;
    minWeight[0][0] = 0, minWeight[1][0] = 0;   // 从0号顶点开始，规定已在树中的顶点最小代价为0
    // 若isAdd[i] = true, 则minWeight[0][i] = 0
    for (int i = 1; i < MaxGraphVertex; i++) {       // 初始化剩余顶点
        isAdd[i] = false;
        minWeight[0][i] = matGraph.edges[0][i];
        if (matGraph.edges[0][i] != inf) minWeight[1][i] = 0;
        else minWeight[1][i] = -1;
    }

    /* 循环将顶点加入树中 */
    int verCount = 1;
    while (verCount < vertexNum) {
        /* 找到最小代价的结点 */
        int minCost = inf, minVertex = -1;
        for (int i = 0; i < vertexNum; i++) {
            if (isAdd[i]) continue;
            if (minWeight[0][i] < minCost) {
                minCost = minWeight[0][i];
                minVertex = i;
            }
        }
        int otherEnd = minWeight[1][minVertex];
        isAdd[minVertex] = true;
        minWeight[0][minVertex] = 0;
        printf("{%c, %c}, ", matGraph.vertexes[otherEnd], matGraph.vertexes[minVertex]);        // 将加入树的边输出

        /* 更新minWeight数组 */
        for (int i = 0; i < vertexNum; i++) {
            if (!isAdd[i]) continue;
            for (int j = 0; j < vertexNum; j++) {           // 只有当i顶点已经在树中时，才会更新和它相连的边的信息
                if (isAdd[j]) continue;         // 如果和i顶点相连的顶点已在树中，则跳过
                int newCost = matGraph.edges[i][j];
                if (newCost < minWeight[0][j]) {        // 如果边i, j的权值小于j顶点之前的最小的代价
                    minWeight[0][j] = newCost;          // 则更新j顶点的最小代价
                    minWeight[1][j] = i;                // 最小代价对应的另一个顶点为i
                }
            }
        }

        /* 统计加入树中的顶点数 */
        verCount = 0;
        for (int i = 0; i < matGraph.vertexNum; i++)
            verCount += isAdd[i];
    }
    printf("\n");
}

void Kruskal(MatGraph matGraph) {
    int vertexNum = matGraph.vertexNum;
    int unionSet[MaxGraphVertex];       // 给每个顶点进行标号，代替并查集
    for (int i = 0; i < vertexNum; i++)
        unionSet[i] = i;        // 初始为每个结点打上不同的标号

    /* 插入排序每条边 */
    EdgeList sortList = (EdgeNode *) malloc(sizeof(EdgeNode));
    sortList->weight = inf, sortList->next = NULL, sortList->ends[0] = -1, sortList->ends[1] = -1;
    EdgeNode *lastNode = sortList;
    for (int i = 0; i < vertexNum; i++) {        // 遍历所有边（邻接矩阵的上三角）
        for (int j = i; j < vertexNum; j++) {
            int weight = matGraph.edges[i][j];
            if (weight == inf || weight == 0) continue;         // 无边，跳过

            lastNode = sortList;
            while (lastNode->next && lastNode->next->weight < weight)        // 插入排序
                lastNode = lastNode->next;              // 结束后新边结点插在lastNode后面

            EdgeNode *newNode = (EdgeNode *) malloc(sizeof(EdgeNode));
            newNode->weight = weight;
            newNode->ends[0] = i, newNode->ends[1] = j;
            newNode->next = lastNode->next;
            lastNode->next = newNode;
        }
    }

    /* 循环加入每条边 */
    lastNode = sortList->next;
    while (lastNode) {
        /* 判断最小边的两顶点是否属于同一集合，属于则跳过，不属于则继续 */
        int end0 = lastNode->ends[0], end1 = lastNode->ends[1];
        lastNode = lastNode->next;
        int uni0 = unionSet[end0], uni1 = unionSet[end1];
        if (uni0 == uni1) continue;      // 如果两个顶点被打上同一个标号，说明它们属于一个连通分量，再连边则会出现回路

        /* 输出边的信息 */
        printf("{%c, %c}, ", matGraph.vertexes[end0], matGraph.vertexes[end1]);

        /* 将两边打上同一个标号（下标大的改为下标小的编号） */
        for (int i = 0; i < vertexNum; i++)
            if (unionSet[i] == uni1) unionSet[i] = uni0;
    }
    printf("\n");
}