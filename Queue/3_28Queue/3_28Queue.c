//
// Created by マリオネット on 2021/1/15.
//

#include "3_28Queue.h"

bool InitQueue(CircularQueue *Q) {
	QNode *head_node = (QNode *) malloc(sizeof(QNode));
	if (!head_node) return false;
	head_node->next = head_node;    // 头结点的next指向本身（循环）
	*Q = head_node;         // 初始化，尾指针指向头结点
	return true;
}

bool EnQueue(CircularQueue *Q, ElemType e) {
	QNode *new_node = (QNode *) malloc(sizeof(QNode));
	if (!new_node) return false;
	new_node->next = (*Q)->next;        // *Q为指向尾结点的指针，理论上(*Q)->next必为头结点
	new_node->data = e;
	(*Q)->next = new_node;              // 原队尾元素的next指向新队尾元素
	*Q = new_node;                      // 尾结点指向新的队尾元素
	return true;
}

bool DeQueue(CircularQueue *Q, ElemType *e) {
	if ((*Q)->next == *Q) return false;   // 尾结点的next指向本身说明队列为空
	QNode *head_node = (*Q)->next;          // 找到头结点
	QNode *del_node = head_node->next;      // 要出队的结点
	head_node->next = del_node->next;
	if (del_node->next == head_node) *Q = head_node;     // 若要删除结点也是尾结点，则尾指针指向头结点
	*e = del_node->data;
	free(del_node);
	return true;
}