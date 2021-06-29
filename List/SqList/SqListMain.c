//
// Created by マリオネット on 2021/1/3.
//

#include "SqList.h"

int main() {
	SqList *L;
	ElemType e = 0;
	InitList_Sq(L);
	ListInsert_Sq(L, 1, 24);
	ListInsert_Sq(L, 1, 36);
	ListInsert_Sq(L, 1, 48);
	ListInsert_Sq(L, 2, 64);
	ListTraverse(L);
	ListDelete_Sq(L, 3, &e);
	ListTraverse(L);
	printf("%d\n", e);
	return 0;
}