//
// Created by マリオネット on 2021/1/7.
//

#include "DuList.h"

bool InitList_Du(DoubleList *D) {
	DNode *head_node = (DNode *) malloc(sizeof(DNode));
	if (!head_node) return false;
	head_node->prior = NULL;
	head_node->next = NULL;
	*D = head_node;
	return true;
}

bool ListInsert_Du(DoubleList D, int i, ElemType e) {
	DNode *p = D;       // p指向头结点
	int j = 0;
	while (p && j < i - 1) {
		p = p->next;
		j++;
	}
	if (!p || j > i - 1) return false;
	DNode *s = (DNode *) malloc(sizeof(DNode));
	if (!s) return false;
	s->data = e;
	s->prior = p;
	s->next = p->next;
	if (p->next)         // 若p是最后一个结点，则不需要更新p的后继结点的prior域
		p->next->prior = s;
	p->next = s;
	return true;
}

bool ListDelete_Du(DoubleList D, int i, ElemType *e) {
	DNode *p = D;
	int j = 0;
	while (p && j < i - 1) {
		p = p->next;
		j++;
	}
	if (!p || j > i - 1) return false;
	DNode *q = p->next;
	if (q->next)
		q->next->prior = p;
	p->next = q->next;
	*e = q->data;
	free(q);
	return true;
}

void ListTraverse(DoubleList D) {
	DNode *p = D;
	while (p->next) {
		p = p->next;
		printf("%d ", p->data);
	}
	printf("\n");
}
