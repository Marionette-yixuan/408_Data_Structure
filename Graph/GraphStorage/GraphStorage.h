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

#define ADHERE_MULTI_LIST

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

/* 注意有向图中箭头是从tail指向head的 */
void InitGraph(CLLGraph *cllGraph, const ElemType nodeValues[], int length);            // 根据顶点的数据集合构造顶点集合
void AddArc(CLLGraph *cllGraph, ElemType headValue, ElemType tailValue, int weight);    // 在指定顶点间添加一条弧
void DelArc(CLLGraph *cllGraph, ElemType headValue, ElemType tailValue);                // 删除指定结点之间的一条弧
int GetIndex(CLLGraph cllGraph, ElemType vertexValue);                                  // 根据顶点数据找到下标

#endif // CROSS_LINK_LIST

#ifdef ADHERE_MULTI_LIST

/* 邻接多重表存储无向图 */
typedef struct ArcNode {
  int endVertexes[2];                       // 边关联的两个顶点的编号，这里为了强调两个端点的平等性所以用了数组
  int weight;                               // 边的权值
  struct ArcNode *nextArcs[2];              // 两个端点的下一条边，下标对应顶点
} ArcNode;
typedef struct {
  ElemType data;                            // 顶点的数据
  ArcNode *firstArc;                        // 该顶点的第一条边
} VertexNode;
typedef struct {
  VertexNode vNodes[MaxGraphVertex];        // 顶点元素集合
  int vertexNum, arcNum;                    // 顶点数、边数
} AMLGraph;

void InitGraph(AMLGraph *amlGraph, const ElemType nodeValues[], int length);
void AddArc(AMLGraph *amlGraph, ElemType iValue, ElemType jValue, int weight);
void DelArc(AMLGraph *amlGraph, ElemType iValue, ElemType jValue);
int GetIndex(AMLGraph amlGraph, ElemType vertexValue);
/* 判断targetNode的两端是否为i端点和j端点，如果是，则返回0: targetNode.endVertexes[0] == i, 1: targetNode.endVertexes[1] = i */
/* 如果不是，返回-1 */
int IsArc(ArcNode targetNode, int iIndex, int jIndex);

#endif

#endif
