//
// Created by マリオネット on 2021/1/8.
//

#include "SqStack.h"

bool InitStack_Sq(SqStack *S) {
	S->base = (ElemType *) malloc(sizeof(ElemType) * STACK_INIT_SIZE);
	if (!S->base) return false;
	S->top = S->base;
	S->stack_size = STACK_INIT_SIZE;
	return true;
}

bool GetTop_Sq(SqStack S, ElemType *e) {
	if (S.base == S.top) return false;   // 栈顶=栈底，说明栈为空，返回错误
	*e = *(S.top - 1);
	return true;
}

bool Push(SqStack *S, ElemType e) {
	if (S->top - S->base >= S->stack_size) {  // 栈满
		S->base = (ElemType *) realloc(S->base, sizeof(ElemType) * (S->stack_size + STACKINCREMENT));
		if (!S->base) return false;
		S->top = S->base + S->stack_size;   // 重新分配空间后base指针改变，需要更新top指针
		S->stack_size += STACKINCREMENT;
	}
	*S->top++ = e;
	return true;
}

bool Pop(SqStack *S, ElemType *e) {
	if (S->base == S->top) return false;
	*e = *--S->top;
	return true;
}

void StackTraverse(SqStack S) {
	ElemType *p = S.base;
	while (p < S.top) {
		printf("%d ", *p++);
	}
	printf("\n");
}