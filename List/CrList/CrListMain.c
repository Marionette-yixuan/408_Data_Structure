//
// Created by マリオネット on 2021/1/7.
//

#include "CrList.h"

int main() {
	CircularList C;
	ElemType e = 0;
	InitList_Cr(&C);
	ListInsert_Cr(&C, 1, 24);
	ListInsert_Cr(&C, 1, 36);
	ListInsert_Cr(&C, 1, 48);
	ListInsert_Cr(&C, 2, 64);
	ListInsert_Cr(&C, 5, 81);
	ListTraverse(C);
	ListDelete_Cr(&C, 5, &e);
	ListTraverse(C);
	printf("%d\n", e);
	ListInsert_Cr(&C, 3, 81);
	ListTraverse(C);
	GetElem_C(C, 5, &e);
	printf("%d\n", e);

	return 0;
}

