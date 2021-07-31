//
// Created by マリオネット on 2021/7/31.
//

#include "GraphStorage.h"

void InitGraph(CLLGraph *cllGraph, const ElemType nodeValues[], int length) {
    /* 初始化顶点数、边数 */
    cllGraph->arcNum = 0;
    cllGraph->vertexNum = 0;

    /* nodeValues长度和最大顶点数取最小值作为循环次数 */
    int loopCount = MaxGraphVertex < length ? MaxGraphVertex : length;
    for (int i = 0; i < loopCount; i++) {
        /* 将新顶点的数据填入集合中 */
        cllGraph->vNodes[i].data = nodeValues[i];
        cllGraph->vNodes[i].firstIn = NULL;
        cllGraph->vNodes[i].firstOut = NULL;

        /* 增加顶点数 */
        cllGraph->vertexNum++;
    }
}

void AddArc(CLLGraph cllGraph, ElemType headValue, ElemType tailValue, int weight) {
    /* 头尾的顶点编号 & 顶点结点 */
    int headIndex = GetIndex(cllGraph, headValue), tailIndex = GetIndex(cllGraph, tailValue);
    VertexNode *headVNode = GetVNode(cllGraph, headValue), *tailVNode = GetVNode(cllGraph, tailValue);
    /* 创建新边结点 */
    ArcNode *arcNode = (ArcNode *) malloc(sizeof(ArcNode));
    arcNode->headVertex = headIndex;
    arcNode->tailVertex = tailIndex;
    arcNode->weight = weight;

    /* 插入十字链表 */
    ArcNode *lastHeadANode = headVNode->firstIn, *lastTailANode = tailVNode->firstOut;
    // TODO: 余下的操作 2021-07-31

}

int GetIndex(CLLGraph cllGraph, ElemType vertexValue) {
    for (int i = 0; i < cllGraph.vertexNum; i++)
        if (cllGraph.vNodes[i].data == vertexValue) return i;
    return -1;
}

VertexNode *GetVNode(CLLGraph cllGraph, ElemType vertexValue) {
    for (int i = 0; i < cllGraph.vertexNum; i++)
        if (cllGraph.vNodes[i].data == vertexValue) return &cllGraph.vNodes[i];
    return NULL;
}