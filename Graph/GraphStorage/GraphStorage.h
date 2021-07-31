//
// Created by マリオネット on 2021/7/31.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef INC_408_DATA_STRUCTURE_GRAPHSTORAGE_H
#define INC_408_DATA_STRUCTURE_GRAPHSTORAGE_H

#endif //INC_408_DATA_STRUCTURE_GRAPHSTORAGE_H

#ifdef INC_408_DATA_STRUCTURE_GRAPHSTORAGE_H

#define ElemType char
#define MaxGraphVertex 100

#define CROSS_LINK_LIST

#ifdef CROSS_LINK_LIST

/* 十字链表存储有向图 */
typedef struct ArcNode {
  int tailVertex, headVertex;               // 弧尾、弧头顶点的编号
  int weight;                               // 弧的权值
  struct ArcNode *tailNext, *headNext;      // 弧尾、弧头相同的下一条弧
} ArcNode;
typedef struct {
  ElemType data;                            // 顶点的数据
  ArcNode *firstIn, *firstOut;              // 该顶点作为弧尾、弧头的第一条弧
} VertexNode;
typedef struct {
  VertexNode vNodes[MaxGraphVertex];        // 顶点元素集合
  int vertexNum, arcNum;                    // 顶点数、弧数
} CLLGraph;

void InitGraph(CLLGraph *cllGraph, const ElemType nodeValues[], int length);            // 根据顶点的数据集合构造顶点集合
void AddArc(CLLGraph cllGraph, ElemType headValue, ElemType tailValue, int weight);     // 在指定顶点间添加一条弧
void DelArc(CLLGraph cllGraph, ElemType headValue, ElemType tailValue);                 // 删除指定结点之间的一条弧
int GetIndex(CLLGraph cllGraph, ElemType vertexValue);                                  // 根据顶点数据找到下标
VertexNode *GetVNode(CLLGraph cllGraph, ElemType vertexValue);                          // 根据顶点数据返回顶点结点

#endif // CROSS_LINK_LIST

#endif
