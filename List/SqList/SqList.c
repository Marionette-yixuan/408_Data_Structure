//
// Created by マリオネット on 2021/1/3.
//
#include "SqList.h"

bool InitList_Sq(SqList *L) {
	L->elem = (ElemType *) malloc(LIST_INIT_SIZE * sizeof(ElemType));     // 分配存储空间
	if (!L->elem) return false;          // 空间分配失败
	L->length = 0;                      // 初始化实际长度
	L->listsize = LIST_INIT_SIZE;       // 初始化表长
	return true;
}

bool ListInsert_Sq(SqList *L, int i, ElemType e) {
	if (i < 1 || i > L->length + 1) return false;     // i的值不合法
	if (L->length >= L->listsize) {                       // 当前存储空间已满，需要重新分配
		ElemType *newBase = (ElemType *) realloc(L->elem,
		                                         (L->listsize + LISTINCREMENT) * sizeof(ElemType));  // 重新分配存储空间
		if (!newBase) return false;     // 空间分配失败
		L->elem = newBase;              // 更新基址
		L->listsize += LISTINCREMENT;   // 增加表长
	}
	ElemType *q = &(L->elem[i - 1]);    // 获得插入位置的元素
	for (ElemType *p = &(L->elem[L->length - 1]); p >= q; p--)
		*(p + 1) = *p;                  // 从后往前依次进行元素后移
	*q = e;                             // 新元素入表
	L->length++;
	return true;
}

bool ListDelete_Sq(SqList *L, int i, ElemType *e) {
	if (i < 1 || i > L->length) return false;
	ElemType *p = &(L->elem[i - 1]);    // 获得要删除的元素
	*e = *p;                            // 获取要删除元素的值
	ElemType *q = &(L->elem[L->length - 1]);    // 获取表尾元素的位置
	for (p++; p <= q; p++)
		*(p - 1) = *p;                  // 从前往后依次进行元素前移
	L->length--;
	return true;
}

void ListTraverse(SqList *L) {
	for (ElemType *p = L->elem; p <= &(L->elem[L->length - 1]); p++)
		printf("%d ", (*p));
	printf("\n");
}
