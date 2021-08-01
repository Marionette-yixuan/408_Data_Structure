//
// Created by マリオネット on 2021/7/31.
//

#include "GraphStorage.h"

#ifdef CROSS_LINK_LIST

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
    for (int i = loopCount; i < MaxGraphVertex; i++) {
        /* 清空后续结点空间的信息 */
        cllGraph->vNodes[i].data = '\0';
        cllGraph->vNodes[i].firstIn = NULL;
        cllGraph->vNodes[i].firstOut = NULL;
    }
}

void AddArc(CLLGraph *cllGraph, ElemType headValue, ElemType tailValue, int weight) {
    /* 头尾的顶点编号 & 顶点结点 */
    int headIndex = GetIndex(*cllGraph, headValue), tailIndex = GetIndex(*cllGraph, tailValue);
    VertexNode *headVNode = &cllGraph->vNodes[headIndex], *tailVNode = &cllGraph->vNodes[tailIndex];
    /* 创建新边结点 */
    ArcNode *arcNode = (ArcNode *) malloc(sizeof(ArcNode));
    arcNode->headVertex = headIndex;
    arcNode->tailVertex = tailIndex;
    arcNode->weight = weight;
    arcNode->headNext = NULL;       // 下一条边初始都置NULL
    arcNode->tailNext = NULL;

    /* 插入十字链表 */
    ArcNode *lastHeadANode = headVNode->firstIn, *lastTailANode = tailVNode->firstOut;
    if (!lastHeadANode) {        // 若弧头顶点没有第一条边，则直接连到firstIn上
        headVNode->firstIn = arcNode;
    } else {                     // 否则找到最后一条弧头边，连在它的后面
        while (lastHeadANode->headNext) lastHeadANode = lastHeadANode->headNext;
        lastHeadANode->headNext = arcNode;
    }
    if (!lastTailANode) {        // 弧尾顶点插入方法同理
        tailVNode->firstOut = arcNode;
    } else {
        while (lastTailANode->tailNext) lastTailANode = lastTailANode->tailNext;
        lastTailANode->tailNext = arcNode;
    }
    cllGraph->arcNum++;
}

void DelArc(CLLGraph *cllGraph, ElemType headValue, ElemType tailValue) {
    /* 头尾的顶点编号 & 顶点结点 */
    int headIndex = GetIndex(*cllGraph, headValue), tailIndex = GetIndex(*cllGraph, tailValue);
    VertexNode *headVNode = &cllGraph->vNodes[headIndex], *tailVNode = &cllGraph->vNodes[tailIndex];

    /* 分别找到要删除边在头尾端点的上一条边 */
    ArcNode *lastHeadANode = headVNode->firstIn, *lastTailANode = tailVNode->firstOut, *delNode = NULL;
    // 这里没有做异常处理，默认要删除的边都在图中存在
    /* 判断是否第一条边是否就是目标边 */
    if (lastHeadANode->tailVertex == tailIndex) {        // 在弧头处只需判断弧尾是否正确
        delNode = lastHeadANode;
        headVNode->firstIn = delNode->headNext;
    } else while (lastHeadANode->headNext->tailVertex != tailIndex) lastHeadANode = lastHeadANode->headNext;
    if (lastTailANode->headVertex == headIndex) {        // 在弧尾处只需判断弧头是否正确
        delNode = lastTailANode;
        tailVNode->firstOut = delNode->tailNext;
    } else while (lastTailANode->tailNext->headVertex != headIndex) lastTailANode = lastTailANode->tailNext;

    if (!delNode) {             // 如果此时delNode仍为NULL，说明它不是头尾端点的第一条边（上面两个if都没进去）
        delNode = lastHeadANode->headNext;
        lastHeadANode->headNext = delNode->headNext;
        lastTailANode->tailNext = delNode->tailNext;
    }
    free(delNode);
    cllGraph->arcNum--;
}

int GetIndex(CLLGraph cllGraph, ElemType vertexValue) {
    for (int i = 0; i < cllGraph.vertexNum; i++)
        if (cllGraph.vNodes[i].data == vertexValue) return i;
    return -1;
}

#endif // CROSS_LINK_LIST

#ifdef ADHERE_MULTI_LIST

void InitGraph(AMLGraph *amlGraph, const ElemType nodeValues[], int length) {
    /* 初始化顶点数、边数 */
    amlGraph->arcNum = 0;
    amlGraph->vertexNum = 0;

    /* nodeValues长度和最大顶点数取最小值作为循环次数 */
    int loopCount = MaxGraphVertex < length ? MaxGraphVertex : length;
    for (int i = 0; i < loopCount; i++) {
        /* 将新顶点的数据填入集合中 */
        amlGraph->vNodes[i].data = nodeValues[i];
        amlGraph->vNodes[i].firstArc = NULL;

        /* 增加顶点数 */
        amlGraph->vertexNum++;
    }
    for (int i = loopCount; i < MaxGraphVertex; i++) {
        /* 清空后续结点空间的信息 */
        amlGraph->vNodes[i].data = '\0';
        amlGraph->vNodes[i].firstArc = NULL;
    }
}

void AddArc(AMLGraph *amlGraph, ElemType endValues[], int weight) {
    // TODO: 邻接多重表添加一条边
}

#endif // ADHERE_LINK_LIST