//
// Created by マリオネット on 2021/1/7.
//

#include "DuList.h"

int main() {
	DoubleList D;
	int e;
	InitList_Du(&D);
	ListInsert_Du(D, 1, 24);
	ListInsert_Du(D, 1, 36);
	ListInsert_Du(D, 1, 48);
	ListInsert_Du(D, 3, 64);
	ListTraverse(D);
	ListDelete_Du(D, 3, &e);
	ListTraverse(D);
	printf("%d\n", e);

	return 0;
}
