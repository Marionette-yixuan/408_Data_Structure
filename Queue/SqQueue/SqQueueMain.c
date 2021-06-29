//
// Created by マリオネット on 2021/1/13.
//

#include "SqQueue.h"

int main() {
	SqQueue *Q;
	ElemType e;
	InitQueue(Q);
	EnQueue(Q, 24);
	EnQueue(Q, 36);
	EnQueue(Q, 48);
	TraverseQueue(*Q);
	DeQueue(Q, &e);
	printf("%d\n", e);
	TraverseQueue(*Q);
	EnQueue(Q, 64);
	TraverseQueue(*Q);
	return 0;
}