//
// Created by マリオネット on 2021/1/12.
//

#include "LkStack.h"

bool InitStack(LinkStack *L) {
	LNode *head_node = (LNode *) malloc(sizeof(LNode));
	if (!head_node) return false;
	head_node->next = NULL;
	*L = head_node;
	return true;
}

bool GetTop(LinkStack L, ElemType *e) {
	LNode *first_node = L->next;
	if (!first_node) return false;       // 空栈
	*e = first_node->data;
	return true;
}

bool Push(LinkStack L, ElemType e) {
	LNode *new_node = (LNode *) malloc(sizeof(LNode));
	if (!new_node) return false;
	new_node->data = e;
	new_node->next = L->next;
	L->next = new_node;
	return true;
}

bool Pop(LinkStack L, ElemType *e) {
	LNode *first_node = L->next;
	if (!first_node) return false;
	*e = first_node->data;
	L->next = first_node->next;
	free(first_node);
	return true;
}

void StackTraverse(LinkStack L) {
	LNode *p = L;
	while (p->next) {
		p = p->next;
		printf("%d ", p->data);
	}
	printf("\n");
}

bool InitStack_Wo(LinkStack *L) {
	*L = NULL;      // 不带头结点时，头指针最开始指向NULL
	return true;
}

bool GetTop_Wo(LinkStack L, ElemType *e) {
	if (!L) return false;
	*e = L->data;
	return true;
}

bool Push_Wo(LinkStack *L, ElemType e) {
	LNode *new_node = (LNode *) malloc(sizeof(LNode));
	if (!new_node) return false;
	new_node->data = e;
	if (*L)      // 若栈不为空（头指针不指向NULL）
		new_node->next = *L;
	*L = new_node;
	return true;
}

bool Pop_Wo(LinkStack *L, ElemType *e) {
	if (!L) return false;
	LNode *first_node = *L;
	*e = first_node->data;
	*L = first_node->next;
	free(first_node);
	return true;
}

void StackTraverse_Wo(LinkStack L) {
	LNode *p = L;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void ClearStack(LinkStack L) {
	ElemType e;
	while (L->next)
		Pop(L, &e);
}

void OutPut(LinkStack L) {
	LNode *p = L;
	LinkStack cache_stack;
	InitStack(&cache_stack);
	while (p->next) {
		p = p->next;
		Push(cache_stack, p->data);
	}
	LNode *c = cache_stack;
	while (c->next) {
		c = c->next;
		printf("%c", c->data);
	}
	printf("\n");
}