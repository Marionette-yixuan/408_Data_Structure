//
// Created by マリオネット on 2021/1/7.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#ifndef INC_408_DATA_STRUCTURE_CRLIST_H
#define INC_408_DATA_STRUCTURE_CRLIST_H

#endif //INC_408_DATA_STRUCTURE_CRLIST_H

#ifdef INC_408_DATA_STRUCTURE_CRLIST_H

#define ElemType int

typedef struct CNode {
  ElemType data;
  struct CNode *next;
} CNode, *CircularList;

bool InitList_Cr(CircularList *);

bool GetElem_C(CircularList, int, ElemType *);

bool ListInsert_Cr(CircularList *, int, ElemType);

bool ListDelete_Cr(CircularList *, int, ElemType *);

void ListTraverse(CircularList);

#endif
