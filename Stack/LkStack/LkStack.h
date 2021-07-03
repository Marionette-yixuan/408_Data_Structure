//
// Created by マリオネット on 2021/1/12.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef INC_408_DATA_STRUCTURE_LKSTACK_H
#define INC_408_DATA_STRUCTURE_LKSTACK_H

#endif //INC_408_DATA_STRUCTURE_LKSTACK_H

#ifdef INC_408_DATA_STRUCTURE_LKSTACK_H

//#define ElemType int
#define ElemType char

typedef struct LNode {
  ElemType data;
  struct LNode *next;
} LNode, *LinkList;

// 带头结点
bool InitStack(LinkList *);

bool GetTop(LinkList, ElemType *);

bool Push(LinkList, ElemType);

bool Pop(LinkList, ElemType *);

void StackTraverse(LinkList);

// 不带头结点
bool InitStack_Wo(LinkList *);

bool GetTop_Wo(LinkList, ElemType *);

bool Push_Wo(LinkList *, ElemType);

bool Pop_Wo(LinkList *, ElemType *);

void StackTraverse_Wo(LinkList);

void ClearStack(LinkList);

void OutPut(LinkList);

#endif
