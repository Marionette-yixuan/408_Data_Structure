//
// Created by マリオネット on 2021/8/11.
//

#include "GraphTraverse.h"

void InitGraph(MatGraph *matGraph, const ElemType vertexes[], bool edges[][8], int vertexNum) {
    matGraph->vertexNum = vertexNum;
    int edgeNum = 0, i = 0, j = 0;
    for (; i < vertexNum; i++)
        matGraph->vertexes[i] = vertexes[i];
    for (; i < MaxGraphVertex; i++)
        matGraph->vertexes[i] = '\0';
    for (i = 0; i < vertexNum; i++) {
        for (j = 0; j < vertexNum; j++) {
            matGraph->edges[i][j] = edges[i][j];
            edgeNum += edges[i][j];
        }
        for (; j < MaxGraphVertex; j++)
            matGraph->edges[i][j] = false;
    }
    for (; i < MaxGraphVertex; i++) {
        for (j = 0; j < MaxGraphVertex; j++)
            matGraph->edges[i][j] = false;
    }
    matGraph->edgeNum = edgeNum >> 1;
}

int NextNeighbour(MatGraph matGraph, int verIndex, int lastIndex) {
    bool *edge = matGraph.edges[verIndex];          // 取出邻接矩阵中verIndex所对应的行
    for (int i = lastIndex + 1; i < matGraph.vertexNum; i++)
        if (*(edge + i)) return i;
    return -1;
}

void BFSTraverse(MatGraph matGraph) {
    /* 访问标记数组重置 */
    for (int i = 0; i < MaxGraphVertex; i++)
        visited[i] = false;
    /* 初始化辅助队列 */
    InitQueue(&supQueue);
    /* 依次广度优先访问每个未被访问的结点 */
    for (int i = 0; i < matGraph.vertexNum; i++)
        if (!visited[i]) BFS(matGraph, i);
}

void BFS(MatGraph matGraph, int verIndex) {
    /* 访问verIndex结点 */
    printf("%c ", matGraph.vertexes[verIndex]);
    visited[verIndex] = true;

    /* 顶点verIndex入队 */
    EnQueue(&supQueue, verIndex);         // 这里由于队列的元素是char类型，所以把下标转换成了char

    while (QueueLength(supQueue)) {
        int outIndex;
        DeQueue(&supQueue, &outIndex);
        for (int i = NextNeighbour(matGraph, outIndex, -1);
             i >= 0; i = NextNeighbour(matGraph, outIndex, i)) {
            if(!visited[i]) {
                printf("%c ", matGraph.vertexes[i]);
                visited[i] = true;
                EnQueue(&supQueue, (char) i);
            } // end if
        } //end for
    } // end while
}

/* 队列部分 */
bool InitQueue(LinkQueue *Q) {
    QNode *head_node = (QNode *) malloc(sizeof(QNode));
    if (!head_node) return false;
    head_node->next = NULL;
    Q->front = head_node;
    Q->rear = head_node;
    return true;
}

int QueueLength(LinkQueue Q) {
    int length = 0;
    QNode *node = Q.front;
    while (node->next) {
        node = node->next;
        length++;
    }
    return length;
}

bool EnQueue(LinkQueue *Q, int e) {
    QNode *new_node = (QNode *) malloc(sizeof(QNode));
    if (!new_node) return false;
    new_node->data = e;
    new_node->next = Q->rear->next;
    Q->rear->next = new_node;
    Q->rear = new_node;
    return true;
}

bool DeQueue(LinkQueue *Q, int *e) {
    if (Q->rear == Q->front) return false;
    QNode *de_node = Q->front->next;    // 头结点的下一个结点是首元结点
    *e = de_node->data;
    Q->front->next = de_node->next;
    if (!Q->front->next) Q->rear = Q->front;
    free(de_node);
    return true;
}

