//
// Created by マリオネット on 2021/1/15.
//

#include "3_30Queue.h"

bool InitQueue(TQueue *Q) {
	Q->base = (ElemType *) malloc(sizeof(ElemType) * MAXQSIZE);
	if (!Q->base) return false;
	Q->rear = -1;       // rear指向队列已有的最后一个元素，队列空时rear应为-1
	Q->length = 0;
	return true;
}

bool QueueFull(TQueue Q) {
	return Q.length >= MAXQSIZE;
}

bool QueueEmpty(TQueue Q) {
	return !Q.length;
}

bool EnQueue(TQueue *Q, ElemType e) {
	if (QueueFull(*Q)) return false;
	Q->rear = (Q->rear + 1) % MAXQSIZE;     // 本题中rear指向队列最后一个元素，所以入队前rear要加1
	Q->base[Q->rear] = e;
	Q->length++;
	return true;
}

bool DeQueue(TQueue *Q, ElemType *e) {
	if (QueueEmpty(*Q)) return false;
	int front = ((Q->rear - Q->length + 1) + MAXQSIZE) % MAXQSIZE;
	*e = Q->base[front];
	Q->length--;
	return true;
}

void TraverseQueue(TQueue Q) {
	int front = ((Q.rear - Q.length + 1) + MAXQSIZE) % MAXQSIZE;
	for (int i = front, count = 0; count < Q.length; i = (i + 1) % MAXQSIZE, count++)
		printf("%d ", Q.base[i]);
	printf("\n");
}