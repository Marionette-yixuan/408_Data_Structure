//
// Created by マリオネット on 2021/8/12.
//

#include "MinDistance.h"

// BFS
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

int NextNeighbour(MatGraph matGraph, int verIndex) {
    bool *edge = matGraph.edges[verIndex];          // 取出邻接矩阵中verIndex所对应的行
    for (int i = 0; i < matGraph.vertexNum; i++)
        if (*(edge + i) && !visited[i]) return i;   // 有边，且未被访问
    return -1;
}

void BFSMinDistance(MatGraph matGraph, int sourceIndex) {       // 一定是连通图
    InitQueue(&supQueue);
    /* 两个结果数组：path[i]代表从源点访问到i顶点的最后一条路径，dis[i]代表源点到i顶点的路径长度 */
    int dis[MaxGraphVertex], path[MaxGraphVertex];
    for (int i = 0; i < MaxGraphVertex; i++) {
        dis[i] = inf;
        path[i] = -1;
    }
    dis[sourceIndex] = 0, path[sourceIndex] = sourceIndex;      // 标记源点
    visited[sourceIndex] = true;
    EnQueue(&supQueue, sourceIndex);
    while (QueueLength(supQueue)) {
        int outIndex;
        DeQueue(&supQueue, &outIndex);
        for (int i = NextNeighbour(matGraph, outIndex);
             i >= 0; i = NextNeighbour(matGraph, outIndex)) {
            if (!visited[i]) {
                /* 更新路径信息 */
                dis[i] = dis[outIndex] + 1;         // i顶点路径长度为outIndex（上一层顶点）+1
                path[i] = outIndex;                 // i顶点的访问前驱为outIndex顶点
                visited[i] = true;
                EnQueue(&supQueue, i);
            } // end if
        } // end for
    } // end while

    /* 输出路径信息 */
    for (int i = 0; i < matGraph.vertexNum; i++) {
        printf("源点%c到顶点%c的路径长度为: %d, 路径为: ",
               matGraph.vertexes[sourceIndex], matGraph.vertexes[i],
               dis[i]);
        int lastVer = i;
        while (lastVer != sourceIndex) {
            printf("%c<-", matGraph.vertexes[lastVer]);
            lastVer = path[lastVer];
        }
        printf("%c\n", matGraph.vertexes[lastVer]);
    }
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
// end BFS

// DijkstraMinDistance
void InitDGraph(MaDGraph *maDGraph, const ElemType vertexes[], int edges[][5], int vertexNum) {
    maDGraph->vertexNum = vertexNum;
    int edgeNum = 0, i = 0, j = 0;
    for (; i < vertexNum; i++)
        maDGraph->vertexes[i] = vertexes[i];
    for (; i < MaxGraphVertex; i++)
        maDGraph->vertexes[i] = '\0';
    for (i = 0; i < vertexNum; i++) {
        for (j = 0; j < vertexNum; j++) {
            maDGraph->edges[i][j] = edges[i][j];
            edgeNum += edges[i][j] != inf;
        }
        for (; j < MaxGraphVertex; j++)
            maDGraph->edges[i][j] = inf;
    }
    for (; i < MaxGraphVertex; i++) {
        for (; j < MaxGraphVertex; j++)
            maDGraph->edges[i][j] = inf;
    }
    maDGraph->edgeNum = edgeNum;
}

void DijkstraMinDistance(MaDGraph maDGraph, int sourceIndex) {
    int vertexNum = maDGraph.vertexNum;
    /* 维护三个数组 */
    bool final[MaxGraphVertex];                 // 标记是否已找到i顶点的最短路径
    int dis[MaxGraphVertex], path[MaxGraphVertex];      // i顶点的最短路径长度、最短路径直接前驱
    for (int i = 0; i < MaxGraphVertex; i++) {
        final[i] = false;
        dis[i] = inf, path[i] = -1;
    }
    final[sourceIndex] = true;
    dis[sourceIndex] = 0, path[sourceIndex] = sourceIndex;      // 标记源点

    /* 初始更新dis和path数组 */
    for (int i = 0; i < vertexNum; i++) {
        if (maDGraph.edges[sourceIndex][i] != inf) {
            dis[i] = maDGraph.edges[sourceIndex][i];
            path[i] = sourceIndex;
        }
    }

    int finalCount = 1;
    while (finalCount < vertexNum) {
        /* 选出最小的dis，加入到路径中 */
        int minDis = inf, minIndex = -1;
        for (int i = 0; i < vertexNum; i++) {
            if (final[i]) continue;      // 如果已经有最短路径，则跳过
            if (dis[i] < minDis) {       // 挑出最小的dis
                minDis = dis[i];
                minIndex = i;
            }
        }
        final[minIndex] = true;

        /* 根据最新加入的顶点更新dis和path数组 */
        for (int i = 0; i < vertexNum; i++) {
            int weight = maDGraph.edges[minIndex][i];
            if(weight == inf)   continue;
            if(dis[minIndex] + weight < dis[i]) {       // 找到了到i结点更短的路径
                dis[i] = dis[minIndex] + weight;
                path[i] = minIndex;
            }
        }

        /* 统计加入的顶点数 */
        finalCount = 0;
        for (int i = 0; i < vertexNum; i++)
            finalCount += final[i];
    }

    /* 输出路径信息 */
    for (int i = 0; i < maDGraph.vertexNum; i++) {
        printf("源点%c到顶点%c的路径长度为: %d, 路径为: ",
               maDGraph.vertexes[sourceIndex], maDGraph.vertexes[i],
               dis[i]);
        int lastVer = i;
        while (lastVer != sourceIndex) {
            printf("%c<-", maDGraph.vertexes[lastVer]);
            lastVer = path[lastVer];
        }
        printf("%c\n", maDGraph.vertexes[lastVer]);
    }
}
// end DijkstraMinDistance