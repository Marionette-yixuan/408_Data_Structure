//
// Created by マリオネット on 2021/1/15.
//

#include "3_32Queue.h"

void InitQueue(CQueue *Q) {
	Q->base = (ElemType *) malloc(sizeof(ElemType) * k);
	Q->rear = 0;
	return;
}

ElemType EnQueue(CQueue *Q, ElemType e) {
	ElemType oute = Q->base[Q->rear];
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % k;
	return oute;
}

ElemType SumQueue(CQueue Q) {
	ElemType sum = 0;
	for (int i = 0; i < k; i++) {
		sum += Q.base[i];
	}
	return sum;
}

void OutQueue(CQueue Q) {
	for (int i = 0; i < k; i++)
		printf("%d ", EnQueue(&Q, 0));
	return;
}