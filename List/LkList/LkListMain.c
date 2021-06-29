//
// Created by マリオネット on 2021/1/6.
//

#include "LkList.h"

int main() {
	LinkStack L;
	ElemType e = 0;
	InitList_Lk(&L);
	ListInsert_Lk(L, 1, 24);
	ListInsert_Lk(L, 1, 36);
	ListInsert_Lk(L, 1, 48);
	ListInsert_Lk(L, 4, 64);
	ListTraverse(L);
	ListDelete_Lk(L, 3, &e);
	ListTraverse(L);
	printf("%d\n", e);
	GetElem_L(L, 3, &e);
	printf("%d", e);
	return 0;
}