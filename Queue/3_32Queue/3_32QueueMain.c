//
// Created by マリオネット on 2021/1/15.
//

#include "3_32Queue.h"

int main() {
	CQueue Q;
	int max = 5000000;
	int count = 0;
	InitQueue(&Q);
	for (int i = 0; i < k; i++) {
		EnQueue(&Q, 0);
	}
	printf("%d ", EnQueue(&Q, 1));
	while (SumQueue(Q) <= max) {
		printf("%d ", EnQueue(&Q, SumQueue(Q)));
	}
	OutQueue(Q);
	return 0;
}