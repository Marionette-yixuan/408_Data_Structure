//
// Created by マリオネット on 2021/8/11.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef INC_408_DATA_STRUCTURE_MINSPANNINGTREE_H
#define INC_408_DATA_STRUCTURE_MINSPANNINGTREE_H

#endif //INC_408_DATA_STRUCTURE_MINSPANNINGTREE_H

#ifdef INC_408_DATA_STRUCTURE_MINSPANNINGTREE_H

#define ElemType char
#define MaxGraphVertex 10
#define inf 2147483647

/* 邻接矩阵存储无向图 */
typedef struct {
  ElemType vertexes[MaxGraphVertex];
  int edges[MaxGraphVertex][MaxGraphVertex];
  int vertexNum, edgeNum;
} MatGraph;

void InitGraph(MatGraph *matGraph, const ElemType vertexes[], int edges[][6], int vertexNum);      // 胡写的一个初始化函数
void Prim(MatGraph matGraph);

typedef struct EdgeNode {       // 用于为每条边排序的链表
  int weight;       // 权值
  int ends[2];      // 两边的顶点
  struct EdgeNode *next;        // 下一条边
} EdgeNode, *EdgeList;

void Kruskal(MatGraph matGraph);

#endif
