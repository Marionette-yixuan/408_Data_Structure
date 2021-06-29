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
} LNode, *LinkStack;

// 带头结点
bool InitStack(LinkStack *);

bool GetTop(LinkStack, ElemType *);

bool Push(LinkStack, ElemType);

bool Pop(LinkStack, ElemType *);

void StackTraverse(LinkStack);

// 不带头结点
bool InitStack_Wo(LinkStack *);

bool GetTop_Wo(LinkStack, ElemType *);

bool Push_Wo(LinkStack *, ElemType);

bool Pop_Wo(LinkStack *, ElemType *);

void StackTraverse_Wo(LinkStack);

void ClearStack(LinkStack);

void OutPut(LinkStack);

#endif
