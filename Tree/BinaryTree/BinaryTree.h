//
// Created by マリオネット on 2021/4/12.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef INC_408_DATA_STRUCTURE_BINARYTREE_H
#define INC_408_DATA_STRUCTURE_BINARYTREE_H

#endif //INC_408_DATA_STRUCTURE_BINARYTREE_H

#ifdef INC_408_DATA_STRUCTURE_BINARYTREE_H

#define ElemType int

typedef struct BiTNode {
  ElemType data;
  struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

bool InitTree(BiTree *, ElemType);

/*
 * AddNode(BiTNode *T, int LorR, ElemType e) : bool
 * 新建一个数据为 e 的结点，并将其连接到 T 结点的 LorR 位置（0: 左结点，1: 右结点）
 */
bool AddNode(BiTNode *, int, ElemType);
bool PreOrderTraverse(BiTree, void Print(ElemType));
bool InOrderTraverse(BiTree, void Print(ElemType));
bool PostOrderTraverse(BiTree, void Print(ElemType));
void Print(ElemType);
bool LayerOrderTraverse(BiTree, void Print(ElemType));


typedef struct QueueNode {
  BiTNode data;
  struct QueueNode *next;
} QNode;
typedef struct {
  QNode *front;
  QNode *rear;
} LinkQueue;

bool InitQueue(LinkQueue *);
int QueueLength(LinkQueue);
bool EnQueue(LinkQueue *, BiTNode);
bool DeQueue(LinkQueue *, BiTNode *);
void TraverseQueue(LinkQueue);

#endif
