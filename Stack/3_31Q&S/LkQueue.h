//
// Created by マリオネット on 2021/1/13.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef INC_408_DATA_STRUCTURE_LKQUEUE_H
#define INC_408_DATA_STRUCTURE_LKQUEUE_H

#endif //INC_408_DATA_STRUCTURE_LKQUEUE_H

#ifdef INC_408_DATA_STRUCTURE_LKQUEUE_H

#define ElemType char
typedef struct QueueNode {
  ElemType data;
  struct QueueNode *next;
} QNode;
typedef struct {
  QNode *front;
  QNode *rear;
} LinkQueue;

// 带头结点
bool InitQueue(LinkQueue *);

int QueueLength(LinkQueue);

bool EnQueue(LinkQueue *, ElemType);

bool DeQueue(LinkQueue *, ElemType *);

void TraverseQueue(LinkQueue);

// 不带头结点
bool InitQueue_Wo(LinkQueue *);

int QueueLength_Wo(LinkQueue);

bool EnQueue_Wo(LinkQueue *, ElemType);

bool DeQueue_Wo(LinkQueue *, ElemType *);

void TraverseQueue_Wo(LinkQueue);

#endif