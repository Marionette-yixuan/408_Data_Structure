//
// Created by マリオネット on 2021/1/15.
//

#include "3_28Queue.h"

int main() {
	CircularQueue *Q;
	ElemType e;
	InitQueue(Q);
	DeQueue(Q, &e);
	printf("%d ", e);
	EnQueue(Q, 24);
	EnQueue(Q, 36);
	EnQueue(Q, 48);
	DeQueue(Q, &e);
	printf("%d ", e);
	DeQueue(Q, &e);
	printf("%d ", e);
	DeQueue(Q, &e);
	printf("%d ", e);
	DeQueue(Q, &e);
	printf("%d", e);
	return 0;
}