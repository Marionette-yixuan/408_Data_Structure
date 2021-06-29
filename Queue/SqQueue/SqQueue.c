//
// Created by マリオネット on 2021/1/13.
//

#include "SqQueue.h"

bool InitQueue(SqQueue *Q) {
	Q->base = (ElemType *) malloc(sizeof(ElemType) * MAXQSIZE);
	if (!Q->base) return false;
	Q->front = 0;
	Q->rear = 0;
	return true;
}

int QueueLength(SqQueue Q) {
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

bool EnQueue(SqQueue *Q, ElemType e) {
	if ((Q->rear + 1) % MAXQSIZE == Q->front) return false;       // 队头是队尾的下一个位置，说明队列已满
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXQSIZE;
	return true;
}

bool DeQueue(SqQueue *Q, ElemType *e) {
	if (Q->rear == Q->front) return false;       // 队头=队尾，说明队列空
	*e = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAXQSIZE;
	return true;
}

void TraverseQueue(SqQueue Q) {
	for (int i = Q.front, count = 0; count < QueueLength(Q); i = (i + 1) % MAXQSIZE, count++)
		printf("%d ", Q.base[i]);
	printf("\n");
}