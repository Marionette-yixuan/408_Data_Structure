//
// Created by マリオネット on 2021/1/13.
//

#include "LkQueue.h"

void test3_21();

int main() {
	LinkQueue *Q;
	ElemType e;
	/*  // 带头结点
	InitQueue(Q);
	printf("%d\n", DeQueue(Q, &e));
	EnQueue(Q, 24);
	EnQueue(Q, 36);
	EnQueue(Q, 48);
	printf("%d\n", QueueLength(*Q));
	TraverseQueue(*Q);
	DeQueue(Q, &e);
	printf("%d\n", e);
	printf("%d\n", QueueLength(*Q));
	TraverseQueue(*Q);
	EnQueue(Q, 64);
	TraverseQueue(*Q);
	printf("%d", QueueLength(*Q));
	 */

	/*
	InitQueue_Wo(Q);
	printf("%d\n", DeQueue_Wo(Q, &e));
	EnQueue_Wo(Q, 24);
	EnQueue_Wo(Q, 36);
	EnQueue_Wo(Q, 48);
	printf("%d\n", QueueLength_Wo(*Q));
	TraverseQueue_Wo(*Q);
	DeQueue_Wo(Q, &e);
	printf("%d\n", e);
	printf("%d\n", QueueLength_Wo(*Q));
	TraverseQueue_Wo(*Q);
	EnQueue_Wo(Q, 64);
	TraverseQueue_Wo(*Q);
	printf("%d", QueueLength_Wo(*Q));
	*/
	// 3.21
	test3_21();

	return 0;
}

void test3_21() {
	LinkQueue variaQ, symbQ;
	InitQueue(&variaQ);
	InitQueue(&symbQ);
	char inc, popc;
	do {
		inc = (char) getchar();
		if (inc >= 'a' && inc <= 'z')
			EnQueue(&variaQ, inc);
		else if (inc == '+' || inc == '-' || inc == '*' || inc == '/')
			EnQueue(&symbQ, inc);
	} while (inc != '\n');
	DeQueue(&variaQ, &popc);
	printf("%c", popc);
	while (QueueLength(variaQ) && QueueLength(symbQ)) {
		DeQueue(&variaQ, &popc);
		printf("%c", popc);
		DeQueue(&symbQ, &popc);
		printf("%c", popc);
	}
}