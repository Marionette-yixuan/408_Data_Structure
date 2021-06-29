//
// Created by マリオネット on 2021/1/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef INC_408_DATA_STRUCTURE_3_32QUEUE_H
#define INC_408_DATA_STRUCTURE_3_32QUEUE_H

#endif //INC_408_DATA_STRUCTURE_3_32QUEUE_H

#ifdef  INC_408_DATA_STRUCTURE_3_32QUEUE_H

#define k 10
#define ElemType int
typedef struct {
  ElemType *base;
  int rear;
} CQueue;

void InitQueue(CQueue *);

ElemType EnQueue(CQueue *, ElemType);

ElemType SumQueue(CQueue);

void OutQueue(CQueue);

#endif