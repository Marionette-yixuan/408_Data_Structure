//
// Created by マリオネット on 2021/8/11.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef INC_408_DATA_STRUCTURE_GRAPHTRAVERSE_H
#define INC_408_DATA_STRUCTURE_GRAPHTRAVERSE_H

#endif //INC_408_DATA_STRUCTURE_GRAPHTRAVERSE_H

#ifdef INC_408_DATA_STRUCTURE_GRAPHTRAVERSE_H

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
void BFSTraverse(MatGraph matGraph);                // 广度优先遍历matGraph
void BFS(MatGraph matGraph, int verIndex);          // 从verIndex开始广度优先遍历matGraph
void DFSTraverse(MatGraph matGraph);                // 深度优先遍历matGraph
void DFS(MatGraph matGraph, int verIndex);          // 从verIndex开始深度优先遍历matGraph

#endif
