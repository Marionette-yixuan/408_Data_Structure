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
    /* 这里使用的是插在链表的最后面，而邻接多重表使用的是插在表的最前端（很明显插在头部比较快） */
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
    } else {
        while (lastHeadANode->headNext->tailVertex != tailIndex) lastHeadANode = lastHeadANode->headNext;
        delNode = lastHeadANode->headNext;
        lastHeadANode->headNext = delNode->headNext;
    }
    if (lastTailANode->headVertex == headIndex) {        // 在弧尾处只需判断弧头是否正确
        delNode = lastTailANode;
        tailVNode->firstOut = delNode->tailNext;
    } else {
        while (lastTailANode->tailNext->headVertex != headIndex) lastTailANode = lastTailANode->tailNext;
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

void AddArc(AMLGraph *amlGraph, ElemType iValue, ElemType jValue, int weight) {
    /* 头尾的顶点编号 & 顶点结点 */
    int iIndex = GetIndex(*amlGraph, iValue), jIndex = GetIndex(*amlGraph, jValue);
    VertexNode *iVNode = &amlGraph->vNodes[iIndex], *jVNode = &amlGraph->vNodes[jIndex];
    /* 创建新边结点 */
    ArcNode *arcNode = (ArcNode *) malloc(sizeof(ArcNode));
    arcNode->endVertexes[0] = iIndex;           // 所有0下标对应的都是i顶点，1下标对应j顶点，保持一致
    arcNode->endVertexes[1] = jIndex;
    arcNode->weight = weight;

    /* 插入邻接多重表，直接插在顶点结点的fisrtArc处，为了方便找到同顶点的下一条边 */
    arcNode->nextArcs[0] = iVNode->firstArc;
    arcNode->nextArcs[1] = jVNode->firstArc;
    iVNode->firstArc = arcNode;
    jVNode->firstArc = arcNode;

    amlGraph->arcNum++;
}

void DelArc(AMLGraph *amlGraph, ElemType iValue, ElemType jValue) {
    // TODO: 邻接多重表删除边
    /* 头尾的顶点编号 & 顶点结点 */
    int iIndex = GetIndex(*amlGraph, iValue), jIndex = GetIndex(*amlGraph, jValue);
    VertexNode *iVNode = &amlGraph->vNodes[iIndex], *jVNode = &amlGraph->vNodes[jIndex];

    /* 分别找到要删除结点在两个端点链表的上一条边 */
    ArcNode *iLastANode = iVNode->firstArc, *jLastANode = jVNode->firstArc, *delNode = NULL;
    int isIFirst = IsArc(*iLastANode, iIndex, jIndex), isJFirst = IsArc(*jLastANode, iIndex, jIndex);
    /* 处理i端点 */
    if (isIFirst != -1) {        // i端点的第一条边就是要删除的边
        delNode = iLastANode;       // 删除的边结点
        iVNode->firstArc = delNode->nextArcs[isIFirst];         // isIFirst代表删除的边中i端点的下一条边存储在哪个位置
    } else {
        while (true) {
            /* 判断边结点的nextArcs的0位置还是1位置是i端点，然后循环找到删除结点的上一个结点 */
            if (iLastANode->endVertexes[0] == iIndex) {
                if (IsArc(*iLastANode->nextArcs[0], iIndex, jIndex) != -1) break;
                else iLastANode = iLastANode->nextArcs[0];
            } else if (iLastANode->endVertexes[1] == iIndex) {
                if (IsArc(*iLastANode->nextArcs[1], iIndex, jIndex) != -1) break;
                else iLastANode = iLastANode->nextArcs[1];
            }
        }
        /* 找到删除结点的上一个结点后，将指针越过删除结点指向下一个结点 */
        if (iLastANode->endVertexes[0] == iIndex) {
            delNode = iLastANode->nextArcs[0];
            iLastANode->nextArcs[0] = delNode->nextArcs[IsArc(*delNode, iIndex, jIndex)];
        } else {        // iLastANode->endVertexes[1] == iIndex
            delNode = iLastANode->nextArcs[1];
            iLastANode->nextArcs[1] = delNode->nextArcs[IsArc(*delNode, iIndex, jIndex)];
        }
    }
    /* 处理j端点 */
    if (isJFirst != -1) {
        delNode = jLastANode;
        jVNode->firstArc = delNode->nextArcs[1 - isJFirst];         // 上面判断isJFirst时依旧是先i后j，所以这里0代表j在1，1代表j在0
    } else {
        while (true) {
            if (jLastANode->endVertexes[0] == jIndex) {
                if (IsArc(*jLastANode->nextArcs[0], iIndex, jIndex) != -1) break;
                else jLastANode = jLastANode->nextArcs[0];
            } else if (jLastANode->endVertexes[1] == jIndex) {
                if (IsArc(*jLastANode->nextArcs[1], iIndex, jIndex) != -1) break;
                else jLastANode = jLastANode->nextArcs[1];
            }
        }
        if (jLastANode->endVertexes[0] == jIndex) {      // 处理i结点时一定已经找到了要删除的结点delNode，所以不会出现delNode为NULL的情况
            jLastANode->nextArcs[0] = delNode->nextArcs[1 - IsArc(*delNode, iIndex, jIndex)];
        } else {        // iLastANode->endVertexes[1] == jIndex
            jLastANode->nextArcs[1] = delNode->nextArcs[1 - IsArc(*delNode, iIndex, jIndex)];
        }
    }

    free(delNode);
    amlGraph->arcNum--;
}

int GetIndex(AMLGraph amlGraph, ElemType vertexValue) {
    for (int i = 0; i < amlGraph.vertexNum; i++)
        if (amlGraph.vNodes[i].data == vertexValue) return i;
    return -1;
}

int IsArc(ArcNode targetNode, int iIndex, int jIndex) {
    if (targetNode.endVertexes[0] == iIndex && targetNode.endVertexes[1] == jIndex)
        return 0;
    else if (targetNode.endVertexes[0] == jIndex && targetNode.endVertexes[1] == iIndex)
        return 1;
    else return -1;
}

#endif // ADHERE_LINK_LIST