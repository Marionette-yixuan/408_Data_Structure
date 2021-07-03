//
// Created by マリオネット on 2021/1/6.
//

#include "LkList.h"

bool InitList_Lk(LinkList *L) {
	LNode *head_node = (LNode *) malloc(sizeof(LNode));
	head_node->next = NULL;
	*L = head_node;
	return true;
}

bool GetElem_L(LinkList L, int i, ElemType *e) {
	LNode *p = L->next;
	int j = 1;      // 此时p已经指向头结点的下一个结点（首元结点），即第1个结点
	while (p && j < i) {
		p = p->next;
		j++;
	}
	if (!p || j > i) return false;
	*e = p->data;
	return true;
}

bool ListInsert_Lk(LinkList L, int i, ElemType e) {
	LNode *p = L;
	int j = 0;      // 此时p指向头结点，故j初始为0
	while (p && j < i - 1) {
		p = p->next;
		j++;
	}
	if (!p || j > i - 1) return false;
	LNode *s = (LNode *) malloc(sizeof(LNode));
	if (!s) return false;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

bool ListDelete_Lk(LinkList L, int i, ElemType *e) {
	LNode *p = L;
	int j = 0;
	while (p && j < i - 1) {
		p = p->next;
		j++;
	}
	if (!p || j > i - 1) return false;
	LNode *q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return true;
}

void ListTraverse(LinkList L) {
	LNode *p = L;
	while (p->next) {
		p = p->next;
		printf("%d ", p->data);
	}
	printf("\n");
}
