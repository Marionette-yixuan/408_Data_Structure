//
// Created by マリオネット on 2021/1/8.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef INC_408_DATA_STRUCTURE_SQSTACK_H
#define INC_408_DATA_STRUCTURE_SQSTACK_H

#endif //INC_408_DATA_STRUCTURE_SQSTACK_H

#ifdef INC_408_DATA_STRUCTURE_SQSTACK_H

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define ElemType char

typedef struct {
  ElemType *base;       // 栈存储空间的基址，指向栈底的位置
  ElemType *top;        // 当前栈顶的地址
  int stack_size;       // 该顺序栈的最大容量
} SqStack;

bool InitStack_Sq(SqStack *);

bool GetTop_Sq(SqStack, ElemType *);

bool Push(SqStack *, ElemType);

bool Pop(SqStack *, ElemType *);

void StackTraverse(SqStack);

#endif
