//
// Created by マリオネット on 2021/1/15.
//

#include "3_30Queue.h"

int main() {
	TQueue *Q;
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
