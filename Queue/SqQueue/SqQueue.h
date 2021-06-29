//
// Created by マリオネット on 2021/1/13.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef INC_408_DATA_STRUCTURE_SQQUEUE_H
#define INC_408_DATA_STRUCTURE_SQQUEUE_H

#endif //INC_408_DATA_STRUCTURE_SQQUEUE_H

#ifdef INC_408_DATA_STRUCTURE_SQQUEUE_H

#define MAXQSIZE 100
#define ElemType int
typedef struct {
  ElemType *base;
  int front, rear;
} SqQueue;

bool InitQueue(SqQueue *);

int QueueLength(SqQueue);

bool EnQueue(SqQueue *, ElemType);

bool DeQueue(SqQueue *, ElemType *);

void TraverseQueue(SqQueue);

#endif
