//
// Created by マリオネット on 2021/1/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef INC_408_DATA_STRUCTURE_3_30QUEUE_H
#define INC_408_DATA_STRUCTURE_3_30QUEUE_H

#endif //INC_408_DATA_STRUCTURE_3_30QUEUE_H

#ifdef INC_408_DATA_STRUCTURE_3_30QUEUE_H

#define ElemType int
#define MAXQSIZE 10

typedef struct {
  ElemType *base;
  int rear, length;
} TQueue;

bool InitQueue(TQueue *);

bool QueueFull(TQueue);

bool QueueEmpty(TQueue);

bool EnQueue(TQueue *, ElemType);

bool DeQueue(TQueue *, ElemType *);

void TraverseQueue(TQueue);

#endif