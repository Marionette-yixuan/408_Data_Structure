//
// Created by マリオネット on 2021/1/15.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#ifndef INC_408_DATA_STRUCTURE_3_28QUEUE_H
#define INC_408_DATA_STRUCTURE_3_28QUEUE_H

#endif //INC_408_DATA_STRUCTURE_3_28QUEUE_H

#ifdef INC_408_DATA_STRUCTURE_3_28QUEUE_H

#define ElemType int

typedef struct CQNode {
  ElemType data;
  struct CQNode *next;
} QNode, *CircularQueue;

bool InitQueue(CircularQueue *);

bool EnQueue(CircularQueue *, ElemType);

bool DeQueue(CircularQueue *, ElemType *);

#endif
