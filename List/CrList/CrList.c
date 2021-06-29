//
// Created by マリオネット on 2021/1/7.
//

#include "CrList.h"

bool InitList_Cr(CircularList *C) {  // 对于循环链表，C为尾指针（指向表尾结点）
	CNode *head_node = (CNode *) malloc(sizeof(CNode));
	head_node->next = head_node;
	*C = head_node;
	return true;
}

bool GetElem_C(CircularList C, int i, ElemType *e) {
	CNode *p = C->next->next;       // p指向首元结点
	int j = 1;
	while (p != C->next && j < i) {    // 判断p为表尾结点的方式：p = C
		p = p->next;
		j++;
	}
	if (p == C->next || j > i) return false;
	*e = p->data;
	return true;
}

bool ListInsert_Cr(CircularList *C, int i, ElemType e) {
	CNode *p = (*C)->next;             // p指向头结点
	int j = 0;
	while (p != (*C) && j < i - 1) {
		p = p->next;
		j++;
	}       // 找到要插入位置的前驱结点，用p表示
	if (j != i - 1) return false;
	CNode *s = (CNode *) malloc(sizeof(CNode));
	if (!s) return false;
	s->data = e;
	s->next = p->next;
	p->next = s;
	if (p == *C)     // 若p是尾结点
		*C = s;     // 更新尾指针
	return true;
}

bool ListDelete_Cr(CircularList *C, int i, ElemType *e) {
	CNode *p = (*C)->next;
	int j = 0;
	while (p != (*C) && j < i - 1) {
		p = p->next;
		j++;
	}
	if (j != i - 1) return false;
	CNode *q = p->next;
	p->next = q->next;
	*e = q->data;
	if (q == *C)
		*C = p;
	free(q);
	return true;
}

void ListTraverse(CircularList C) {
	CNode *p = C->next;
	while (p != C) {
		p = p->next;
		printf("%d ", p->data);
	}
	printf("\n");
}