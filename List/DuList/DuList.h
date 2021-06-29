//
// Created by マリオネット on 2021/1/7.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef INC_408_DATA_STRUCTURE_DULIST_H
#define INC_408_DATA_STRUCTURE_DULIST_H

#endif //INC_408_DATA_STRUCTURE_DULIST_H

#ifdef  INC_408_DATA_STRUCTURE_DULIST_H

#define ElemType int

typedef struct DNode {
  ElemType data;
  struct DNode *prior;
  struct DNode *next;
} DNode, *DoubleList;

bool InitList_Du(DoubleList *);

bool GetElem_D(DoubleList, int, ElemType *);

bool ListInsert_Du(DoubleList, int, ElemType);

bool ListDelete_Du(DoubleList, int, ElemType *);

void ListTraverse(DoubleList);

#endif
