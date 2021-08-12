//
// Created by マリオネット on 2021/8/12.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#ifndef INC_408_DATA_STRUCTURE_MINDISTANCE_H
#define INC_408_DATA_STRUCTURE_MINDISTANCE_H

#endif //INC_408_DATA_STRUCTURE_MINDISTANCE_H

#ifdef INC_408_DATA_STRUCTURE_MINDISTANCE_H

/* 辅助队列 */
typedef struct QueueNode {
  int data;
  struct QueueNode *next;
} QNode;
typedef struct {
  QNode *front;
  QNode *rear;
} LinkQueue;

// 带头结点
bool InitQueue(LinkQueue *);
int QueueLength(LinkQueue);
bool EnQueue(LinkQueue *, int);
bool DeQueue(LinkQueue *, int *);

#define ElemType char
#define MaxGraphVertex 20
#define inf 2147483647

/* 邻接矩阵存储无向图 */
typedef struct {
  ElemType vertexes[MaxGraphVertex];
  bool edges[MaxGraphVertex][MaxGraphVertex];
  int vertexNum, edgeNum;
} MatGraph;
bool visited[MaxGraphVertex];           // 访问标记数组
LinkQueue supQueue;                     // 辅助队列

void InitGraph(MatGraph *matGraph, const ElemType vertexes[], bool edges[][8], int vertexNum);      // 胡写的一个初始化函数
int NextNeighbour(MatGraph matGraph, int verIndex);         // 从matGraph图中找到verIndex的下一个邻接顶点
void BFSMinDistance(MatGraph matGraph, int sourceIndex);

/* 邻接矩阵存储有向/无向带权图 */
typedef struct {
  ElemType vertexes[MaxGraphVertex];
  int edges[MaxGraphVertex][MaxGraphVertex];
  int vertexNum, edgeNum;
} MaDGraph;

void InitDGraph(MaDGraph *maDGraph, const ElemType vertexes[], int edges[][5], int vertexNum);      // 也是胡写的初始化函数
void DijkstraMinDistance(MaDGraph maDGraph, int sourceIndex);

#endif