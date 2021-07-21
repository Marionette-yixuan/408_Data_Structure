//
// Created by マリオネット on 2021/7/19.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef INC_408_DATA_STRUCTURE_TREETRAVERSION_H
#define INC_408_DATA_STRUCTURE_TREETRAVERSION_H

#define ElemType char
#define MAX_TREE_NUM 50
#define LEFT (-1)
#define MID (0)
#define RIGHT (1)

typedef struct TrTNode {                // 三叉树定义
  ElemType data;
  struct TrTNode *lChild, *mChild, *rChild;
} TrTNode, *TrTree;
typedef TrTree TrForest[MAX_TREE_NUM];  // 森林定义

void InitTree_T(TrTree *trTree, ElemType rootData);                             // 三叉树初始化
TrTNode *AddNode_T(TrTNode *parentNode, ElemType newData, int pos);             // 三叉树添加结点，并返回新添加的结点
void PreTraverse_T(TrTree trTree);                                              // 三叉树先序遍历
void PostTraverse_T(TrTree trTree);                                             // 三叉树后序遍历
void LayerTraverse_T(TrTree trTree);                                            // 三叉树层序遍历


typedef struct QueueNode {
  TrTNode data;
  struct QueueNode *next;
} QNode;
typedef struct {
  QNode *front;
  QNode *rear;
} LinkQueue;

bool InitQueue(LinkQueue *);
int QueueLength(LinkQueue Q);
bool EnQueue(LinkQueue *, TrTNode);
bool DeQueue(LinkQueue *, TrTNode *);

#endif //INC_408_DATA_STRUCTURE_TREETRAVERSION_H
