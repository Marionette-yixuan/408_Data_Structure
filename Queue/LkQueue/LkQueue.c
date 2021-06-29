//
// Created by マリオネット on 2021/1/13.
//

#include "LkQueue.h"

bool InitQueue(LinkQueue *Q) {
	QNode *head_node = (QNode *) malloc(sizeof(QNode));
	if (!head_node) return false;
	head_node->next = NULL;
	Q->front = head_node;
	Q->rear = head_node;
	return true;
}

int QueueLength(LinkQueue Q) {
	int length = 0;
	QNode *node = Q.front;
	while (node->next) {
		node = node->next;
		length++;
	}
	return length;
}

bool EnQueue(LinkQueue *Q, ElemType e) {
	QNode *new_node = (QNode *) malloc(sizeof(QNode));
	if (!new_node) return false;
	new_node->data = e;
	new_node->next = Q->rear->next;
	Q->rear->next = new_node;
	Q->rear = new_node;
	return true;
}

bool DeQueue(LinkQueue *Q, ElemType *e) {
	if (Q->rear == Q->front) return false;
	QNode *de_node = Q->front->next;    // 头结点的下一个结点是首元结点
	*e = de_node->data;
	Q->front->next = de_node->next;
	if (!Q->front->next) Q->rear = Q->front;
	free(de_node);
	return true;
}

void TraverseQueue(LinkQueue Q) {
	QNode *node = Q.front;
	while (node->next) {
		node = node->next;
		printf("%d ", node->data);
	}
	printf("\n");
}

bool InitQueue_Wo(LinkQueue *Q) {
	Q->front = NULL;
	Q->rear = NULL;
	return true;
}

int QueueLength_Wo(LinkQueue Q) {
	QNode *node = Q.front;
	if (!node) return 0;
	int length = 1;     // Q.front不为NULL，说明队列有至少一个元素，且node指向第一个元素
	while (node->next) {
		node = node->next;
		length++;
	}
	return length;
}

bool EnQueue_Wo(LinkQueue *Q, ElemType e) {  // 入队操作与带头结点的队列完全一样
	QNode *new_node = (QNode *) malloc(sizeof(QNode));
	if (!new_node) return false;
	new_node->data = e;
	if (Q->rear) {   // 当队列为空时，不执行下方两句
		new_node->next = Q->rear->next;
		Q->rear->next = new_node;
	} else Q->front = new_node; // 首个元素入队后，头尾指针均指向该元素
	Q->rear = new_node;
	return true;
}

bool DeQueue_Wo(LinkQueue *Q, ElemType *e) {
	if (!Q->front) return false;
	QNode *de_node = Q->front;      // front直接指向首元结点
	*e = de_node->data;
	Q->front = de_node->next;
	free(de_node);
	return true;
}

void TraverseQueue_Wo(LinkQueue Q) {
	QNode *node = Q.front;
	while (node) {
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}